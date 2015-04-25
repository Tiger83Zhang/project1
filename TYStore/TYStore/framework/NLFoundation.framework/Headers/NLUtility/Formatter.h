//
//  Formatter.h
//  jsums
//
//  Created by su on 14-5-16.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol Formatter <NSObject>
- (NSString*)format:(id)object;
- (id)unformat:(NSString*)string;
@optional
- (void)setPattern:(NSString*)pattern;
@end