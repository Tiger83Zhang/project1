//
//  BaseViewController.h
//  CCBPOS
//
//  Created by ZhangSx on 14/12/1.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "AppDelegate.h"
#import <NLFoundation/NLUtility/NLProgressHUD+Custom.h>
#import <NLFoundation/NLRuntime/NSObject+Runtime.h>
@interface BaseViewController : UIViewController
/*!
 *  @brief  参数数组
 */
@property (nonatomic,strong) NSMutableArray * paramsArr;
@property (nonatomic,strong) IBOutlet UILabel * labTitle;
@property (nonatomic,strong) UIColor *navColor;
/*!
 *  @brief  传递多参数至页面
 *
 *  @param obj 参数1。。。
 *
 *  @return viewcontroller对象
 */
-(id)initWithParams:(id)obj,...NS_REQUIRES_NIL_TERMINATION;
/*!
 *  @brief  toast
 *
 *  @param prompt 显示提示信息，默认
 */
- (void)showPrompt:(NSString *)prompt;
- (void)showPrompt:(NSString *)prompt delay:(NSTimeInterval)delay;

//显示提示信息，1秒后执行follow
- (void)showPrompt:(NSString *)prompt follow:(void (^)(void))follow;

//在做somethings的时候转圈圈，然后执行completion
- (void)showSpinnerWhen:(void (^)(void))someThings completion:(void (^)(void))completion;
- (void)showSpinnerInView:(UIView *)view when:(void (^)(void))someThings completion:(void (^)(void))completion;
- (void)showSpinnerWhen1:(void (^)(void))someThings completion:(void (^)(void))completion timeinterval:(int)timeinterval;//add by zsx
-(void)showSpinnerInView1:(UIView *)view when:(void (^)(void))someThings completion:(void (^)(void))completion timeinterval:(int)timeinterval;//add by zsx
-(void)createBackButton;
-(void)createRightButton;
- (UIButton*)createRightButtonWithTitle:(NSString*)title action:(SEL)action;
- (UIButton*)createRightButtonWithNormalImage:(NSString*)nor selectImage:(NSString*)sel action:(SEL)action;
-(void)hideBackButton;
-(void)configButton:(UIButton *)btn unselectName:(NSString *)uname selectName:(NSString *)name title:(NSString *)title;
-(void)configButton:(UIButton *)btn unselectName:(NSString *)uname selectName:(NSString *)name title:(NSString *)title  size:(float)size;
-(void)configBgView:(UIImageView *)v bgName:(NSString *)name;
-(void)configButton:(UIButton *)btn title:(NSString *)title size:(float)size;
-(void)btnBack:(UIButton *)btn;
-(void)btnRight:(UIButton *)btn;
-(IBAction)btnPageBack:(id)sender;

- (BOOL)popToController:(Class)viewControllerClass animated:(BOOL)animated;
- (BOOL)popToController:(Class)viewControllerClass animated:(BOOL)animated completion:(void (^)(void))completion;
- (void)popToRootViewController:(BOOL)animated completion:(void (^)(void))completion;

- (id)initWiithOutXib;
@end
