//
//  NSObject+Swizz.h
//  jsums
//
//  Created by su on 14-5-15.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>
/*!
 @protocol 拦截类或对象方法进行替换等操作
 @abstract
 @discussion
 */
@protocol SwizzingDataSource <NSObject>
@optional
/*!
 @method
 @abstract 拦截类方法
 @discussion
 @return <需要被拦截方法, 替换方法>
 */
+ (NSDictionary*)swizzingClassSelectorsDatasource;
/*!
 @method
 @abstract 拦截实例方法
 @discussion
 @return <需要被拦截方法, 替换方法>
 */
+ (NSDictionary*)swizzingInstanceSelectorsDatasource;
@end

/*!
 @class
 @abstract 加载拦截器
 @discussion
 */
@interface NSObject (Swizz)
/*!
 @method
 @abstract 对类加载拦截器
 @discussion 一般在NSObject +(void)load 或+(void)initialize时调用
 */
+ (void)loadSwizzingSelectors;
@end
