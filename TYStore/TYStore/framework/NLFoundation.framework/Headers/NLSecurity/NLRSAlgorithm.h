//
//  NLRSAlgorithm.h
//  NLSecurity
//
//  Created by su on 14/8/16.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLAlgorithm.h"

@interface NLRSAlgorithm : NSObject<NLAlgorithmStrategy, NLEncryptAlgorithm>
@property (nonatomic, strong) NSData *inValue;
@property (nonatomic, strong) NSData *key;
@property (nonatomic) NSStringEncoding encoding;
+ (id)initWithPlainText:(NSString*)plainText publicKeyPem:(NSString*)keyPem;
+ (NSData*)getPublicKeyBerDataFromPemString:(NSString*)pemString;
@end
