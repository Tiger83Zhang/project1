//
//  RandomUtil.h
//  lakala
//
//  Created by mac on 11-10-3.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface RandomUtil : NSObject {

}
+(void)reallyRandom;
+ (float)randomFloatZeroToOne;
+ (float)randomFloat:(float)num;
+ (int)randomInt:(float)num;
// 生成十六进制随机数
+ (char)randomHex;
// 生成十六位的十六进制随机数
+ (NSString*)random16Hexs;
+(NSArray*)randomArray:(NSArray*)arr;

@end
