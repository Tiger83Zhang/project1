//
//  NLMD5Algorithm.h
//  jsums
//
//  Created by su on 14-4-30.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLAlgorithm.h"

@interface NLMD5Algorithm : NSObject<NLAlgorithmStrategy, NLEncryptAlgorithm>
+ (id)initWithText:(NSString*)input;
@end