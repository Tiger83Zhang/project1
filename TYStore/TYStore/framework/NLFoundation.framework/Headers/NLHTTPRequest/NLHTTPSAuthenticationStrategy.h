//
//  NLHTTPSAuthenticationStrategy.h
//  jsums
//
//  Created by su on 14-5-2.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import "NLHTTPRequest.h"

@interface NLHTTPSAuthenticationStrategy : NSObject<NLHTTPAuthenticationStrategy>
- (id)initWithDerFileName:(NSString*)der;
@end
