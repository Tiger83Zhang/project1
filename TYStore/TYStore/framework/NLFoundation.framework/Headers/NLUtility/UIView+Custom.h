//
//  UIView+Custom.h
//  Lakala
//
//  Created by lint on 12-10-25.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    WebViewTag = 1999,
} SubViewTags;

@interface UIView (Custom)

// 信息介绍背景块
+ (UIView*)infoViewWithFrame:(CGRect)frame bgColor:(UIColor*)color;
// 默认信息介绍背景块(黄色背景，左移10)
+ (UIView*)defaultInfoViewWithY:(CGFloat)y height:(CGFloat)height;
// 淡入淡出动画，附带动画结束的block
+ (void)animateCurveEaseIn:(NSTimeInterval)duration animations:(void (^)(void))animations ok:(void (^)(void))complete;
// 淡入淡出动画
+ (void)animateCurveEaseIn:(NSTimeInterval)duration animations:(void (^)(void))animations;
// duration0.2f快速淡入淡出
+ (void)animateQuickCurveEaseIn:(void(^)(void))animations;

@end
