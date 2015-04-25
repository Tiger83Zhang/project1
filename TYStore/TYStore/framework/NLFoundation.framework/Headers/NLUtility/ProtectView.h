//
//  ProtectView.h
//  ESSI
//
//  Created by su on 14-2-19.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "NSObject+Extension.h"

@interface ProtectView : UIView
@property (nonatomic, strong) CMExecutor *touchExecutor;
+ (id)initWithFrame:(CGRect)frame executor:(CMExecutor*)touchExecutor;
@end