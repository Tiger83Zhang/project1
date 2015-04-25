//
//  HomeMenuView.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "HomeMenuView.h"
#import <NLFoundation/NLUtility/UILabel+Custom.h>
#import <NLFoundation/NLUtility/UIViews+Extension.h>

@interface HomeMenuView ()

@end

@implementation HomeMenuView

- (id)initWithMenuData:(HomeMenuData*)menuData
{
    self = [super initWithFrame:menuData.frame];
    if (self) {
        self.menuData = menuData;
        
        [self modifyView];
    }
    
    return self;
}

- (void)modifyView
{
    self.backgroundColor = self.menuData.backgroundColor;
    
//    UIButton *btn = [UIButton buttonWithFrame:CGRectMake(0, 0, self.frame.size.width, self.frame.size.height) title:nil target:self.menuData.target action:self.menuData.action];
//    [self addSubview:btn];
    UIButton *btn = [UIButton buttonWithType:UIButtonTypeCustom];
    btn.tag = self.menuData.menuType;
    btn.frame = CGRectMake(0, 0, self.frame.size.width, self.frame.size.height);
    [btn addTarget:self.menuData.target action:self.menuData.action forControlEvents:UIControlEventTouchUpInside];
    [self addSubview:btn];
    
    BOOL showType = self.frame.size.height > 70? YES : NO;
    
    UIImageView *iconView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 30, 30)];
    iconView.image = [UIImage imageNamed:self.menuData.icon];
    [self addSubview:iconView];
    
    UILabel *titleLb = [[UILabel alloc] initWithFrame:CGRectZero];
    titleLb.text = self.menuData.title;
    titleLb.font = [UIFont systemFontOfSize:16.0];
    titleLb.textColor = [UIColor whiteColor];
    titleLb.backgroundColor = [UIColor clearColor];
    [self addSubview:titleLb];
    
    CGSize size = [titleLb.text sizeWithFont:titleLb.font];
    
    if (showType) {
        iconView.frame = CGRectMake((self.frame.size.width-iconView.frame.size.width)/2, (self.frame.size.height - iconView.frame.size.height-size.height)/2, iconView.frame.size.width, iconView.frame.size.height);
        titleLb.frame = CGRectMake((self.frame.size.width-size.width)/2, iconView.frame.origin.y+iconView.frame.size.height, self.frame.size.width, 30);
    }
    else {
        iconView.frame = CGRectMake((self.frame.size.width-iconView.frame.size.width-size.width)/2, (self.frame.size.height - iconView.frame.size.height)/2, iconView.frame.size.width, iconView.frame.size.height);
        titleLb.frame = CGRectMake(iconView.frame.origin.x+iconView.frame.size.width+5, (self.frame.size.height - 30)/2, self.frame.size.width-iconView.frame.origin.x-iconView.frame.size.width, 30);
    }
}


@end
