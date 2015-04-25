//
//  CommodityTabbarView.h
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol CommodityTabbarDelegate <NSObject>

- (void)showLast;
- (void)showNext;
- (void)showDetail;
- (void)doCollect;

@end

@interface CommodityTabbarView : UIView

@property (assign, nonatomic) id<CommodityTabbarDelegate>delegate;

@end
