//
//  UILabel+Custom.h
//  Lakala
//
//  Created by zw SU on 12-10-24.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UILabel (Custom)

- (UILabel*)labelBindFontSize:(float)size;
- (UILabel*)labelBindFont:(UIFont*)font;
- (UILabel*)labelBindText:(NSString*)text;

+ (UILabel *)lableFrame:(CGRect)rect text:(NSString *)text textSize:(float)size textColor:(UIColor*)color;
+ (UILabel *)lableFrame:(CGRect)rect text:(NSString *)text textSize:(float)size;
+ (UILabel *)lableFrame:(CGRect)rect text:(NSString *)text;

//add by feng  带下划线Label
+ (UILabel *)UnderLineFrame:(CGRect)rect text:(NSString *)text;
+ (UILabel *)UnderLineFrame:(CGRect)rect text:(NSString *)text textSize:(float)size;
+ (UILabel *)UnderLineFrame:(CGRect)rect text:(NSString *)text textSize:(float)size textColor:(UIColor*)color;

@end

@interface UnderlineUILabel : UILabel

@end
