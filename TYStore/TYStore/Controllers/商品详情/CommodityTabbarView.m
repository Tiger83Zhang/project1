//
//  CommodityTabbarView.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "CommodityTabbarView.h"

@interface CommodityTabbarView ()

@property (strong, nonatomic) UIButton *collectBt;
@property (strong, nonatomic) UIImageView *iconView;

@end

@implementation CommodityTabbarView

- (id)init
{
    self = [super initWithFrame:CGRectMake(0, kViewHeight-60, kAppWidth, 60)];
    if (self) {
        [self createView];
    }
    
    return self;
}

- (void)createView
{
    CGFloat width = (kAppWidth - 3) / 4.0;
    
    // 前一个
    UIButton *lastBt = [self buttonWithFrame:CGRectMake(0, 0, width, 60) icon:@"icon_detail_pro.png" title:@"前一个" target:self action:@selector(showLast)];
    [self addSubview:lastBt];
    
    // 后一个
    UIButton *nextBt = [self buttonWithFrame:CGRectMake(width+1, 0, width, 60) icon:@"icon_detail_next.png" title:@"后一个" target:self action:@selector(showNext)];
    [self addSubview:nextBt];
    
    // 详情
    UIButton *detailBt = [self buttonWithFrame:CGRectMake((width+1)*2, 0, width, 60) icon:@"icon_btnshwo_def.png" title:@"详情" target:self action:@selector(showDetail)];
    [self addSubview:detailBt];
    
    // 收藏
    self.collectBt = [self buttonWithFrame:CGRectMake((width+1)*3, 0, width, 60) icon:@"product_collect_default.png" title:@"收藏" target:self action:@selector(doCollect)];
    [self addSubview:self.collectBt];
    
    UIView *lineView1 = [[UIView alloc] initWithFrame:CGRectMake(width, 0, 1, 60)];
    lineView1.backgroundColor = RGBCOLOR(200, 200, 200);
    [self addSubview:lineView1];
    
    UIView *lineView2 = [[UIView alloc] initWithFrame:CGRectMake(width*2+1, 0, 1, 60)];
    lineView2.backgroundColor = RGBCOLOR(200, 200, 200);
    [self addSubview:lineView2];
    
    UIView *lineView3 = [[UIView alloc] initWithFrame:CGRectMake(width*3+2, 0, 1, 60)];
    lineView3.backgroundColor = RGBCOLOR(200, 200, 200);
    [self addSubview:lineView3];
}

- (UIButton *)buttonWithFrame:(CGRect)frame icon:(NSString*)icon title:(NSString*)title target:(id)target action:(SEL)action
{
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.frame = frame;
    [btn setBackgroundColor:RGBCOLOR(109, 166, 171)];
    [btn addTarget:target action:action forControlEvents:UIControlEventTouchUpInside];
    
    UIImageView *iconView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 30, 25)];
    iconView.image = [UIImage imageNamed:icon];
    [btn addSubview:iconView];
    if ([title isEqualToString:@"收藏"]) {
        self.iconView = iconView;
    }
    
    UILabel *titleLb = [[UILabel alloc] initWithFrame:CGRectZero];
    titleLb.text = title;
    titleLb.textColor = [UIColor whiteColor];
    titleLb.font = [UIFont systemFontOfSize:16.0];
    titleLb.backgroundColor = [UIColor clearColor];
    [btn addSubview:titleLb];
    
    CGSize size = [title sizeWithFont:titleLb.font];
    
    iconView.frame = CGRectMake((frame.size.width-iconView.frame.size.width)/2, (60-iconView.frame.size.height-20)/2, iconView.frame.size.width, iconView.frame.size.height);
    titleLb.frame = CGRectMake((frame.size.width-size.width)/2, iconView.frame.origin.y+iconView.frame.size.height, frame.size.width, 25);
    
    return btn;
}

- (void)showLast
{
    if (self.delegate && [self.delegate respondsToSelector:@selector(showLast)]) {
        [self.delegate showLast];
    }
}

- (void)showNext
{
    if (self.delegate && [self.delegate respondsToSelector:@selector(showNext)]) {
        [self.delegate showNext];
    }
}

- (void)showDetail
{
    if (self.delegate && [self.delegate respondsToSelector:@selector(showDetail)]) {
        [self.delegate showDetail];
    }
}

- (void)doCollect
{
    if (self.collectBt.selected) {
        self.collectBt.selected = NO;
        self.iconView.image = [UIImage imageNamed:@"product_collect_default.png"];
    }
    else {
        self.collectBt.selected = YES;
        self.iconView.image = [UIImage imageNamed:@"product_collect_check.png"];
    }
    
    if (self.delegate && [self.delegate respondsToSelector:@selector(doCollect)]) {
        [self.delegate doCollect];
    }
}

@end
