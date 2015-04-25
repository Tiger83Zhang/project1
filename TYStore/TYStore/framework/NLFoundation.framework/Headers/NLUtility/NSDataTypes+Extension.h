//
//  NSDataTypes+Extension.h
//  GrammarTest
//
//  Created by zw SU on 12-10-20.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#import <UIKit/UIColor.h>
#import "NSCommonObjects+Extension.h"
int hexCharToInt(const char c);
int hexStringToInt(const char *hex);

@interface NSString (ext)
/*!
 @method
 @abstract 将一个可能是NSString的对象，或者空对象，强制转回NSString类型
 @discussion 如果该对象不是NSString，或者为nil、NSNull，则返回@""。否则返回正常String自身
 @result NSString
 */
+ (NSString*)notNull:(NSString*)str;
/*!
 @method 
 @abstract 判断字符串是否为空（推荐使用）
 @discussion 如果字符串为nil或NSNull，或字符串长度小于等于零，或者trim之后与空字符串匹配，则判断为空
 @result 是否为空
 */
+ (BOOL)isEmpty:(NSString*)str;
/*!
 @method 
 @abstract 判断非nil字符串是否为空
 @discussion 在字符串不为nil、NSNull时, 如果字符串长度小于等于零，或者trim之后与空字符串匹配，则判断为空
                如果不确定NSString 是否为空，则应该调用[NSString isEmpty:str];
 @result 是否为空
 */
- (BOOL)isEmpty;
/*!
 @method 
 @abstract 去除字符串首位的空字符串
 @discussion
 @result 去除首尾空字符串的新字符串
 */
- (NSString*)trim;
/*!
 @method
 @abstract 在文件扩展名前追加str
 @discussion 
 @param str 追加的字符串
 @result 追加后的文件名
 */
- (NSString*)pathAppendBeforeExtension:(NSString*)str;
/*!
 @method
 @abstract 在文件名前追加str
 @discussion
 @param str 追加的字符串
 @result 追加后的文件名
 */
- (NSString*)pathAppendBeforeName:(NSString*)str;
/*!
 @method
 @abstract 时间字符串格式化
 @param srcFormat 原日期格式 定义在NSDateFormat枚举类型中
 @param destFormat 目标转换时间格式 定义在NSDateFormat枚举类型中
 @result 格式化后的时间
 */
- (NSString*)formatDateWithSrcFormat:(NSDateFormat)srcFormat destFormat:(NSDateFormat)destFormat;
/*!
 @method
 @abstract 时间字符串格式化
 @param srcFormat 原日期格式 
 @param destFormat 目标转换时间格式 
 @result 格式化后的时间
 */
- (NSString*)formatDateWithSrc:(NSString*)srcFormat dest:(NSString*)destFormat;
/*!
@method
@abstract 由yyyy-MM-dd 转换为MM月dd日
@result 格式化后的时间
*/
- (NSString*)CNDateFromYMD2YM;

@end


@interface NSString (money)
/*!
 @method 
 @abstract 将金额格式化成两位小数点的字符串
 @discussion 将一大数money格式化成两位小数点的字符串
 @result 格式化后的金额字符串
 */
+ (NSString*)formatMoney:(double)money;
// 格式化成中文金额。即两位小数金额 元
+ (NSString*)formatCNMoney:(double)money;
// 校验金额是否合法（不能小于零）
+ (BOOL)isMoneyValid:(NSString *)money;

@end


@interface NSString (card)

// 校验卡号是否合法（必须在10～32位之间）
+ (BOOL)isCardNumValid:(NSString *)cardNum;
// 前六后四中间四个*掩码的卡号格式
- (NSString*)cardNum64format;
// 四四格式
- (NSString*)cardNum44format;

@end

@interface NSString (color)
/*!
 @method 
 @abstract 将十六进制字符串（如＃ffffff或者ffffff）转换为相应的颜色
 @discussion 如果颜色字符串不合法，默认返回白色
 @param alpha 颜色透明值
 @result 对应的rgb颜色
 */
- (UIColor *) hexStringToColorWithAlpha:(float)alpha;

@end

/*!
 @abstract URL转义，指定忽略转义的符号
 @constants kEncodeURLEscapesAllSymbols = @":/?#[]@!$ &'()*+,;=\"<>%{}|\\^~`"
 @constants kEncodeURLEscapesNewLineSymbols = @"!*'\"();:@&=+$,/?%#[]% "
 @constants kEncodeURLEscapesCommonSymbols = @"!*'();:@&=+$,/?%#[]"
 */
extern NSString *const kEncodeURLEscapesAllSymbols;
extern NSString *const kEncodeURLEscapesNewLineSymbols;
extern NSString *const kEncodeURLEscapesCommonSymbols;

@interface NSString (transfer)
/*!
 @method url转义
 @result url转义编码
 */
- (NSString*)encodeURLString;
/*!
 @method escapedURLString
 @result
 An autorelease NSString object with all special characters being converted to
 percent escape codes.
 @discussion
 If you want to convert a url string, you should NOT send this message to a receiver
 with format "http://www.xxx.com/page.x?arg1=1&arg2=2" directly. Because that
 percent escape codes are only used in url request arguments.
 */
- (NSString *)escapedURLString;
/*!
 @method originalURLString
 @result
 An autorelease NSString object with all escaped codes being converted to
 readable characters.
 @discussion
 DO NOT send this message to a receiver without escaped codes but within '%', such
 as "url%url". If you do this, you'll get an unexpected result.
 */
- (NSString *)originalURLString;
/*!
 @method
 @abstract URL转义
 @param escapesChars 忽略转义的符号
 @param encoding 指定字符编码格式
 @return 转义结果
 */
- (NSString*)encodedURLWithEscapes:(NSString*)escapesChars encoding:(NSStringEncoding)encoding;
/*!
 @method
 @abstract URL转义，默认为UTF-8编码
 @param escapesChars 忽略转义的符号
 @return 转义结果
 */
- (NSString*)encodedURLWithEscapes:(NSString*)escapesChars;
@end

@interface NSString (url)
/*!
 @method
 @abstract 将url字符串处理出参数列表
 @result 参数字典
 */
- (NSDictionary *)paramsOfUrl;
/*!
 @method
 @abstract 将一串&=的字符串转换为参数列表
 @result 参数字典
 */
- (NSDictionary*)paramsOfUrlParams;
/*!
 @method
 @abstract 将url字符串的中文进行转码
 @result 转码后的url字符串
 */
- (NSString*)escapesUTF8Url;
/*!
 @method
 @abstract 将url字符串追加get键值对参数
 @param value 值
 @param key 关键字
 @result 返回新url字符串
 */
- (NSString *)urlAppendValue:(NSString*)value key:(NSString*)key;
/*!
 @method
 @abstract 将url字符串追加多个get键值对参数
 @param dic 键值对字典
 @result 返回新url字符串
 */
- (NSString *)urlAppendKeyValues:(NSDictionary*)dic;

@end

@interface NSString (replace)
/*!
 @method
 @abstract 将字符串中出现的字符替换成目标字符
 @param chs 被替换的字符串
 @param target 目标字符串
 @result 返回替换后的字符串
 */
- (NSString*)replaceChars:(NSString*)chs targetChars:(NSString*)target;

@end


@interface NSArray (ext)
/*!
 @method
 @abstract 判断一个数组是否为空
 @discussion 如果数组为nil或者不是NSArray类型或者count <= 0则认为空
 @param arr 要做判断的数组
 @result 是否为空
 */
+ (BOOL)isEmpty:(NSArray*)arr;
/*!
 @method
 @abstract 安全访问数组成员对象
 @discussion 如果数组为空或索引越界，则返回nil。否则返回对应对象成员
 @param index 索引值
 @result nil或具体某个对象
 */
- (id)safeObjectAtIndex:(NSInteger)index;
/*!
 @method
 @abstract 第一个class类型的对象
 @discussion 如果不存在返回nil
 @param cls 对象类型
 @result nil或具体某个对象
 */
- (id)firstObjectOfClass:(Class)cls;
/*!
 @method
 @abstract 所有class类型的对象
 @discussion 如果不存在返回nil
 @param cls 对象类型
 @result nil或对应类型的对象数组
 */
- (NSArray*)objectsOfClass:(Class)cls;
@end

@interface NSDictionary (ext)
/*!
 @method
 @abstract 判断一个字典是否为空
 @discussion 如果字典为nil或者不是NSDictionary类型或者values、keys count <= 0则认为空
 @param arr 要做判断的数组
 @result 是否为空
 */
+ (BOOL)isEmpty:(NSDictionary*)dic;
/*!
 @method
 @abstract 从一个字典的key和非nil value中转出一串"key1=value1&key2=value2"形式的url参数串
 */
- (NSString*)urlParams;

@end

@interface NSMutableDictionary (ext)
/*!
 @method
 @abstract 往可变字典添加或设置一个键值对
 @discussion 如果键或值为空则添加失败，否则成功
 @param obj 值
 @param key 键名
 @result 是否成功添加字段到字典中
 */
- (BOOL)setValue:(id)value forKey:(NSString*)key;
@end


@interface NSNumber (money)
/*!
 @method
 @abstract 分转元格式
 @result 元为单位的金额
 */
- (NSInteger)fen2yuanValue;
@end


@interface NSString (path)
/*!
 @method
 @abstract 给出本地的文件名（文件名+扩展名）
 @result 返回指定本地文件名的完整路径名
 */
- (NSString *)mainBundlePath;
@end

@interface NSURL (format)
/*!
 @method
 @abstract 给url添加get键值对参数
 @param value 值
 @param key 关键字
 @result 返回新的url串
 */
- (NSURL *)urlAppendValue:(NSString*)value key:(NSString*)key;
/*!
 @method
 @abstract 将url串追加多个get键值对参数
 @param dic 键值对字典
 @result 返回新url串
 */
- (NSURL *)urlAppendKeyValues:(NSDictionary*)dic;
@end
