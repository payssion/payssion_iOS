//
//  PaymentHttpClient.h
//  Payssion-Example
//
//  Created by UlquiorraCifer on 16/11/22.
//  Copyright © 2016年 Payssion. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void (^PaymentHttpRequestCompletionHandler)(id response, NSHTTPURLResponse *urlResponse, NSError *error);

@class PaymentHttpRequest;

@interface PaymentHttpClient : NSObject

+ (instancetype)sharedClient;
+ (instancetype)sharedClientWithIdentifier:(NSString*)identifier;

- (void)setBasicAuthWithUsername:(NSString*)username password:(NSString*)password;
- (void)setValue:(NSString *)value forHTTPHeaderField:(NSString *)field;

- (PaymentHttpRequest*)GET:(NSString*)path parameters:(NSDictionary*)parameters completion:(PaymentHttpRequestCompletionHandler)completionBloc;

- (PaymentHttpRequest*)GET:(NSString*)path parameters:(NSDictionary*)parameters saveToPath:(NSString*)savePath progress:(void (^)(float progress))progressBlock completion:(PaymentHttpRequestCompletionHandler)completionBlock;

- (PaymentHttpRequest*)POST:(NSString*)path parameters:(NSObject*)parameters completion:(PaymentHttpRequestCompletionHandler)completionBlock;

- (PaymentHttpRequest*)POST:(NSString*)path parameters:(NSObject*)parameters progress:(void (^)(float progress))progressBlock completion:(void (^)(id response, NSHTTPURLResponse *urlResponse, NSError *error))completionBlock;
- (PaymentHttpRequest*)PUT:(NSString*)path parameters:(NSObject*)parameters completion:(PaymentHttpRequestCompletionHandler)completionBlock;

- (PaymentHttpRequest*)DELETE:(NSString*)path parameters:(NSDictionary*)parameters completion:(PaymentHttpRequestCompletionHandler)completionBlock;
- (PaymentHttpRequest*)HEAD:(NSString*)path parameters:(NSDictionary*)parameters completion:(PaymentHttpRequestCompletionHandler)completionBlock;

- (void)cancelRequestsWithPath:(NSString*)path;
- (void)cancelAllRequests;
- (PaymentHttpRequest*)queueRequest:(PaymentHttpRequest*)requestOperation;

@property (nonatomic, strong) NSDictionary *baseParameters;

@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, strong) NSString *basePath;
@property (nonatomic, strong) NSString *userAgent;

@property (nonatomic, readwrite) BOOL sendParametersAsJSON;
@property (nonatomic, readwrite) NSURLRequestCachePolicy cachePolicy;
@property (nonatomic, readwrite) NSUInteger timeoutInterval;

@end
