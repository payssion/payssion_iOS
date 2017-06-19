//
//  PayssionRequest.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/22.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface PayssionRequest : NSObject

@property (copy, nonatomic) NSString *api_key;
@property (copy, nonatomic) NSString *secret_key;
@property (nonatomic) BOOL live_mode;
@property (copy, nonatomic) NSString *method;
@property (copy, nonatomic) NSString *user_agent;
@property (copy, nonatomic) NSString *source;

@end
