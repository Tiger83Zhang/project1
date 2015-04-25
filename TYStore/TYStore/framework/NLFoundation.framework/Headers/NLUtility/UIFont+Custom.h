//
//  UIFont+Custom.h
//  Lakala
//
//  Created by zw SU on 12-10-24.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

#pragma mark 字体尺寸
@interface UIFont (Custom)

// 描述内容的字体 14.0f
+ (UIFont*)defaultDescFont;

// 按钮title默认字体 16.0f
+ (UIFont*)defaultButtonFont;

// 文本标签默认字体  16.0f
+ (UIFont*)defaultLabelFont;

// 强调作用的文本标签默认字体 18.0f
+ (UIFont*)strongLabelFont;

// 导航条title的字体 18.0f
+ (UIFont*)defaultNavTitleFont;

// 导航条内ButtonItem的title字体 12.0f
+ (UIFont*)defaultNavItemFont;

// 分组cell左边文本标签的字体 16.0f
+ (UIFont*)groupCellLeftLabelFont;

// 输入框默认字体
+ (UIFont*)defaultTextFieldFont;

// 分组cell输入框默认字体
+ (UIFont*)groupCellTextFieldFont;

@end
