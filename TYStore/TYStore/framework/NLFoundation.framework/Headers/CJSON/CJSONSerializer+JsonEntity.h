//
//  CJSONSerializer+JsonEntity.h
//  shlakala
//
//  Created by su on 13-12-24.
//  Copyright (c) 2013年 suzw. All rights reserved.
//

#import "CJSONSerializer.h"

@interface CJSONSerializer (Swizzing)

@end


@interface NSObject (JsonEntity)
- (NSData*)serializeJsonData;
- (NSString*)serializeJsonString;
@end
