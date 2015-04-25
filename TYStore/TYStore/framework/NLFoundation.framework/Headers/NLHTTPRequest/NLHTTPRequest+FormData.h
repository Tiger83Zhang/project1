//
//  NLHTTPRequest+FormData.h
//  jsums
//
//  Created by su on 14-5-6.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLHTTPRequest.h"

@interface NLHTTPRequest (FormData)
// Add a POST variable to the request
- (void)addPostValue:(id <NSObject>)value forKey:(NSString *)key;

// Set a POST variable for this request, clearing any others with the same key
- (void)setPostValue:(id <NSObject>)value forKey:(NSString *)key;

- (void)addData:(NSData *)data andContentType:(NSString *)contentType forKey:(NSString *)key;

// Add the contents of an NSData object to the request
- (void)addData:(NSData *)data forKey:(NSString *)key;
@end
