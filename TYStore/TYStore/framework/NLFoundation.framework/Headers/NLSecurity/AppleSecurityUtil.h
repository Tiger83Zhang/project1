//
//  AppleSecurityUtil.h
//  jsums
//
//  Created by su on 14-5-2.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <CommonCrypto/CommonDigest.h>
#import <CommonCrypto/CommonCryptor.h>

@interface AppleSecurityUtil : NSObject
+ (NSString *)md5Calculate:(NSString*)input;
+ (NSString *)sha1Calculate:(NSString*)input;
+ (NSData*)desCalculate:(NSData*)data key:(NSData*)key operation:(CCOperation)op;
+ (NSData*)tripleDesCalculate:(NSData*)data key:(NSData*)key operation:(CCOperation)op;
@end
