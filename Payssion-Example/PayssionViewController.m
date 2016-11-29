//
//  ViewController.m
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/29.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import "PayssionViewController.h"
#import <PayssionSDK/PayssionSDK.h>

@interface PayssionViewController () <PaymentDelegate>

@end

@implementation PayssionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Setup.
    [self setupUI];
}

#pragma mark - Setup
- (void)setupUI {
    // Use full screen layout.
    self.edgesForExtendedLayout = UIRectEdgeAll;
    self.automaticallyAdjustsScrollViewInsets = YES;
    self.extendedLayoutIncludesOpaqueBars = YES;
    
    self.navigationItem.title= @"Payssion-Example";
    
    // Pay button.
    UIButton *payButton = [UIButton buttonWithType:UIButtonTypeSystem];
    payButton.frame = CGRectMake(10, 100, self.view.frame.size.width-20, 40);
    [payButton setTitle:@"Pay" forState:UIControlStateNormal];
    [payButton setTitle:@"Pay" forState:UIControlStateSelected];
    [payButton setBackgroundColor:[UIColor orangeColor]];
    [payButton addTarget:self action:@selector(onClickPay) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:payButton];
    
}

- (void)onClickPay{
    
    PayRequest *payRequest = [[PayRequest alloc] init];
    payRequest.live_mode = false;
    payRequest.api_key = @"916937a82dd7af5a";
    payRequest.secret_key = @"demo456";
    payRequest.pm_id = @"sofort";
    payRequest.amount = @"100";
    payRequest.currency = @"USD";
    payRequest.order_id = @"order id 123";
    payRequest.descriptions = @"IOS order by payssion, orderId:123";
    
    PaymentMainController *paymentMainController = [[PaymentMainController alloc] init];
    paymentMainController.payRequest = payRequest;
    paymentMainController.paymentDelegate = self;
    paymentMainController.hidesBottomBarWhenPushed = YES;
    [self.navigationController pushViewController:paymentMainController animated:YES];
    
}

// NOTE
- (void)processOrderWithPayResponse:(PayResponse *)payResponse{
    if (payResponse != nil) {
        NSLog(@"%@",payResponse.mOrderId);
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
