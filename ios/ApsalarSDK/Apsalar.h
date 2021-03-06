//
//  Apsalar.h
//  Apsalar SDK for iOS public API
//
//  Copyright © 2010-2016 Apsalar Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


@interface Apsalar : NSObject
+ (void)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret ;
+ (void)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchOptions:(NSDictionary *)launchOptions;
+ (void)startSession:(NSString *)apiKey withKey:(NSString *)apiSecret andLaunchURL:(NSURL *)url;
+ (void)reStartSession:(NSString *)apiKey withKey:(NSString *)apiSecret;
+ (BOOL)sessionStarted;
+ (void)endSession;
+ (void)event:(NSString *)name;
+ (void)event:(NSString *)name withArgs:(NSDictionary *)args;
+ (void)eventWithArgs:(NSString *)name, ...; // use only subclasses of
                                              // NSObject, not primitive types
                                              // like int

+ (void)registerDeviceTokenForUninstall:(NSData *)deviceToken;
+ (void)registerDeferredDeepLinkHandler:(void (^)(NSString *deeplink))handler;
+ (int)setDeferredDeepLinkTimeout:(int)duration;

+ (Apsalar *) shared;
+ (NSTimeInterval) sessionDuration;
+ (NSDate *) sessionStartDate;
+ (NSString *) sessionID;
+ (NSString *) version;
+ (NSString *) apsalarID;
+ (NSString *)apsalarKeyspace;
+ (void) setBufferLimit:(int)size;
@property(strong, nonatomic, readonly) NSString *applicationName;
@property(strong, nonatomic, readonly) NSString *applicationIdentifier;
+ (BOOL) processJSRequest:(UIWebView *)webView withURL:(NSURLRequest *)url;
@property(nonatomic) int minSessionDuration;  // Default: 5
+ (void) setMinSessionDuration:(int)seconds;

// IAP
+ (void)setAllowAutoIAPComplete:(BOOL)boolean;
+ (void)iapComplete:(id)transaction;
+ (void)iapComplete:(id)transaction withAttributes:(id)value, ...;

// DEMO
+ (void)setGender:(NSString *)gender;
+ (void)setAge:(id)age;

// BATCHING
+ (int)batchInterval;
+ (void)setBatchInterval:(int)interval;
+ (BOOL)batchesEvents;
+ (void)setBatchesEvents:(BOOL)boolean;
+ (void)sendAllBatches;

@end
