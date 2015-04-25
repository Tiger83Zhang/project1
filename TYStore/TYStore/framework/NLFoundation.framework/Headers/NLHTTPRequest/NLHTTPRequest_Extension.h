//
//  NLHTTPRequest_Extension.h
//  NLHTTPRequest
//
//  Created by su on 14-5-8.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLHTTPRequest.h"

/*!
 @constants NL_HTTP_METHOD_GET           请求类型GET
 @constants NL_HTTP_METHOD_POST         请求类型POST
 @constants NL_HTTP_METHOD_PUT           请求类型PUT
 @constants NL_HTTP_METHOD_DEL           请求类型DELETE
 @constants NL_HTTP_METHOD_HEAD       请求类型HEAD
 */
extern NSString *const NL_HTTP_METHOD_GET;
extern NSString *const NL_HTTP_METHOD_POST;
extern NSString *const NL_HTTP_METHOD_PUT;
extern NSString *const NL_HTTP_METHOD_DEL;
extern NSString *const NL_HTTP_METHOD_HEAD;

typedef enum _NLHTTPPostFormat {
    NLHTTPURLEncodedPostFormat = 0,
    NLHTTPMultipartFormDataPostFormat = 1
} NLHTTPPostFormat;

@interface NLHTTPRequest ()
@property (retain) NSMutableArray *postData;
@property (retain) NSMutableArray *fileData;

@property (assign) NLHTTPPostFormat postFormat;
@property (assign, atomic) unsigned long long postLength;
@property (assign, nonatomic) BOOL haveBuiltPostBody;

- (void)failWithError:(NSError *)error;
@end

