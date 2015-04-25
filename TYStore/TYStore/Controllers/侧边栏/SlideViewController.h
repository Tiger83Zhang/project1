//
//  SlideViewController.h
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "BaseViewController.h"
@class CommodityListViewController;

@interface SlideViewController : BaseViewController

@property (strong, nonatomic) CommodityListViewController *listVC; // 当前列表


- (void)setCurrListViewController:(CommodityListViewController*)listVC;
@end
