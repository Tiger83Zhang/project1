//
//  AmountFormatter.h
//  yidianfu
//
//  Created by su on 15/1/15.
//  Copyright (c) 2015年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Formatter.h"

@interface AmountFormatter : NSObject<Formatter>
+ (NSString*)amountFenUnitFromYuan:(NSString*)yuan;
+ (NSString*)amountYuanUnitFromFen:(NSString*)fen;
+ (NSString*)standardAmountYuanUnitFromYuan:(NSString*)fen;
@end
