//
//  UIImage+Extension.h
//  ESSI
//
//  Created by su on 14-1-20.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIImage (Extension)
- (UIImage*)resizableImageWithCap:(CGFloat)cap;
- (UIImage*)redrawImageWithCap:(CGFloat)cap;
- (UIImage *)reSizeImageWithSize:(CGSize)reSize;
@end


CG_INLINE CGRect
CGRectMakeWithSize(CGSize size)
{
    CGRect rect;
    rect.origin.x = 0; rect.origin.y = 0;
    rect.size.width = size.width; rect.size.height = size.height;
    return rect;
}