//
//  SlideNavigationController.m
//  SlideMenu
//
//  Created by Aryan Gh on 4/24/13.
//  Copyright (c) 2013 Aryan Ghassemi. All rights reserved.
//
// https://github.com/aryaxt/iOS-Slide-Menu
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#import "SlideNavigationController.h"
#import "ImageUtil.h"

@interface SlideNavigationController()
@property (nonatomic, strong) UITapGestureRecognizer *tapRecognizer;
@property (nonatomic, strong) UIPanGestureRecognizer *panRecognizer;
@property (nonatomic, assign) CGPoint draggingPoint;
@end

@implementation SlideNavigationController
@synthesize righMenu;
@synthesize leftMenu;
@synthesize tapRecognizer;
@synthesize panRecognizer;
@synthesize draggingPoint;
@synthesize leftbarButtonItem;
@synthesize rightBarButtonItem;
@synthesize enableSwipeGesture;

#define MENU_OFFSET 60
#define MENU_SLIDE_ANIMATION_DURATION .3
#define MENU_QUICK_SLIDE_ANIMATION_DURATION .1
#define MENU_IMAGE @"menu-button"

#define NAVIGAION_BAR_BACKGROUND RGBCOLOR(109, 166, 171)

static SlideNavigationController *singletonInstance;

#pragma mark - Initialization -

+ (SlideNavigationController *)sharedInstance
{
	return singletonInstance;
}

- (void)awakeFromNib
{
	[self setup];
}

- (id)initWithRootViewController:(UIViewController *)rootViewController
{
	if (self = [super initWithRootViewController:rootViewController])
	{
		[self setup];
        [self setNavigationBarView:NAVIGAION_BAR_BACKGROUND];
	}
	
	return self;
}

- (id)init
{
	if (self = [super init])
	{
		[self setup];
        [self setNavigationBarView:NAVIGAION_BAR_BACKGROUND];
	}
	
	return self;
}

- (void)setNavigationBarView:(UIColor*)navColor
{
    if (!navColor) {
        navColor = NAVIGAION_BAR_BACKGROUND;
    }
    // navigation 上的 title 颜色
    self.navigationBar.translucent = NO;
    if ([[UIDevice currentDevice].systemVersion floatValue] >= 7.0) {
        // navigationbar 底色
        [[UINavigationBar appearance] setBarTintColor:navColor];
        // 返回按钮颜色
        [[UINavigationBar appearance] setTintColor:[UIColor whiteColor]];
        //[UINavigationBar appearance]
    }
    else {
        [self.navigationBar setBackgroundImage:[ImageUtil createImageWithColor:navColor]
                                 forBarMetrics:UIBarMetricsDefault];
    }
    
    NSShadow *shadow    = [[NSShadow alloc] init];
    shadow.shadowColor  = [UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.8];
    shadow.shadowOffset = CGSizeMake(1, 1);
    
    NSMutableDictionary *attrDict = [[NSMutableDictionary alloc]init];
    
    if ([[UIDevice currentDevice].systemVersion floatValue]<6.) {
        [attrDict setValue:[UIColor whiteColor] forKey:UITextAttributeTextColor];
        [attrDict setValue:[UIColor colorWithRed:0.0 green:0.0 blue:0.0 alpha:0.8] forKey:UITextAttributeTextShadowColor];
        
        [attrDict setValue:[NSValue valueWithUIOffset:UIOffsetMake(1.0,1.0)]
                    forKey:UITextAttributeTextShadowOffset];
        [attrDict setValue:[UIFont boldSystemFontOfSize:20.0] forKey:UITextAttributeFont];
    }
    else{
        [attrDict setValue:[UIColor whiteColor] forKey:NSFontAttributeName];
        [attrDict setValue:navColor forKey:NSForegroundColorAttributeName];
        //[attrDict setValue:shadow forKey:NSShadowAttributeName];
        [attrDict setValue:[UIFont boldSystemFontOfSize:20.0] forKey:NSFontAttributeName];
    }
    
    self.navigationBar.titleTextAttributes = attrDict;
}

- (void)setup
{
	self.avoidSwitchingToSameClassViewController = YES;
	singletonInstance = self;
	self.delegate = self;
	
	self.view.layer.shadowColor = [UIColor darkGrayColor].CGColor;
	self.view.layer.shadowRadius = 10;
	self.view.layer.shadowPath = [UIBezierPath bezierPathWithRect:self.view.bounds].CGPath;
	self.view.layer.shadowOpacity = 1;
	self.view.layer.shouldRasterize = YES;
	self.view.layer.rasterizationScale = [UIScreen mainScreen].scale;
    
    [self setBarTintColor:CCB_rgb(39, 43, 53)];
    
//	[self setEnableSwipeGesture:YES];//FIXME: 阻止了连接导航器的页面的滑动
}
-(void)setBarTintColor:(UIColor *)color
{
    if (!color) {
        color = NAVIGAION_BAR_BACKGROUND;
    }
    if (G_DEVICE_IOS7) {
        self.navigationBar.barTintColor = color;
    }
    else {
        self.navigationBar.tintColor =color;
    }
}
#pragma mark - Public Methods -

- (void)switchToViewController:(UIViewController *)viewController withCompletion:(void (^)())completion
{
	if (self.avoidSwitchingToSameClassViewController && [self.topViewController isKindOfClass:viewController.class])
	{
		[self closeMenuWithCompletion:completion];
		return;
	}
	
	__block CGRect rect = self.view.frame;
	
	if ([self isMenuOpen])
	{
		[UIView animateWithDuration:MENU_SLIDE_ANIMATION_DURATION
							  delay:0
							options:UIViewAnimationOptionCurveEaseOut
						 animations:^{
			rect.origin.x = (rect.origin.x > 0) ? rect.size.width : -1*rect.size.width;
			self.view.frame = rect;
		} completion:^(BOOL finished) {
			
//			[super popToRootViewControllerAnimated:NO];//FIXME:  popToRoot?
			[super pushViewController:viewController animated:NO];
			
			[self closeMenuWithCompletion:^{
				if (completion)
					completion();
			}];
		}];
	}
	else
	{
//		[super popToRootViewControllerAnimated:NO];//FIXME: popToRoot?
		[super pushViewController:viewController animated:YES];
		
		if (completion)
			completion();
	}
}

- (NSArray *)popToRootViewControllerAnimated:(BOOL)animated
{
	if ([self isMenuOpen])
	{
		[self closeMenuWithCompletion:^{
			[super popToRootViewControllerAnimated:animated];
		}];
	}
	else
	{
		return [super popToRootViewControllerAnimated:animated];
	}
	
	return nil;
}

- (void)pushViewController:(UIViewController *)viewController animated:(BOOL)animated
{
	if ([self isMenuOpen])
	{
		[self closeMenuWithCompletion:^{
			[super pushViewController:viewController animated:animated];
		}];
	}
	else
	{
		[super pushViewController:viewController animated:animated];
	}
}

- (NSArray *)popToViewController:(UIViewController *)viewController animated:(BOOL)animated
{
	if ([self isMenuOpen])
	{
		[self closeMenuWithCompletion:^{
			[super popToViewController:viewController animated:animated];
		}];
	}
	else
	{
		return [super popToViewController:viewController animated:animated];
	}
	
	return nil;
}

#pragma mark - Private Methods -

- (UIBarButtonItem *)barButtonItemForMenu:(Menu)menu
{
	SEL selector = (menu == MenuLeft) ? @selector(leftMenuSelected:) : @selector(righttMenuSelected:);
	UIBarButtonItem *customButton = (menu == MenuLeft) ? self.leftbarButtonItem : self.rightBarButtonItem;
	
	if (customButton)
	{
		customButton.action = selector;
		customButton.target = self;
		return customButton;
	}
	else
	{
		UIImage *image = [UIImage imageNamed:MENU_IMAGE];
        return [[UIBarButtonItem alloc] initWithImage:image style:UIBarButtonItemStylePlain target:self action:selector];
	}
}

- (BOOL)isMenuOpen
{
	return (self.view.frame.origin.x == 0) ? NO : YES;
}

- (BOOL)shouldDisplayMenu:(Menu)menu forViewController:(UIViewController *)vc
{
	if (menu == MenuRight)
	{
		if ([vc respondsToSelector:@selector(slideNavigationControllerShouldDisplayRightMenu)] &&
			[(UIViewController<SlideNavigationControllerDelegate> *)vc slideNavigationControllerShouldDisplayRightMenu])
		{
			return YES;
		}
	}
	if (menu == MenuLeft)
	{
		if ([vc respondsToSelector:@selector(slideNavigationControllerShouldDisplayLeftMenu)] &&
			[(UIViewController<SlideNavigationControllerDelegate> *)vc slideNavigationControllerShouldDisplayLeftMenu])
		{
			return YES;
		}
	}
	
	return NO;
}

- (void)openMenu:(Menu)menu withDuration:(float)duration andCompletion:(void (^)())completion
{
	[self.topViewController.view addGestureRecognizer:self.tapRecognizer];
	
	if (menu == MenuLeft)
	{
		[self.righMenu.view removeFromSuperview];
		[self.view.window insertSubview:self.leftMenu.view atIndex:0];
	}
	else
	{
		[self.leftMenu.view removeFromSuperview];
		[self.view.window insertSubview:self.righMenu.view atIndex:0];
	}
	
	[UIView animateWithDuration:duration
						  delay:0
						options:UIViewAnimationOptionCurveEaseOut
					 animations:^{
						 CGRect rect = self.view.frame;
						 rect.origin.x = (menu == MenuLeft) ? (rect.size.width - MENU_OFFSET) : ((rect.size.width - MENU_OFFSET )* -1);
						 self.view.frame = rect;
					 }
					 completion:^(BOOL finished) {
						 if (completion)
							 completion();
					 }];
}

- (void)openMenu:(Menu)menu withCompletion:(void (^)())completion
{
	[self openMenu:menu withDuration:MENU_SLIDE_ANIMATION_DURATION andCompletion:completion];
}

- (void)closeMenuWithDuration:(float)duration andCompletion:(void (^)())completion
{
	[self.topViewController.view removeGestureRecognizer:self.tapRecognizer];
	
	[UIView animateWithDuration:duration
						  delay:0
						options:UIViewAnimationOptionCurveEaseOut
					 animations:^{
						 CGRect rect = self.view.frame;
						 rect.origin.x = 0;
						 self.view.frame = rect;
					 }
					 completion:^(BOOL finished) {
						 if (completion)
							 completion();
					 }];
}

- (void)closeMenuWithCompletion:(void (^)())completion
{
	[self closeMenuWithDuration:MENU_SLIDE_ANIMATION_DURATION andCompletion:completion];
}

#pragma mark - UINavigationControllerDelegate Methods -

- (void)navigationController:(UINavigationController *)navigationController
	  willShowViewController:(UIViewController *)viewController
					animated:(BOOL)animated
{
	if ([self shouldDisplayMenu:MenuLeft forViewController:viewController])
		viewController.navigationItem.leftBarButtonItem = [self barButtonItemForMenu:MenuLeft];
	
	if ([self shouldDisplayMenu:MenuRight forViewController:viewController])
		viewController.navigationItem.rightBarButtonItem = [self barButtonItemForMenu:MenuRight];
}

#pragma mark - IBActions -

- (void)leftMenuSelected:(id)sender
{
	if ([self isMenuOpen])
		[self closeMenuWithCompletion:nil];
	else
		[self openMenu:MenuLeft withCompletion:nil];
		
}

- (void)righttMenuSelected:(id)sender
{
	if ([self isMenuOpen])
		[self closeMenuWithCompletion:nil];
	else
		[self openMenu:MenuRight withCompletion:nil];
}

#pragma mark - Gesture Recognizing -

- (void)tapDetected:(UITapGestureRecognizer *)tapRecognizer
{
	[self closeMenuWithCompletion:nil];
}

- (void)panDetected:(UIPanGestureRecognizer *)aPanRecognizer
{
	static NSInteger velocityForFollowingDirection = 1000;
	
	CGPoint translation = [aPanRecognizer translationInView:aPanRecognizer.view];
    CGPoint velocity = [aPanRecognizer velocityInView:aPanRecognizer.view];
	
    if (aPanRecognizer.state == UIGestureRecognizerStateBegan)
	{
		self.draggingPoint = translation;
    }
	else if (aPanRecognizer.state == UIGestureRecognizerStateChanged)
	{
		NSInteger movement = translation.x - self.draggingPoint.x;
		CGRect rect = self.view.frame;
		rect.origin.x += movement;
		
		if (rect.origin.x >= self.minXForDragging && rect.origin.x <= self.maxXForDragging)
			self.view.frame = rect;
		
		self.draggingPoint = translation;
		
		if (rect.origin.x > 0)
		{
			[self.righMenu.view removeFromSuperview];
			[self.view.window insertSubview:self.leftMenu.view atIndex:0];
		}
		else
		{
			[self.leftMenu.view removeFromSuperview];
			[self.view.window insertSubview:self.righMenu.view atIndex:0];
		}
	}
	else if (aPanRecognizer.state == UIGestureRecognizerStateEnded)
	{
        NSInteger currentX = self.view.frame.origin.x;
		NSInteger currentXOffset = (currentX > 0) ? currentX : currentX * -1;
		NSInteger positiveVelocity = (velocity.x > 0) ? velocity.x : velocity.x * -1;
		
		// If the speed is high enough follow direction
		if (positiveVelocity >= velocityForFollowingDirection)
		{
			// Moving Right
			if (velocity.x > 0)
			{
				if (currentX > 0)
				{
					[self openMenu:(velocity.x > 0) ? MenuLeft : MenuRight withCompletion:nil];
				}
				else
				{
					[self closeMenuWithDuration:MENU_QUICK_SLIDE_ANIMATION_DURATION andCompletion:nil];
				}
			}
			// Moving Left
			else
			{
				if (currentX > 0)
				{
					[self closeMenuWithCompletion:nil];
				}
				else
				{
					Menu menu = (velocity.x > 0) ? MenuLeft : MenuRight;
					
					if ([self shouldDisplayMenu:menu forViewController:self.visibleViewController])
						[self openMenu:(velocity.x > 0) ? MenuLeft : MenuRight withDuration:MENU_QUICK_SLIDE_ANIMATION_DURATION andCompletion:nil];
				}
			}
		}
		else
		{
			if (currentXOffset < self.view.frame.size.width/2)
				[self closeMenuWithCompletion:nil];
			else
				[self openMenu:(currentX > 0) ? MenuLeft : MenuRight withCompletion:nil];
		}
    }
}

- (NSInteger)minXForDragging
{
	if ([self shouldDisplayMenu:MenuRight forViewController:self.topViewController])
	{
		return (self.view.frame.size.width - MENU_OFFSET)  * -1;
	}
	
	return 0;
}

- (NSInteger)maxXForDragging
{
	if ([self shouldDisplayMenu:MenuLeft forViewController:self.topViewController])
	{
		return self.view.frame.size.width - MENU_OFFSET;
	}
	
	return 0;
}

#pragma mark - Setter & Getter -

- (UITapGestureRecognizer *)tapRecognizer
{
	if (!tapRecognizer)
	{
		tapRecognizer = [[UITapGestureRecognizer alloc] initWithTarget:self action:@selector(tapDetected:)];
	}
	
	return tapRecognizer;
}

- (UIPanGestureRecognizer *)panRecognizer
{
	if (!panRecognizer)
	{
		panRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panDetected:)];
	}
	
	return panRecognizer;
}

- (void)setEnableSwipeGesture:(BOOL)markEnableSwipeGesture
{
	enableSwipeGesture = markEnableSwipeGesture;
	
	if (enableSwipeGesture)
	{
		[self.view addGestureRecognizer:self.panRecognizer];
	}
	else
	{
		[self.view removeGestureRecognizer:self.panRecognizer];
	}
}
-(void)popToRoot:(BOOL)animated
{
    [self popToRootViewControllerAnimated:NO];
}
#pragma mark - InterfaceOrientations
-(BOOL)shouldAutorotate
{
    return NO;
}
-(NSUInteger)supportedInterfaceOrientations
{
    return UIInterfaceOrientationMaskPortrait;
}
-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
{
    return UIInterfaceOrientationPortrait;
}
//#pragma mark - OrientationController
//-(BOOL)shouldAutorotate
//{
//    if ([self.topViewController respondsToSelector:@selector(shouldAutorotate)]) {
//        return [self.topViewController shouldAutorotate];
//    }
//    return NO;
//}
//-(NSUInteger)supportedInterfaceOrientations
//{
//    if ([self.topViewController respondsToSelector:@selector(supportedInterfaceOrientations)]) {
//        return [self.topViewController supportedInterfaceOrientations];
//    }
////    return [super supportedInterfaceOrientations];
//    return UIInterfaceOrientationMaskPortrait;
//}
//-(UIInterfaceOrientation)preferredInterfaceOrientationForPresentation
//{
//    if ([self.topViewController preferredInterfaceOrientationForPresentation]) {
//      return [self.topViewController preferredInterfaceOrientationForPresentation];
//    }
////    return [super preferredInterfaceOrientationForPresentation];
//    return UIInterfaceOrientationPortrait;
//}
@end
