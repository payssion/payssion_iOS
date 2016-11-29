//
//  PaymentMainController.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/23.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import "PayRequest.h"
#import "PayResponse.h"
#import "PaymentValueDelegate.h"
#import "PaymentDelegate.h"

@interface PaymentMainController : UIViewController<PaymentDelegate>

@property (strong,nonatomic) PayRequest *payRequest;

@property (strong,nonatomic) PayResponse *payResponse;

@property(nonatomic,assign) NSObject<PaymentValueDelegate> *delegate;

@property(nonatomic,assign) NSObject<PaymentDelegate> *paymentDelegate;

@end
