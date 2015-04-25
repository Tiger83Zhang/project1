//
//  NLDesAlgorithm.h
//  jsums
//
//  Created by su on 14-4-30.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLAlgorithm.h"

@protocol NLDesAlgorithm <NLEncryptAlgorithm, NLDecryptAlgorithm>
@end

/*!
 @class
 @abstract DES
 @discussion
 */

@interface NLDesAlgorithm : NSObject<NLAlgorithmStrategy, NLDesAlgorithm>
@property (nonatomic, strong) NSData *inValue;
@property (nonatomic, strong) NSData *key;
@property (nonatomic) NSStringEncoding encoding;

+ (id)initWithText:(NSString*)text key:(NSString*)key;
- (id)initWithData:(NSData*)data key:(NSData*)key;
- (id)initWithText:(NSString*)text key:(NSString*)key encoding:(NSStringEncoding)encoding;
+ (NSString*)hexStringWithData:(NSData*)data;
+ (NSData*)hexStr2bcd:(NSString*)hexStr;
@end