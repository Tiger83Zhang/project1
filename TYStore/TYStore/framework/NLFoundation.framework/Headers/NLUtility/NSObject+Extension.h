//
//  NSObject+Extension.h
//  Lakala
//
//  Created by zw SU on 12-10-24.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (ext)

// 如果一个对象具有delegate属性，且可以通过setDelegate方法赋值，则可通过此方法将delegate绑定
- (id)bindDelegate:(id)delegate;
/*!
 @method 执行方法，可传入多个参数的数组，一一对应各个参数
 @abstract
 @param objects 参数数组
 @result 执行方法的对象
 */
- (id)performSelector:(SEL)selector withObjectArray:(NSArray *)objects;
/*!
 @method 执行方法，可传入多个参数，一一对应各个参数
 @abstract
 @param objects 参数列表
 @result 执行方法的对象
 */
- (id)performSelector:(SEL)selector withObjects:(id)objects, ... NS_REQUIRES_NIL_TERMINATION;

@end

/*!
 @class CMExecutor
 @abstract 用于替换delegate机制的执行者类型。调用不同的perform方法进行调用
 */
@interface CMExecutor : NSObject {
}
@property (nonatomic, assign) id performer;
@property (nonatomic, assign) SEL action;
/*!
 @method 用于替换delegate机制的执行者，传入方法执行者和要执行的方法
 @abstract
 @param target 方法执行者
 @param method 执行的方法
 @result
 */
+ (id)initWithTarget:(id)target action:(SEL)method;
/*!
 @method 让方法执行
 @abstract 不传参
 */
- (void)perform;
/*!
 @method 让方法执行
 @abstract 传入一个参数
 @param object 唯一的一个参数
 */
- (void)performWithObject:(id)object;
/*!
 @method 让方法执行
 @abstract 传入多个参数，nil结束
 @param objects 多个参数列表
 */
- (void)performWithObjects:(id)objects, ... NS_REQUIRES_NIL_TERMINATION;

@end

@interface NSOperationQueue (share)
// 创建或者取得一个线程操作队列，方便多任务处理
+ (id)sharedQueue;

@end
