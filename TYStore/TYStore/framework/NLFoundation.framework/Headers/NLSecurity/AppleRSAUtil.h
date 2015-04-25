//
//  AppleRSAUtil.h
//  NLSecurity
//
//  Created by su on 14/8/16.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppleRSAUtil : NSObject
+ (BOOL)exportKeyRefWithP12Data:(NSData*)p12Data pkcsPwd:(NSString*)pkcsPwd publicKeyRef:(SecKeyRef*)publicKey privateKeyRef:(SecKeyRef*)privateKey;
+ (SecKeyRef)persitentKeyRef:(NSData*)keyBerData;
+ (BOOL)exportPublicKeyRefWithCerPath:(NSString*)cerPath publicKeyRef:(SecKeyRef*)publicKey;
+ (BOOL)exportPublicKeyRefWithCerData:(NSData*)cerData publicKeyRef:(SecKeyRef*)publicKey;
+ (BOOL)exportPrivateKeyRefWithP12Path:(NSString *)p12Path privateKeyRef:(SecKeyRef *)privateKey;
+ (BOOL)exportPrivateKeyRefWithP12Data:(NSData *)data privateKeyRef:(SecKeyRef *)privateKey;


+ (NSData *)encryptMultBlocksWithData:(NSData *)content publicKeyRef:(SecKeyRef)publicKey;
+ (NSData*)encrypt:(NSData*)plainData publicKeyData:(NSData*)keyBerData;
+ (NSData *)decryptMultBlocksWithData:(NSData *)content privateKeyRef:(SecKeyRef)privateKey;
+ (NSData*)decrypt:(NSData*)data privateKeyData:(NSData*)keyBerData;


+ (NSData *)calculateSha1HashBytes:(NSData *)content;
+ (NSString*)signData:(NSData *)plainTextBytes privateKey:(SecKeyRef)privateKey;
+ (NSString*)signSHA1WithRSA:(NSString *)plainText privateKey:(SecKeyRef)privateKeyRef;
+ (NSData*)signDataSHA1WithRSA:(NSData *)plainTextBytes privateKey:(SecKeyRef)privateKeyRef;
+ (BOOL)verifySHA1WithRSA:(NSString *)plainText signedData:(NSString *)signedData publicKey:(SecKeyRef)publicKey;
+ (BOOL)verifyDataSHA1WithRSA:(NSData *)plainTextBytes signedData:(NSData *)signedDataBytes publicKey:(SecKeyRef)publicKey;
+ (BOOL) sha256VerifyData:(NSData *)plainTextBytes withSignedData:(NSData *)signedDataBytes publicKey:(SecKeyRef)publicKey;


+ (NSString*)hexStringWithData:(NSData*)data;
@end
