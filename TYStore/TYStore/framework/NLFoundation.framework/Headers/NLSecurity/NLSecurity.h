//
//  NLSecurity.h
//  NLSecurity
//
//  Created by su on 14-1-14.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "NLAlgorithm.h"

@interface NLSecurity : NSObject
/*!
 @method
 @abstract 调用指定算法进行加密
 @discussion
 @param algorithm 加密算法构造对象
 @return 加密后的结果（密文）
 */
+ (NSString*)encryptWithAlgorithm:(id<NLEncryptAlgorithm>)algorithm;
/*!
 @method
 @abstract 调用指定算法进行解密
 @discussion
 @param algorithm 解密算法构造对象
 @return 解密后的结果（明文）
 */
+ (NSString*)decryptWithAlgorithm:(id<NLDecryptAlgorithm>)algorithm;
/*!
 @method
 @abstract SHA1WithRSA签名
 @discussion
 @param plainText 被签名的数据
 @param p12Path 存储私钥的p12格式文件路径
 @return 签名数据
 */
+ (NSString*)sha1WithRSASign:(NSString*)plainText p12Path:(NSString*)p12Path;
/*!
 @method
 @abstract SHA1WithRSA验签
 @discussion
 @param plainText 被签名的数据
 @param signData 签名数据
 @param cerPath 存储公钥信息的cer格式文件路径
 @return 验签是否通过
 */
+ (BOOL)sha1WithRSAVerify:(NSString*)plainText signData:(NSString*)signData cerPath:(NSString*)cerPath;

//// helper methods
+ (NSString*)getPemEntityFromPemFileConent:(NSString*)content;
@end
