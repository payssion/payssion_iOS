//
//  PaymentHttpRequest.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/22.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AvailabilityMacros.h>

#import "PaymentHttpClient.h"

enum {
    SVHTTPRequestMethodGET = 0,
    SVHTTPRequestMethodPOST,
    SVHTTPRequestMethodPUT,
    SVHTTPRequestMethodDELETE,
    SVHTTPRequestMethodHEAD
};
typedef NSUInteger PaymentRequestMethod;

@interface PaymentHttpRequest : NSOperation

+ (PaymentHttpRequest*)GET:(NSString*)address parameters:(NSDictionary*)parameters completion:(PaymentHttpRequestCompletionHandler)block;
+ (PaymentHttpRequest*)GET:(NSString*)address parameters:(NSDictionary*)parameters saveToPath:(NSString*)savePath progress:(void (^)(float progress))progressBlock completion:(PaymentHttpRequestCompletionHandler)completionBlock;

+ (PaymentHttpRequest*)POST:(NSString*)address parameters:(NSObject*)parameters completion:(PaymentHttpRequestCompletionHandler)block;
+ (PaymentHttpRequest*)POST:(NSString *)address parameters:(NSObject *)parameters progress:(void (^)(float))progressBlock completion:(PaymentHttpRequestCompletionHandler)completionBlock;
+ (PaymentHttpRequest*)PUT:(NSString*)address parameters:(NSObject*)parameters completion:(PaymentHttpRequestCompletionHandler)block;

+ (PaymentHttpRequest*)DELETE:(NSString*)address parameters:(NSDictionary*)parameters completion:(PaymentHttpRequestCompletionHandler)block;
+ (PaymentHttpRequest*)HEAD:(NSString*)address parameters:(NSDictionary*)parameters completion:(PaymentHttpRequestCompletionHandler)block;

- (PaymentHttpRequest*)initWithAddress:(NSString*)urlString
                                method:(PaymentRequestMethod)method
                            parameters:(NSObject*)parameters
                            completion:(PaymentHttpRequestCompletionHandler)completionBlock;

- (void)preprocessParameters;
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

+ (void)setDefaultTimeoutInterval:(NSTimeInterval)interval;
+ (void)setDefaultUserAgent:(NSString*)userAgent;

@property (nonatomic, strong) NSString *userAgent;
@property (nonatomic, readwrite) BOOL sendParametersAsJSON;
@property (nonatomic, readwrite) NSURLRequestCachePolicy cachePolicy;
@property (nonatomic, readwrite) NSUInteger timeoutInterval;
@property (nonatomic, strong) NSMutableURLRequest *operationRequest;

@end


// the following methods are only to be accessed from SVHTTPRequest.m and SVHTTPClient.m

@protocol PaymentRequestPrivateMethods <NSObject>

@property (nonatomic, strong) NSString *requestPath;
@property (nonatomic, strong) PaymentHttpClient *client;

- (PaymentHttpRequest*)initWithAddress:(NSString*)urlString
                                method:(PaymentRequestMethod)method
                            parameters:(NSObject*)parameters
                            saveToPath:(NSString*)savePath
                              progress:(void (^)(float))progressBlock
                            completion:(PaymentHttpRequestCompletionHandler)completionBlock;

- (void)signRequestWithUsername:(NSString*)username password:(NSString*)password;

@end