//
//  BaseViewController.m
//  CCBPOS
//
//  Created by ZhangSx on 14/12/1.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "BaseViewController.h"
#import <QuartzCore/QuartzCore.h>
#import <NLFoundation/NLUtility/NLProgressHUD.h>
#import "HomeViewController.h"
#import "SlideViewController.h"

@interface BaseViewController()<UIGestureRecognizerDelegate>
{
    BOOL isJump;
}
@end
@implementation BaseViewController
-(id)initWithParams:(id)obj, ...
{
    self = [super initWithNibName:XIBUSE(NSStringFromClass([self class])) bundle:nil];
    if (self) {
        NSMutableArray* arrays = [NSMutableArray array];
        va_list argList;
        if (obj) {
            [arrays addObject:obj];
            va_start(argList, obj);
            id arg;
            while ((arg = va_arg(argList, id))) {
                [arrays addObject:arg];
            }
        }
        self.paramsArr = [NSMutableArray arrayWithArray:arrays];
    }
    return self;
}
-(id)init
{
    self = [super init];
    if (self) {
        //
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:NO];
    }
    return self;
    //    return [self initWithNibName:XIBUSE(NSStringFromClass([self class])) bundle:nil];
}
- (id)initWiithOutXib
{
    self = [super init];
    if (self) {
        //
        [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:NO];
    }
    return self;
}
-(id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        if(G_DEVICE_IOS7)
        {
            [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:NO];
            
            [self.navigationController.navigationBar setTitleTextAttributes:[NSDictionary dictionaryWithObjectsAndKeys:
                                                                             [UIColor whiteColor], UITextAttributeTextColor,
                                                                             [UIColor colorWithRed:0 green:0.7 blue:0.8 alpha:1], UITextAttributeTextShadowColor,
                                                                             [NSValue valueWithUIOffset:UIOffsetMake(0, 0)], UITextAttributeTextShadowOffset,
                                                                             [UIFont fontWithName:@"Helvetica-Bold" size:20.0], UITextAttributeFont,
                                                                             nil]];
        }
        // 防止按钮可以同时被按下
        for(UIView* v in self.view.subviews)
        {
            if([v isKindOfClass:[UIButton class]])
            {
                UIButton* btn = (UIButton*)v;
                [btn setExclusiveTouch:YES];
            }
        }
    }
    return self;
}

-(void)setTitle:(NSString *)title
{
    self.labTitle = [[UILabel alloc]initWithFrame:CGRectMake(0, 0, 100, 40)];
    _labTitle.text = title;
    _labTitle.font = [UIFont boldSystemFontOfSize:20.0];
    _labTitle.backgroundColor = [UIColor clearColor];
    _labTitle.textColor= [UIColor whiteColor];
    _labTitle.textAlignment = NSTextAlignmentCenter;
    
    self.navigationItem.titleView = _labTitle;
}

-(void)createBackButton
{
    UIButton * btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(0, 0, 25, 25);
    [btn setBackgroundImage:[UIImage imageNamed:@"btn_back_nor.9.png"] forState:UIControlStateNormal];
    [btn setBackgroundImage:[UIImage imageNamed:@"btn_back_sel.9.png"] forState:UIControlStateHighlighted];
    [btn addTarget:self action:@selector(btnBack:) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem * leftB = [[UIBarButtonItem alloc] initWithCustomView:btn];
    self.navigationItem.leftBarButtonItem = leftB;
}
-(void)createRightButton
{
    UIButton * btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(0, 0, 20, 20);
    [btn setBackgroundImage:[UIImage imageNamed:@"addClerk.png"] forState:UIControlStateNormal];
    [btn addTarget:self action:@selector(btnRight:) forControlEvents:UIControlEventTouchUpInside];
    UIBarButtonItem * rightB = [[UIBarButtonItem alloc] initWithCustomView:btn];
    self.navigationItem.rightBarButtonItem = rightB;
}
- (UIButton*)createRightButtonWithTitle:(NSString *)title action:(SEL)action
{
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    [btn setTitle:title forState:UIControlStateNormal];
    CGSize size = [title sizeWithFont:[UIFont systemFontOfSize:15.0]];
    btn.titleLabel.font = [UIFont systemFontOfSize:15.0];
    [btn setFrame:CGRectMake(0, 0, size.width, 44)];
    [btn addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:btn];
    return btn;
}
- (UIButton*)createRightButtonWithNormalImage:(NSString*)nor selectImage:(NSString*)sel action:(SEL)action
{
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn setFrame:CGRectMake(0, 0, 20, 20)];
    [btn setBackgroundImage:[UIImage imageNamed:nor] forState:UIControlStateNormal];
    [btn setBackgroundImage:[UIImage imageNamed:sel] forState:UIControlStateHighlighted];
    [btn addTarget:self action:action forControlEvents:UIControlEventTouchUpInside];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:btn];
    return btn;
}
-(void)hideBackButton
{
    UIButton * btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = CGRectMake(0, 0, 28, 20);
    btn.hidden = YES;
    UIBarButtonItem * leftB = [[UIBarButtonItem alloc] initWithCustomView:btn];
    self.navigationItem.leftBarButtonItem = leftB;
}
-(void)configButton:(UIButton *)btn unselectName:(NSString *)uname selectName:(NSString *)name title:(NSString *)title
{
    UIImage * imgUn = [UIImage imageNamed:uname];
    imgUn = [imgUn resizableImageWithCapInsets:UIEdgeInsetsMake(5, 5, 5, 5)];
    UIImage * img = [UIImage imageNamed:name];
    img = [img resizableImageWithCapInsets:UIEdgeInsetsMake(5, 5, 5, 5)];
    
    [btn setTitle:title forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:19];
    [btn setBackgroundImage:imgUn forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    
    [btn setBackgroundImage:img forState:UIControlStateHighlighted];
    [btn setTitleColor:[UIColor lightGrayColor] forState:UIControlStateHighlighted];
    
}
-(void)configButton:(UIButton *)btn unselectName:(NSString *)uname selectName:(NSString *)name title:(NSString *)title  size:(float)size
{
    UIImage * imgUn = [UIImage imageNamed:uname];
    imgUn = [imgUn resizableImageWithCapInsets:UIEdgeInsetsMake(5, 5, 5, 5)];
    UIImage * img = [UIImage imageNamed:name];
    img = [img resizableImageWithCapInsets:UIEdgeInsetsMake(5, 5, 5, 5)];
    
    [btn setTitle:title forState:UIControlStateNormal];
    btn.titleLabel.font = [UIFont boldSystemFontOfSize:size];
    [btn setBackgroundImage:imgUn forState:UIControlStateNormal];
    [btn setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
    
    [btn setBackgroundImage:img forState:UIControlStateHighlighted];
    [btn setTitleColor:[UIColor lightGrayColor] forState:UIControlStateHighlighted];
    
}
-(void)configBgView:(UIImageView *)v bgName:(NSString *)name
{
    UIImage * imgUn = [UIImage imageNamed:name];
    imgUn = [imgUn resizableImageWithCapInsets:UIEdgeInsetsMake(5, 5, 5, 5)];
    [v setImage:imgUn];
}
-(void)btnBack:(UIButton *)btn
{
    [self.navigationController popViewControllerAnimated:YES];
}
-(void)btnRight:(UIButton *)btn
{
    
}
-(void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [[UIApplication sharedApplication] setStatusBarStyle:UIStatusBarStyleLightContent animated:NO];
    [self.navigationController setNavigationBarHidden:NO animated:YES];
    [[UIApplication sharedApplication] setStatusBarHidden:NO];
    
    if (![self isKindOfClass:[SlideViewController class]]) {
        MAIN_SIDEMENU.open = NO;
    }
    
    if (![self isKindOfClass:[HomeViewController class]] && ![self isKindOfClass:[SlideViewController class]]) {
        if (G_DEVICE_IOS7) {
            [MAIN_NAVIGATION setBarTintColor:self.navColor];
        }
        else {
            [MAIN_NAVIGATION setNavigationBarView:self.navColor];
        }
    }
}
- (void)viewWillDisappear:(BOOL)animated
{
    // 界面消失，清除设备接口回调
    [super viewWillDisappear:animated];
}
- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    [self createBackButton];
    self.view.backgroundColor = RGBCOLOR(242, 242, 242);
    
    UITapGestureRecognizer *tapGesture = [[UITapGestureRecognizer alloc]initWithTarget:self
                                                         action:@selector(hideKeyBorad:)];
    tapGesture.cancelsTouchesInView = NO;
    tapGesture.delegate = self;
    [self.view addGestureRecognizer:tapGesture];
}
- (void)showPrompt:(NSString *)prompt
{
    [self showPrompt:prompt delay:2.5];
}

- (void)showPrompt:(NSString *)prompt follow:(void (^)(void))follow
{
    [self showPrompt:prompt];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        sleep(2.5);//FIXME:显示时间
        dispatch_async(dispatch_get_main_queue(), ^{
            follow();
        });
    });
}

- (void)showPrompt:(NSString *)prompt delay:(NSTimeInterval)delay
{
    if (prompt!=nil&&prompt.length>0) {
        BOOL hasAlert = NO;
        for (id window in [[UIApplication sharedApplication] windows]) {
            for (id view in ((UIView *)window).subviews) {
                if ([view isKindOfClass:[UIAlertView class]] && ((UIAlertView *)view).tag != RECEIBVABLE_CHANGE_AMOUNT_VIEW_TAG) {
                    hasAlert = YES;
                    break;
                }
            }
            if (hasAlert == YES) {
                break;
            }
        }
        if (hasAlert == NO) {
            NLProgressHUD *hud = [NLProgressHUD showHUDAddedTo:MAIN_WINDOW animated:YES];
            if (prompt.length > 14) {
                //        hud.labelFont = [UIFont systemFontOfSize:13];
            }
            hud.mode = NLProgressHUDModeText;
            hud.labelText = prompt;
            hud.yOffset = -32;
            //    hud.yOffset = (self.navigationController.view ? 0 : -32);
            [hud hide:YES afterDelay:delay];
        }
    }
    
}

- (void)showSpinnerWhen:(void (^)(void))someThings completion:(void (^)(void))completion
{
    if (self.navigationController.view) {
        [self showSpinnerInView:self.navigationController.view when:someThings completion:completion];
    } else {
        NSLog(@"=============================view is nil.");
    }
}

- (void)showSpinnerInView:(UIView *)view when:(void (^)(void))someThings completion:(void (^)(void))completion
{
    [NLProgressHUD hideAllHUDsForView:MAIN_WINDOW animated:NO];
    [NLProgressHUD showHUDAddedTo:MAIN_WINDOW animated:YES];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        someThings();
        dispatch_async(dispatch_get_main_queue(), ^{
            [NLProgressHUD hideHUDForView:MAIN_WINDOW animated:YES];
            completion();
        });
    });
}
- (void)showSpinnerWhen1:(void (^)(void))someThings completion:(void (^)(void))completion timeinterval:(int)timeinterval
{
    if (self.navigationController.view) {
        [self showSpinnerInView1:self.navigationController.view when:someThings completion:completion timeinterval:timeinterval];
    } else {
        NSLog(@"=============================view is nil.");
    }
}
-(void)showSpinnerInView1:(UIView *)view when:(void (^)(void))someThings completion:(void (^)(void))completion timeinterval:(int)timeinterval
{
    [NLProgressHUD hideAllHUDsForView:MAIN_WINDOW animated:NO];
    NLProgressHUD *hud = [[NLProgressHUD alloc] initWithView:view];
    hud.mode = NLProgressHUDModeDeterminate;
    //    hud.mode = MBProgressHUDModeText;
    hud.tag = timeinterval;
    isJump = NO;
    [view addSubview:hud];
    [hud showWhileExecuting:@selector(updateProgress:) onTarget:self withObject:hud animated:YES];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        someThings();
        dispatch_async(dispatch_get_main_queue(), ^{
            [NLProgressHUD hideAllHUDsForView:MAIN_WINDOW animated:NO];
            isJump = YES;
            completion();
        });
    });
}
-(void)updateProgress:(NLProgressHUD *)hub
{
    int t = 0;
    while (hub.progress < 1.0f && !isJump) {
        t += 1;
        [NSThread sleepForTimeInterval:0.001];
        hub.progress = (double)t/hub.tag;
        //             hub.labelText = [NSString stringWithFormat:@"%d%%",t*100/hub.tag];
        //             NSLog(@"%d.....",t);
    }
}
-(void)btnPageBack:(id)sender
{
    [self.navigationController popViewControllerAnimated:YES];
}
- (BOOL)popToController:(Class)viewControllerClass animated:(BOOL)animated
{
    for (UIViewController *viewConroller in MAIN_NAVIGATION.viewControllers) {
        if ([viewConroller isKindOfClass:viewControllerClass]) {
            [MAIN_NAVIGATION popToViewController:viewConroller animated:animated];
            return YES;
        }
    }
    return NO;
}
- (BOOL)popToController:(Class)viewControllerClass animated:(BOOL)animated completion:(void (^)(void))completion
{
    BOOL result = [self popToController:viewControllerClass animated:animated];
    if (result) {
        dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
            if (animated) {
                sleep(0.3);//FIXME:显示时间
            }
            dispatch_async(dispatch_get_main_queue(), ^{
                completion();
            });
        });
    }
    return result;
}
- (void)popToRootViewController:(BOOL)animated completion:(void (^)(void))completion
{
    [MAIN_NAVIGATION popToRootViewControllerAnimated:animated];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        if (animated) {
            sleep(0.3);//FIXME:显示时间
        }
        dispatch_async(dispatch_get_main_queue(), ^{
            completion();
        });
    });
}
#pragma mark 隐藏键盘
-(void)hideKeyBorad:(UITapGestureRecognizer*)tap
{
    [[[UIApplication sharedApplication] keyWindow] endEditing:YES];
}

@end
