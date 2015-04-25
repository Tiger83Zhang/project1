//
//  NSString+Regular.h
//  ESSI
//
//  Created by su on 14-3-6.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (Regular)
- (NSArray*)matchWithRegex:(NSString*)regex;
@end
