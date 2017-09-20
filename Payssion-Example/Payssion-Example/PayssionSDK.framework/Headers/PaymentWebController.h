//
//  PaymentWebController.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/22.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WebKit/WebKit.h>
#import "PaymentValueDelegate.h"

@interface PaymentWebController : UIViewController

@property (nonatomic,copy) NSString *reUrl;

@property(nonatomic,assign) NSObject<PaymentValueDelegate> *delegate;

@property(nonatomic,assign) NSObject<PaymentValueDelegate> *backDelegate;

@end

