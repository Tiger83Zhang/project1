//
//  CJSONDeserializer+Extension.h
//  Lakala
//
//  Created by su on 13-3-6.
//  Copyright (c) 2013年 lakala.com. All rights reserved.
//

#import "CJSONDeserializer.h"

@interface CJSONDeserializer (Extension)

+ (CJSONDeserializer*)xNullDeserializer;
+ (id)deserialize:(NSData *)inData;

@end
