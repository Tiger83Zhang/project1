//
//  UIApplication+AppUrl.h
//  callB
//
//  Created by su on 13-1-15.
//  Copyright (c) 2013年 suzw. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *const TargetAppSchemeName;
/*!
 @class UIApplication AppUrl category
 @abstract  应用间通信处理类，指定通信对方的scheme以及发送的消息内容
 */
@interface UIApplication (AppUrl)

+ (BOOL)openDefaultTargetAppWithMsg:(NSString*)msg;

+ (BOOL)openScheme:(NSString*)scheme msg:(NSString*)msg;

@end
