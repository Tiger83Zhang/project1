//
//  UIViews+Extension.h
//  GrammarTest
//
//  Created by zw SU on 12-10-20.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIScreen (ext)

// 当前手机屏幕大小
+ (CGSize)screenSize;
// 是否retina屏幕
+ (BOOL)isRetina;
// 主题请求时，分辨率参数。eg:1024_768
+ (NSString *)themeResolution;

@end

enum {
    UIDevice_iPhoneStandardRes      = 1,    // iPhone 1,3,3GS Standard Resolution   (320x960px)
    UIDevice_iPhoneHiRes            = 2,    // iPhone 4,4S High Resolution          (640x960px)
    UIDevice_iPhoneTallerHiRes      = 3,    // iPhone 5 High Resolution             (640x1136px)
    UIDevice_iPadStandardRes        = 4,    // iPad 1,2 Standard Resolution         (1024x768px)
    UIDevice_iPadHiRes              = 5     // iPad 3 High Resolution               (2048x1536px)
}; typedef NSUInteger UIDeviceResolution;

@interface UIDevice (Resolutions) 

+ (UIDeviceResolution) currentResolution;
+ (NSString*)deviceString;
+ (BOOL)isIphone5;

@end

@interface UIView (ext)

+ (id)initWithFrame:(CGRect)frame;

- (CGPoint)origin;
- (CGSize)size;

- (void)setX:(float)x;
- (void)setY:(float)y;
- (void)setX:(float)x Y:(float)y;
- (void)setOrigin:(CGPoint)point;

- (void)setWidth:(float)width;
- (void)setHeight:(float)height;
- (void)setWidth:(float)width Height:(float)height;
- (void)setSize:(CGSize)size;

// 将一个view自身设置tag，并返回自身
- (id)viewBindTag:(NSInteger)tag;
// 将一个view重新设置frame，并返回自身
- (id)viewBindFrame:(CGRect)rect;
// 将一个view重新设置位置，并返回自身
- (id)viewBindOrigin:(CGPoint)point;
// 将一个view重新设置大小，并返回自身
- (id)viewBindSize:(CGSize)size;
// 查找某个view特定类型的子view
- (id)findSubviewWithClass:(Class)cls;
// 查找第一响应对象
- (UIView*)findFirstResponder;

// 释放第一响应对象
- (void)findAndResignFirstResponder;

// 颜色装饰View
+ (UIView*)colorViewWithFrame:(CGRect)frame color:(UIColor*)color alpha:(CGFloat)alpha;
// 图片装饰View
+ (UIView*)imageViewWithFrame:(CGRect)frame image:(NSString*)img alpha:(CGFloat)alpha;

/*!
 @method
 @abstract 对某个view本身进行截图
 @param frame 指定截图区域
 @return 截图Image
 */
- (UIImage*)captureViewWithFrame:(CGRect)frame;
/*!
 @method
 @abstract 对某个view本身进行截图
 @param frame 指定截图区域
 @param scale 缩放比
 @return 截图Image
 */
- (UIImage*)captureViewWithFrame:(CGRect)frame scale:(CGFloat)scale;
/*!
 @method
 @abstract 对某个view本身进行截图
 @discussion scale 为[UIScreen mainScreen].scale
 @param frame 指定截图区域
 @return 截图Image
 */
- (UIImage*)captureViewDefaultScaleWithFrame:(CGRect)frame;
/*!
 @method
 @abstract 对某个view本身进行截图
 @return 截图Image
 */
- (UIImage*)captureImage;

@end


@interface UIAlertView (ext)
/*!
 @abstract 创建一个只有title、msg、取消的alertView
 @param title 提示框标题
 @param message 提示信息
 @param cancelTitle 取消的标题
 */
+ (UIAlertView*)alertTitle:(NSString*)title msg:(NSString*)message cancel:(NSString*)cancelTitle;
/*!
 @abstract 创建一个只有title、msg、取消的alertView
 @param title 提示框标题
 @param message 提示信息
 @param cancelTitle 取消的标题
 @param otherTitles 更多标题
 */
+ (UIAlertView*)alertTitle:(NSString *)title msg:(NSString *)message cancel:(NSString *)cancelTitle others:(NSString *)otherTitles, ... NS_REQUIRES_NIL_TERMINATION;
/*!
 @abstract 显示alertView并绑定alertView的委托对象
 @param delegate 欲绑定的委托对象
 */
- (void)show:(id<UIAlertViewDelegate>)delegate;
/*!
 @abstract 清除指定tag的alertView
 @param tag 指定alertView的tag
 */
+ (void)dismissWithTag:(NSInteger)tag;
/*!
 @abstract 清除应用所有呈现的alertView
 @method 
 */
+ (void)dismissAll;

@end


@interface UIControl (ext)
/*!
 @abstract 值改变事件执行方法绑定(UISwitch等有效)
 @param target 值改变事件方法执行者
 @param action 值改变事件执行方法
 */
- (void)addTarget:(id)target valueChangedAction:(SEL)action;
/*!
 @abstract 按下事件执行方法绑定
 @param target 按下事件方法执行者
 @param action 按下事件执行方法
 */
- (void)addTarget:(id)target downAction:(SEL)action;

@end



@interface UIButton (ext)
/*!
 @abstract 设置按钮正常和选中(含高亮)状态时的对应图片
 @param normalImg 正常图片
 @param selectedImg 选中高亮图片
 */
- (void)setNormalImage:(NSString*)normalImg select:(NSString*)selectedImg;
/*!
 @abstract 创建按钮
 @param normalImg 正常图片
 @param selectedImg 选中高亮图片
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)buttonWithImage:(NSString *)normalImg select:(NSString *)selectedImg target:(id)target action:(SEL)sel;
/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param normalImg 正常图片
 @param selectedImg 选中高亮图片
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)buttonWithFrame:(CGRect)frame normal:(NSString *)normalImg select:(NSString *)selectedImg target:(id)target action:(SEL)sel;
/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param normalImg 正常图片
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)buttonWithFrame:(CGRect)rect image:(NSString*)normalImg target:(id)target action:(SEL)sel;
/*!
 @abstract 创建图像居中，按钮外框更大的按钮
 @param frame 大小位置
 @param imgName 正常图片
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)imageButtonWithFrame:(CGRect)rect imageName:(NSString *)imgName target:(id)target action:(SEL)sel;
/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param title 文字
 @param titleColor 文字颜色
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)buttonWithFrame:(CGRect)rect title:(NSString *)title titleColor:(UIColor *)titleColor target:(id)target action:(SEL)sel;
/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param title 文字
 @param normalColor 正常文字颜色
 @param selectedColor 选中文字颜色
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)buttonWithFrame:(CGRect)rect title:(NSString *)title normalColor:(UIColor *)normalColor selectedColor:(UIColor*)selectedColor target:(id)target action:(SEL)sel;
/*!
 @abstract 创建矩形框按钮
 @param frame 大小位置
 @param title 文字
 @param titleColor 文字颜色
 @param target action所属对象
 @param sel action执行的方法
 */
+ (UIButton *)rectButtonWithFrame:(CGRect)rect title:(NSString *)title titleColor:(UIColor *)titleColor target:(id)target action:(SEL)sel;
/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param target action所属对象
 @param sel action执行的方法
 @param title 标题
 */
+ (UIButton *)buttonWithFrame:(CGRect)rect title:(NSString *)title target:(id)target action:(SEL)sel;

/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param target action所属对象
 @param sel action执行的方法
 @param title 标题
 @param color 标题颜色
 */
+ (UIButton *)buttonWithFrame:(CGRect)rect title:(NSString *)title textColor:(UIColor *)color target:(id)target action:(SEL)sel;

/*!
 @abstract 创建按钮
 @param frame 大小位置
 @param target action所属对象
 @param sel action执行的方法
 @param title 标题
 @param color 标题颜色
 @param size  标题字体大小
 */
+ (UIButton *)buttonWithFrame:(CGRect)rect title:(NSString *)title textColor:(UIColor *)color textSize:(CGFloat)size target:(id)target action:(SEL)sel;

@end


@interface UIImageView (ext)
/*!
 @abstract 倒影加淡黑渐变
 @param weight 倒影高度
 */
- (void)addReflectEffect:(CGFloat)weight;
/*!
 @abstract 保留四个边缘不拉伸
 @param cap 四个边缘保留的width，中间拉伸
 */
- (void)boundsCap:(CGFloat)cap;

@end

@interface UILabel (ext)
/*!
 @abstract 文本标签自动换行
 @param lines 最大换行数
 */
- (void)autoWrapWithMaxLines:(int)lines;

@end

@interface UIImage (ext)
/*!
 @abstract 从图片底部取部分图片
 @param weight 截取的高度
 @param size 图片的原先预期大小
 @return 截取后的图片
 */
- (UIImage*)pickBottomImage:(float)weight withSize:(CGSize)size;
/*!
 @abstract 从图片顶部取部分图片
 @param weight 截取的高度
 @param size 图片的原先预期大小
 @return 截取后的图片
 */
- (UIImage*)pickTopImage:(float)weight withSize:(CGSize)size;
/*!
 @abstract 粘贴图片到原图上
 @param img 待粘贴的图片
 @param point 粘贴的位置
 @return 粘贴后的图片
 */
- (UIImage*)pasteImage:(UIImage*)img inPoint:(CGPoint)point;
/*!
 @abstract 创建颜色图片
 @param color 要生成的图片颜色
 @param size 生成单独图片大小
 @return 颜色图片
 */
+ (UIImage*)imageWithColor:(UIColor*)color size:(CGSize)size;
/*!
 @abstract 给图片上颜色边框
 @param color 边框颜色
 @param xWidth 左右平均边框宽度
 @param yWidth 上下平均边框宽度
 @return 边框的图片
 */
- (UIImage*)imageBorderWithColor:(UIColor*)color xWidth:(CGFloat)xWidth yWidth:(CGFloat)yWidth;
/*!
 @abstract 对image图片四个边缘不进行拉伸，其余适度拉伸
 @param boundsCap 保留四个边缘的宽度
 @return 保留边缘中间拉伸的图片
 */
- (UIImage*)boundsCap:(CGFloat)cap;
/*!
 @abstract 对image按找给定尺寸进行缩放
 @param targetSize 给定目标尺寸
 @return 缩放后的图像
 */
- (UIImage *)imageByScalingToSize:(CGSize)targetSize;

@end

