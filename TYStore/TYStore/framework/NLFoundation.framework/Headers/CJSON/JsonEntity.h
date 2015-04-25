//
//  JsonEntity.h
//  MiLe
//
//  Created by su on 13-10-12.
//  Copyright (c) 2013年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol JsonEntity <NSObject>
@optional
+ (NSDictionary*)keyFieldDictionary;
@optional
- (NSDictionary*)keyValueSerializerDictionary;
- (NSData*)toJsonData;
- (NSString*)toJsonString;
@optional
+ (NSDictionary*)keyClassDeserializerDictionary;
+ (id<JsonEntity>)fromJsonData:(NSData*)json;
+ (id<JsonEntity>)fromJsonDictionary:(NSDictionary*)jsonDict;
@end


@protocol ExtendJsonEntity <JsonEntity>

@end