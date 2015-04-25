//
//  UISegmentedControl+Custom.h
//  Lakala
//
//  Created by su on 12-11-12.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UISegmentedControl (Custom)

// UISegmentedControlStylePlain风格的UISegmentedControl，默认selectedIndex为0
+  (UISegmentedControl*)plainStyleSegmentedControl:(CGRect) frame target:(id)target action:(SEL)action titles:(NSString *)titles, ... NS_REQUIRES_NIL_TERMINATION;

@end
