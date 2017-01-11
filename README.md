# payssion_iOS
## 导入代码
##### 1.将framework文件夹下的`PayssionSDK.framework.zip`压缩文件中以下文件拷贝到项目文件夹下，并导入到项目工程中。
```xml
 PayssionSDK.framework
```
在Build Phases选项卡的Link Binary With Libraries中，增加以下依赖：

![alt text](/img/librarie.png "img")

##### 2. 在需要调用PayssionSDK的文件中，增加头文件引用。并遵守PaymentDelegate协议
```xml
1.#import <PayssionSDK/PayssionSDK.h>

2.@interface ViewController () <PaymentDelegate>
3.@end
```

##### 3. 组装请求信息。
```xml
    PayRequest *payRequest = [[PayRequest alloc] init];
    payRequest.live_mode = false;
    payRequest.api_key = @"916937a82dd7af5a";
    payRequest.secret_key = @"demo456";
    payRequest.pm_id = @"boleto_br";
    payRequest.amount = @"100";
    payRequest.currency = @"USD";
    payRequest.order_id = @"order id 123";
    payRequest.description = @"game recharge #123";
```
## 请求参数说明

| 参数名         | 类型         | 必填          | 示例          | 释义          | 详解         |
| :------------ |:----------  |:--- |:--------------- |:---------------- |:--------------------- |
| live_mode     | BOOL           | 否           | true/false    | 程序运行环境 |测试环境传false.正式环境传true.默认正式环境
| api_key       | NSString       | 是           | 916937a82dd7af5a  | App id    | 注意区分对应环境的api_key
| secret_key    | NSString       | 是           | demo456           | 密钥       | 注意区分对应环境的secret_key
| order_id      | NSString       | 是           | 1989093-251658248 | 订单id     | 需自定义，且长度不超过32位
| amount        | NSString       | 是           | 1.99              | 订单总金额  | 
| currency      | NSString       | 是           | USD、CNY等         | 货币种类    | 大写，币种缩写可搜索公共信息
| pm_id         | NSString       | 是           | sofort             | 支付方式id | [供参考](https://payssion.com/en/docs/#api-reference-pm-id)。具体询问我司商务经理 
| description   | NSString       | 是           | game recharge #123 | 订单描述 | 
| payer_email   | NSString       | 是           | example@demo.com   | 付款方邮箱 | 南美地区支付必须填写邮箱。具体询问我们的商务经理
| payer_name    | NSString       | 否           | example name       | 付款方姓名 | 
| payer_ref     | NSString       | 否           | example ref        | 付款方其他信息 | 

## 代码示例
###创建交易
通过以下代码创建交易
```java
    PaymentMainController *paymentMainController = [[PaymentMainController alloc] init];
    paymentMainController.payRequest = payRequest;
    paymentMainController.paymentDelegate = self;
    paymentMainController.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:paymentMainController animated:YES];
```
###处理返回数据
需要重写`processOrderWithPayResponse`函数
```java
    - (void)processOrderWithPayResponse:(PayResponse *)payResponse{
    if (payResponse != nil) {
        NSLog(@"%@",payResponse.mOrderId);
    }
}
```

## 返回数据说明

###1.参数说明

返回数据封装为PayResponse类。PayResponse不为空就意味着客户端支付流程结束，准确支付结果以notify_url通知为准。
| 参数名         | 类型          | 释义              | 详解                   |
| :-------------- |:------------ |:----------- |:---------------------------- |
| mTransactionId  | NSString      | 交易id|Payssion 交易号 id,如订单异常,需提供此 id
| mOrderId        | NSString      | 订单id| 客户发起支付时自定义的订单 id。注意与`mTransactionId`区分
| mState          | NSString      | 订单状态| 状态值见下表，当前获取的状态有延迟，准确支付结果以notify_url通知为准
| mAmount         | NSString      | 订单金额|

###2.支付状态说明

| 支付状态 	        | 说明       |
| :----------------- | :--------------------- |
| error	              |支付发生错误
| pending	            |未完成支付
| completed	          |支付成功
| paid_partial	       |部分支付，用户只支付了部分金额
| failed	             |支付失败
| cancelled	          |交易被取消
| cancelled_by_user	  |用户取消支付
| rejected_by_bank	   |银行拒绝
| expired	            |交易失效
| refunded	           |退款成功
| refund_pending	     |已申请退款，正在处理退款
| refund_failed	      |退款失败
| chargeback	         |拒付

###3.注意事项
1. 需要注意的是这里的支付成功意味着支付流程成功。因为银行间结算有延迟，所以最终的支付结果要以您后台配置的[`otify_url`](https://payssion.com/en/docs/#api-reference-payment-notifications)[(中文请点击)](https://payssion.com/cn/docs/#api-notifications)收到的通知为准。

2. 在接收`notify_url`数据时需验证签名`notify_sig`。详情请[查阅文档](https://payssion.com/en/docs/#api-reference-signature)[(中文请点击)](https://payssion.com/cn/docs/#api-api-signature)以及[Demo](https://github.com/payssion/payssion-php/blob/master/samples/sample_postback.php)。

## 常见疑问
**1.** 提示`pp Transport Security has blocked a cleartext HTTP (http://) resource load since it is insecure.`

上述问题需要`修改 App Transport Security 策略`

iOS 9 中新增了 App Transport Security 特性, 主要影响是使得原来请求网络数据时用到的 HTTP 协议都必须换成 HTTPS 协议。

但是实际情况中，我们的数据服务可能还并未升级到 HTTPS，所以这时候我们需要对项目进行一些设置来允许 HTTP 数据请求，也就是修改 App Transport Security 策略。步骤是：

在项目的 `Info.plist` 文件中添加如下字段：

![alt text](/img/security.png "img")

对应的字段如下：

```xml
<key>NSAppTransportSecurity</key>
<dict>
    <key>NSAllowsArbitraryLoads</key>
    <true/>
</dict>
```
