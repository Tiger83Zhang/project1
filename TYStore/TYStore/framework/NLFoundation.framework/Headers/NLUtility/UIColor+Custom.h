//
//  UIColor+Custom.h
//  Lakala
//
//  Created by zw SU on 12-10-24.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface UIColor (Custom)
//根据字符获取颜色
+ (UIColor *) colorFromHexRGB:(NSString *) inColorString;
@end
