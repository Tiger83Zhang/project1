//
//  CommodityView.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "CommodityView.h"
#import "CommodityDetailViewController.h"

@interface CommodityView ()

@property (strong, nonatomic) NSDictionary *data;

@property (strong, nonatomic) UIImageView *imageView;

@property (strong, nonatomic) UIButton *collectBt;

@end

@implementation CommodityView

- (id)init
{
    self = [super initWithFrame:CGRectMake(0, 0, kAppWidth/2, 200)];
    if (self) {
        self.backgroundColor = [UIColor clearColor];
        [self createView];
    }
    return self;
}

- (void)createView
{
    UIButton *bgBt = [UIButton buttonWithType:UIButtonTypeCustom];
    bgBt.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
    [bgBt setBackgroundImage:[UIImage imageNamed:@"select.png"] forState:UIControlStateHighlighted];
    [bgBt addTarget:self action:@selector(toDetail) forControlEvents:UIControlEventTouchUpInside];
    [self addSubview:bgBt];
    
    self.imageView = [[UIImageView alloc] initWithFrame:CGRectMake(4, (200-100)/2, kAppWidth/2-8, 100)];
    self.imageView.backgroundColor = [UIColor orangeColor];
    [self addSubview:self.imageView];
    
    self.collectBt = [UIButton buttonWithType:UIButtonTypeCustom];
    [self.collectBt setFrame:CGRectMake(kAppWidth/2-30, self.imageView.frame.origin.y+self.imageView.frame.size.height+10, 20, 20)];
    [self.collectBt addTarget:self action:@selector(doCollect:) forControlEvents:UIControlEventTouchUpInside];
    [self.collectBt setImage:[UIImage imageNamed:@"product_collect_check.png"] forState:UIControlStateSelected];
    [self.collectBt setImage:[UIImage imageNamed:@"product_collect_default.png"] forState:UIControlStateNormal];
    [self addSubview:self.collectBt];
}

- (void)updateViewWithData:(NSDictionary *)data
{
    self.data = data;
    [self createView];
}

#pragma mark UIControl
- (void)doCollect:(UIButton*)button
{
    button.selected = !button.selected;
}

- (void)toDetail
{
    CommodityDetailViewController *detailVC = [[CommodityDetailViewController alloc] init];
    [MAIN_NAVIGATION pushViewController:detailVC animated:YES];
}

@end
