//
//  NLHTTPRequest.h
//  jsums
//
//  Created by su on 14-4-30.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol NLHTTPAuthenticationStrategy;

@interface NLHTTPRequest : NSObject
// Should be an HTTP or HTTPS url, may include username and password if appropriate
- (id)initWithURL:(NSURL *)newURL;

// Convenience constructor
+ (id)requestWithURL:(NSURL *)newURL;
+ (id)requestWithURLString:(NSString *)url;
#pragma mark setup request

// Add a custom header to the request
- (void)addRequestHeader:(NSString *)header value:(NSString *)value;
// Called to add data to the post body. Will append to postBody when shouldStreamPostDataFromDisk is false, or write to postBodyWriteStream when true
- (void)appendPostData:(NSData *)data;
#pragma mark running a request


// Run a request synchronously, and return control when the request completes or fails
- (void)startSynchronous;

// Run request in the background
- (void)startAsynchronous;

// Clears all delegates and blocks, then cancels the request
- (void)clearDelegatesAndCancel;
#pragma mark get information about this request

// Returns the contents of the result as an NSString (not appropriate for binary data - used responseData instead)
- (NSString *)responseString;

// Response data, automatically uncompressed where appropriate
- (NSData *)responseData;


@property (retain,setter=setURL:, nonatomic) NSURL *url;
@property (assign, nonatomic) id delegate;
@property (retain) NSError *error;
@property (assign,readonly) BOOL complete;
@property (retain) NSDictionary *responseHeaders;
@property (retain) NSMutableDictionary *requestHeaders;
@property (assign,readonly) int responseStatusCode;
@property (retain,readonly) NSString *responseStatusMessage;
@property (retain, nonatomic) NSString *requestMethod;
@property (retain) NSMutableData *postBody;
//@property (assign) unsigned long long contentLength;
//@property (assign) unsigned long long postLength;
//@property (assign) NSStringEncoding defaultResponseEncoding;
@property (assign) NSStringEncoding stringEncoding;
@property (assign) NSStringEncoding responseEncoding;
@property (assign) BOOL validatesSecureCertificate;
@property (assign) NSTimeInterval timeOutSeconds;
@property (retain) NSObject<NLHTTPAuthenticationStrategy> *authStrategy;
@end


@protocol NLHTTPRequestDelegate <NSObject>

@optional

// These are the default delegate methods for request status
// You can use different ones by setting didStartSelector / didFinishSelector / didFailSelector
- (void)requestStarted:(NLHTTPRequest *)request;
- (void)request:(NLHTTPRequest *)request didReceiveResponseHeaders:(NSDictionary *)responseHeaders;
- (void)requestFinished:(NLHTTPRequest *)request;
- (void)requestFailed:(NLHTTPRequest *)request;
// When a delegate implements this method, it is expected to process all incoming data itself
// This means that responseData / responseString / downloadDestinationPath etc are ignored
// You can have the request call a different method by setting didReceiveDataSelector
- (void)request:(NLHTTPRequest *)request didReceiveData:(NSData *)data;

@end

@protocol NLHTTPAuthenticationStrategy <NSObject>
@required
- (BOOL)connection:(NSURLConnection *)connection canAuthenticateAgainstProtectionSpace:(NSURLProtectionSpace *)protectionSpace;
- (void)connection:(NSURLConnection *)connection didReceiveAuthenticationChallenge:(NSURLAuthenticationChallenge *)challenge;
@end

@interface NLHTTPDefaultAuthenticationStrategy : NSObject<NLHTTPAuthenticationStrategy>
@end
