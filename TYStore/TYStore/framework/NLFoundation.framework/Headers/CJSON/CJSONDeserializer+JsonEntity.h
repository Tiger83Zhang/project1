//
//  CJSONDeserializer+JsonEntity.h
//  shlakala
//
//  Created by su on 13-12-24.
//  Copyright (c) 2013年 suzw. All rights reserved.
//
#import "CJSONDeserializer.h"

@interface NSObject (JsonEntity)
+ (id)deserialize:(NSData *)inData;
+ (id)deserializeFromJson:(NSDictionary*)jsonDic;
@end