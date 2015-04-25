//
//  UIViewController+Extension.h
//  Lakala
//
//  Created by su on 13-6-1.
//  Copyright (c) 2013年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIViewController (Extension)

@end


@interface UINavigationController (Extension)
/*!
 @abstract
 @method 从导航控制器中退到某个类型的viewController页面去
 @param cls viewController类型
 @param yn 是否动画推出
 */
- (BOOL)popToViewControllerWithClass:(Class)cls animated:(BOOL)yn;
@end