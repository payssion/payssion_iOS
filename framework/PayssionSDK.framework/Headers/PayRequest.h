//
//  PayRequest.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/22.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import "PayssionRequest.h"

@interface PayRequest : PayssionRequest

@property (copy, nonatomic) NSString *pm_id;
@property (copy, nonatomic) NSString *pm_name;
@property (copy, nonatomic) NSString *amount;
@property (copy, nonatomic) NSString *currency;
@property (copy, nonatomic) NSString *language;
@property (copy, nonatomic) NSString *order_id;
@property (copy, nonatomic) NSString *order_extra;
@property (copy, nonatomic) NSString *payer_name;
@property (copy, nonatomic) NSString *payer_email;
@property (copy, nonatomic) NSString *payer_ref;
@property (copy, nonatomic) NSString *descriptions;
@property (copy, nonatomic) NSMutableDictionary *extra_items;

@end
