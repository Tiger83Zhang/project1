//
//  HomeMenuView.h
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "HomeMenuData.h"

@interface HomeMenuView : UIView

@property (strong, nonatomic) HomeMenuData *menuData;

- (id)initWithMenuData:(HomeMenuData*)menuData;
@end
