//
//  NSCommonObjects+Extension.h
//  GrammarTest
//
//  Created by zw SU on 12-10-22.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 @enum
 @abstract 时间格式
 @constant NSDateFormatStandard 默认标准格式  yyyy-MM-dd HH:mm
 @constant NSDateFormatStandardDate 标准日期格式 yyyy-MM-dd
 @constant NSDateFormatStandardFull 标准完全时间格式 yyyy-MM-dd HH:mm:ss
 @constant NSDateFormatSimpleDate 简洁日期时间格式 yyyyMMdd
 @constant NSDateFormatSimpleFull 简洁完全时间格式 yyyyMMddHHmmss
 @constant NSDateFormatCNFull 中文时间全格式  yyyy年MM月dd日 hh:mm
 @constant NSDateMonthDayCN 中文月日格式  MM月dd日
 @constant NSDateYMDCN 中文年月日格式  yyyy年MM月dd日
 @constant NSDateYMDSlash 以斜杠分隔年月日格式  yyyy/MM/dd
 @constant NSDateYearMonth 以斜杠分隔年月日格式  yyyy-MM
 @constant NSDateYearMonthNone   yyyyMM
 */
typedef enum {
    NSDateFormatStandard,
    NSDateFormatStandardDate,
    NSDateFormatStandardFull,
    NSDateFormatSimpleDate,
    NSDateFormatSimpleFull,
    NSDateFormatCNFull,
    NSDateMonthDayCN,
    NSDateYMDCN,
    NSDateYMDSlash,
    NSDateYearMonth,
    NSDateYearMonthNone
} NSDateFormat;

@interface NSDate(ext)
/*!
 @method 
 @abstract 根据给出的时间格式，返回当前时间
 @discussion 时间格式定义NSDateFormat枚举类型中
 @result 返回格式化后的当前时间
 */
+ (NSString*)currentDate:(NSDateFormat)fr;
/*!
 @method
 @abstract 根据给出的时间格式，返回当前时间
 @discussion 时间格式
 @result 返回格式化后的当前时间
 */
+ (NSString*)currentDateWithFormate:(NSString*)fr;
/*!
 @method
 @abstract 返回当前时间的NSDateFormatStandard类型格式
 @discussion yyyy-MM-dd HH:mm
 @result 返回NSDateFormatStandard格式化后的当前时间
 */
+ (NSString*)standardCurrentDate;
/*!
 @method
 @abstract 根据给出的时间格式，返回所代表的时间格式
 @discussion 时间格式定义NSDateFormat枚举类型中
 @result 返回时间格式字符串
 */
+ (NSString*)formateString:(NSDateFormat)fr;
@end

@interface NSString (date)
/*!
 @method
 @abstract 根据给出的时间格式，返回所代表的时间
 @discussion 时间格式定义NSDateFormat枚举类型中
 @result 返回格式化时间
 */
- (NSDate*)formateDate:(NSDateFormat)fr;
@end


@interface NSUserDefaults (ext)

+ (void)serialize:(id)obj key:(NSString*)key;
+ (id)reverseForKey:(NSString*)key;
+ (BOOL)isSerializedForKey:(NSString*)key;

@end