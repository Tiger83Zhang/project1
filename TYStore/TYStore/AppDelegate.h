//
//  AppDelegate.h
//  TYStore
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SlideNavigationController.h"
#import "RESideMenu.h"
@class SlideViewController;

#define MAIN_WINDOW [[[UIApplication sharedApplication] delegate] window]
#define MAIN_NAVIGATION [(AppDelegate*)[[UIApplication sharedApplication] delegate] nav]
#define MAIN_SIDEMENU [(AppDelegate*)[[UIApplication sharedApplication] delegate] sideMenuViewController]
#define MAIN_SIDEVIEW [(AppDelegate*)[[UIApplication sharedApplication] delegate] slideVC]

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) SlideNavigationController *nav;

@property (strong, nonatomic) RESideMenu *sideMenuViewController;

@property (strong, nonatomic) SlideViewController *slideVC;
@end

