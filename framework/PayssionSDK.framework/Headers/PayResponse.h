//
//  PayResponse.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/23.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import "PayssionResponse.h"

@interface PayResponse : NSObject

@property (copy, nonatomic) NSString *mState;
@property (copy, nonatomic) NSString *mAppName;
@property (copy, nonatomic) NSString *mTransactionId;
@property (copy, nonatomic) NSString *mAmount;
@property (copy, nonatomic) NSString *mOrderId;
@property (copy, nonatomic) NSString *mOrderExtra;
@property (copy, nonatomic) NSString *mPMId;
@property (copy, nonatomic) NSString *mPMName;
@property (copy, nonatomic) NSString *mPayerEmail;
@property (copy, nonatomic) NSString *mCurrency;
@property (copy, nonatomic) NSString *mAmountLocal;
@property (copy, nonatomic) NSString *mCurrencyLocal;
@property (copy, nonatomic) NSString *mRedirectUrl;
@property (copy, nonatomic) NSString *mTodo;

@end

