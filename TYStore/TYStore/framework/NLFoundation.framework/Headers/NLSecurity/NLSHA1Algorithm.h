//
//  NLSHA1Algorithm.h
//  NLSecurity
//
//  Created by su on 14/7/25.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLAlgorithm.h"

@interface NLSHA1Algorithm : NSObject<NLAlgorithmStrategy, NLEncryptAlgorithm>
+ (id)initWithText:(NSString*)input;
@end