//
//  PaymentValueDelegate.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/23.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol PaymentValueDelegate <NSObject>

-(void)passState:(NSString *)state;

- (void)handlBack:(NSString *)back;

@end
