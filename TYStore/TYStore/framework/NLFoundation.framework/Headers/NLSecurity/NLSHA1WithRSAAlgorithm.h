//
//  NLSHA1WithRSAAlgorithm.h
//  RSAVerifyTest
//
//  Created by su on 15/3/14.
//  Copyright (c) 2015年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAlgorithm.h"

@interface NLSHA1WithRSAAlgorithm : NSObject<NLAlgorithmStrategy, NLEncryptAlgorithm>
- (id)initWithP12Path:(NSString*)p12Path;
- (NSString*)signWithPlainText:(NSString*)plainText;

- (id)initWithCerPath:(NSString*)cerPath;
- (BOOL)verifyWithPlainText:(NSString*)plainText signData:(NSString*)signData;
@end
