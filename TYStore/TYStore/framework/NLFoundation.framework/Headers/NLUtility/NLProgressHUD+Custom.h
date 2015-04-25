//
//  NLProgressHUD+Custom.h
//  Lakala
//
//  Created by 苏 忠伟 on 12-11-6.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import "NLProgressHUD.h"
#ifndef MAIN_WINDOW
#define MAIN_WINDOW [UIApplication sharedApplication].mainWindow
#endif
@interface UIApplication (ProgressHUD)
- (void)setHud:(NLProgressHUD*)hud;
- (NLProgressHUD*)hud;
- (UIWindow*)mainWindow;
@end

@interface NLProgressHUD (Custom)
/*!
 @method 开始转圈圈
 */
+ (void)show;
/*!
 @method 开始转圈圈，并提示文字
 */
+ (void)show:(NSString*)text;
/*!
 @method 开始转圈圈，并提示文字，延时几秒后消失圈圈执行某个方法
 @param text 提示文本
 @param duration 延时时间
 @param target 执行方法的对象
 @param action 执行的方法
 */
+ (void)show:(NSString*)text after:(CGFloat)duration target:(id)target action:(SEL)action;
/*!
 @method 结束转圈圈
 */
+ (void)hide;
/*!
 @method 提示text
 @param text 提示文本
 @param yOffset y偏移量（相对于屏幕中间线，中间向上为负值，中间偏下为正值）
 */
+ (void)prompt:(NSString*)text yOffset:(NSInteger)yOffset;
/*!
 @method 提示text
 */
+ (void)prompt:(NSString*)text;
/*!
 @method 提示text几秒钟后，立即执行某个block
 @param text 提示文本
 @param duration 提示几秒。单位为秒
 @param block 执行的方法
 */
+ (void)prompt:(NSString *)text duration:(NSTimeInterval)duration ok:(void(^)())block;
/*!
 @method 提示text默认N秒钟后，立即执行某个block
 @param text 提示文本
 @param block 执行的方法
 */
+ (void)prompt:(NSString *)text ok:(void(^)())block;
/*!
 @method 提示“网络连接失败”
 */
+ (void)promptNetFailed;
/*!
 @method 提示“数据异常”
 */
+ (void)promptDataError;
/*!
 @method 提示“没有更多数据了”
 */
+ (void)promptNoMoreData;
@end
