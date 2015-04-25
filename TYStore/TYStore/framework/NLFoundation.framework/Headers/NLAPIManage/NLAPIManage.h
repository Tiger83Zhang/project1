//
//  NLAPIManage.h
//  NLAPIManage
//
//  Created by su on 14-5-20.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifndef NL_API_REGISTER
//    #define NL_API_REGISTER NSAssert([NLAPIManage isApiValid], @"Newland application interfaces family is out of support !!!", @"%@", [NLAPIManage supportIdentifier]);
    #define NL_API_REGISTER [NLAPIManage assertTest];
#endif

#ifndef NL_API_CLASS_VALIDATOR
    #define NL_API_CLASS_VALIDATOR \
        + (void)load { \
            [NLAPIManage assertTest]; \
            [super load]; \
        }
#endif

/*!
 * VALIDATOR TEMPLATE
 *
+ (void)load {
    Class APIManageClass = NSClassFromString(@"NLAPIManage");
    [APIManageClass assertTest];
    [super load];
}
*/
#ifndef NL_API_STRINGCLASS_VALIDATOR
#define NL_API_STRINGCLASS_VALIDATOR \
    + (void)load { \
        Class APIManageClass = NSClassFromString(@"NLAPIManage"); \
        [APIManageClass assertTest]; \
        [super load]; \
    }
#endif

@interface NLAPIManage : NSObject
+ (BOOL)isApiValid;
+ (NSString*)supportIdentifier;
+ (void)assertTest;
+ (BOOL)registerApis;
@end
