//
//  HomeMenuData.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "HomeMenuData.h"

@implementation HomeMenuData

- (id)initWithFrame:(CGRect)frame backgroundColor:(UIColor *)color title:(NSString*)title icon:(NSString*)icon menuType:(HomeMenuType)menutype target:(id)target action:(SEL)action
{
    self = [super init];
    if (self) {
        self.frame = frame;
        self.backgroundColor = color;
        self.title = title;
        self.icon = icon;
        self.menuType = menutype;
        self.target = target;
        self.action = action;
    }
    return self;
}
@end
