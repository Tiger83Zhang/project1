//
//  NSObject+Runtime.h
//  shlakala
//
//  Created by su on 13-12-24.
//  Copyright (c) 2013年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSObject (Runtime)
/*!
 @method 取得当前对象的所有属性字段
 @abstract
 @result 所有属性名值对（key-name，value-value）
 */
- (NSDictionary*)properties;
/*!
 @method 取得当前对象(包含所有父类)的所有属性字段
 @abstract
 @result 所有属性名值对（key-name，value-value）
 */
- (NSDictionary*)allProperties;
/*!
 @method 取得当前对象对应class类型声明的所有属性字段
 @abstract
 @result 所有属性名值对（key-name，value-value）
 */
- (NSDictionary*)propertiesForClass:(Class)cls;
/*!
 @method 取得当前对象向上父类几个层级所声明的所有属性字段
 @abstract
 @param topLevel 从当前class向上数n个父类（包含自身）
 @result 所有属性名值对（key-name，value-value）
 */
- (NSDictionary*)propertiesWithSuper:(int)topLevel;
/*!
 @method 取得当前对象从某个父类class以下所有声明的所有属性字段
 @abstract
 @param extendClass 指定自顶向下的父类class
 @result 所有属性名值对（key-name，value-value）
 */
- (NSDictionary*)propertiesForExtendClass:(Class)extendClass;
/*!
 @method 取得当前类所有父类树形结构（自底向上）
 @abstract
 @return 所有父类class（含自身）
 */
+ (NSArray*)classesTreeBottomLayout;
/*!
 @method 取得当前类所有父类树形结构（自顶向下）
 @abstract
 @return 所有父类class（含自身）
 */
+ (NSArray*)classesTreeTopLayout;
/*!
 @method 取得当前对象的所有属性
 @abstract
 @result 所有属性名
 */
- (NSArray*)propertyNames;
/*!
 @method 取得当前对象的所有属性值
 @abstract
 @result 所有属性字段的值
 */
- (NSArray*)propertyValues;
/*!
 @method 获取某个类的所有属性
 @abstract
 @param cls 要查找的类
 @result 所有属性名
 */
+ (NSArray*)propertyNamesForClass:(Class)cls;
/*!
 @method 获取某个类的所有属性及类型
 @abstract 默认从NSObject开始，即获取所有的属性及类型
 @result 所有属性名和类型
 */
+(NSDictionary *)propertiesWithEncodedTypes;
/*!
 @method 获取从某个父类class以下所有声明的所有属性及类型
 @abstract
 @result 所有属性名和类型
 */
+(NSDictionary *)propertiesWithEncodedTypesForExtendClass:(Class)cls;
/*!
 @method 设置某个基本数据类型域的属性值
 @abstract
 @param name  域名
 @param value 属性值
 @result 是否设置成功
 */
- (BOOL)setField:(NSString*)name value:(void*)value;
/*!
 @method 获取类的类型编码
 @abstract
 @result 类型编码
 */
+ (NSString*)classEncodedType;
/*!
 @method 获取实例的类型编码
 @abstract
 @result 类型编码
 */
- (NSString*)instanceEncodedType;
/*!
 @method 获取容器-类的复合类型编码
 @abstract
 @result 容器下的复合类型编码
 */
+ (NSString*)complexClassEncodedType:(Class)container;

@end


@interface NSString (DecodedType)
extern NSString *const DecodedTypeNSObject;
extern NSString *const DecodedTypeNSString;
extern NSString *const DecodedTypeNSMutableString;
extern NSString *const DecodedTypeNSData;
extern NSString *const DecodedTypeNSMutableData;
extern NSString *const DecodedTypeNSArray;
extern NSString *const DecodedTypeNSMutableArray;
extern NSString *const DecodedTypeNSDictionary;
extern NSString *const DecodedTypeNSMutableDictionary;
extern NSString *const DecodedTypeNSSet;
extern NSString *const DecodedTypeNSMutableSet;
extern NSString *const DecodedTypeChar;
extern NSString *const DecodedTypeUnsignedChar;
extern NSString *const DecodedTypeInt;
extern NSString *const DecodedTypeUnsignedInt;
extern NSString *const DecodedTypeLong;
extern NSString *const DecodedTypeUnsignedLong;
extern NSString *const DecodedTypeLongLong;
extern NSString *const DecodedTypeUnsignedLongLong;
extern NSString *const DecodedTypeShort;
extern NSString *const DecodedTypeUnsignedShort;
extern NSString *const DecodedTypeBOOL;
extern NSString *const DecodedTypeFloat;
extern NSString *const DecodedTypeDouble;
#define Predicate_isCollectionType(x) (isNSSetType(x) || isNSArrayType(x) || isNSDictionaryType(x))
#define Predicate_isNSArrayType(x) ([x isEqualToString:DecodedTypeNSArray] || [x isEqualToString:DecodedTypeNSMutableArray])
#define Predicate_isNSDictionaryType(x) ([x isEqualToString:DecodedTypeNSDictionary] || [x isEqualToString:DecodedTypeNSMutableDictionary])
#define Predicate_isNSSetType(x) ([x isEqualToString:DecodedTypeNSSet] || [x isEqualToString:DecodedTypeNSMutableSet])

/*!
 @method 获取数据类型
 @abstract Runtime运行时数据类型简写，实际对应的可视类型名
 @result 类型名
 */
- (NSString*)decodedType;
/*!
 @method 获取数据类型
 @abstract Runtime运行时数据类型，实际对应的可用类型
 @result 类型
 */
- (Class)decodedClass;
/*!
 @method 是否OC对象类型
 @abstract 是否OC类型（NSObject所有子类）
 @result 是否OC类型
 */
- (BOOL)isDecodedTypeNSObject;
/*!
 @method 是否容器-OC复合类型
 @abstract 是否容器-OC复合类型（OC集合-NSObject所有子类类型）
 @result 是否复合类型
 */
- (BOOL)isDecodedTypeComplex;
/*!
 @method 获取容器-OC复合类型
 @abstract 第一个为元素类型，第二个为集合容器类型
 @result 复合类型
 */
- (NSArray*)complexDecodedTypes;

@end

FOUNDATION_EXPORT NSString *NSObjectClassEncodedType(Class cls);
FOUNDATION_EXPORT NSString *NSArrayClassEncodedType(Class cls);
