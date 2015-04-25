//
//  NSObject+Copy.h
//  NLRuntime
//
//  Created by su on 14/6/19.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Copy)
/*!
 @method
 @abstract 将一个对象的属性copy到另一个类的对象
 @discussion 除非属性遵循NSCopy，否则默认不支持深克隆。dic为空，则使用自动属性桥接技术。否则完全按照dic来映射copy
 @param dic 属性关联映射表（self-target）。
 @param target 被拷贝的对象
 */
- (void)copyProperties:(NSDictionary*)dic from:(id)target;
/*!
 @method
 @abstract 将一个对象的属性copy到另一个类的对象
 @discussion 除非属性遵循NSCopy，否则默认不支持深克隆。
 @return 拷贝到属性后的self对象
 */
- (id)copyProperties:(id)target;
/*!
 @method
 @abstract 将一个对象的属性copy到另一个类的对象
 @discussion 除非属性遵循NSCopy，否则默认不支持深克隆。
 @return 拷贝到属性后的self对象
 */
- (id)copyAllProperties:(id)target;
@end
