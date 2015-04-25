//
//  NLAlgorithm.h
//  jsums
//
//  Created by su on 14-4-30.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @enum NLAlgorithmOperation
 @discussion
 @constant NLEncrypt
 @constant NLDecrypt
 */
typedef enum {
    NLEncrypt,
    NLDecrypt
} NLAlgorithmOperation;


@protocol NLAlgorithmStrategy <NSObject>
@required
/*!
 @method
 @abstract 算法计算
 @discussion can be override
 */
- (NSString*)calculate:(NLAlgorithmOperation)op;
- (NSString*)strategyName;
@end


/*!
 @protocol
 @abstract 加密算法
 @discussion
 */
@protocol NLEncryptAlgorithm <NSObject>
@required
- (NSString*)encrypt;
@end

/*!
 @protocol
 @abstract 解密算法
 @discussion
 */
@protocol NLDecryptAlgorithm <NSObject>
@required
- (NSString*)decrypt;
@end


