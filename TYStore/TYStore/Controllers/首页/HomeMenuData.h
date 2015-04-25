//
//  HomeMenuData.h
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef enum {
    HomeMenuTypeCompany = 0, // 公司简介
    HomeMenuTypeClass, // 种类
    HomeMenuTypeSpecial, // 特价
    HomeMenuTypeCollection, // 收藏
    HomeMenuTypeHot, // 热卖
    HomeMenuTypeNew, // 新品
    HomeMenuTypeBrander, // 品牌
    HomeMenuTypeUpdate, // 更新数据
    HomeMenuTypeMore, // 更多
    HomeMenuTypeCall, // 联系我们
}HomeMenuType;

@interface HomeMenuData : NSObject

@property (assign, nonatomic) CGRect frame;

@property (strong, nonatomic) UIColor *backgroundColor;

@property (strong, nonatomic) NSString *title;

@property (strong, nonatomic) NSString *icon;

@property (strong, nonatomic) id target;

@property (assign, nonatomic) SEL action;

@property (assign, nonatomic) HomeMenuType menuType;

- (id)initWithFrame:(CGRect)frame backgroundColor:(UIColor *)color title:(NSString*)title icon:(NSString*)icon menuType:(HomeMenuType)menutype target:(id)target action:(SEL)action;

@end
