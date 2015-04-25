//
//  macros.h
//  jsums
//
//  Created by su on 13-11-28.
//  Copyright (c) 2013年 suzw. All rights reserved.
//

#ifndef jsums_macros_h
#define jsums_macros_h

#define INTF_SHARED_INSTANCE + (id)sharedInstance;

#define IMPL_SHARED_INSTANCE \
+ (id)sharedInstance \
{ \
    static dispatch_once_t once; \
    static id instance = nil; \
    dispatch_once( &once, ^{ instance = [[self alloc] init]; } ); \
    return instance; \
}

#define MAIN_ASYNC(block) \
    dispatch_async(dispatch_get_main_queue(), block);
#define GCD_CURRENT dispatch_get_current_queue()

#ifndef GENERATE_CODE_EMPTY_IMPL
    #define GENERATE_CODE_EMPTY_IMPL(x) @implementation x @end
#endif

#define CString(s, ... ) [NSString stringWithFormat:s, ##__VA_ARGS__]

#ifndef G_DEPRECATED_API
    #ifdef __clang__
        #define G_DEPRECATED_API __attribute__ ((deprecated("No longer required.")))
    #else
        #define G_DEPRECATED_API __attribute__ ((deprecated()))
    #endif
#endif

#define NSHTTPDefaultStringEncoding CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingGB_18030_2000)

#define NSGB2312StringEncoding CFStringConvertEncodingToNSStringEncoding(kCFStringEncodingHZ_GB_2312)

#define NLStringSelector(method) NSStringFromSelector(@selector(method))
#define NLAttribute(att) NSStringFromSelector(@selector(att))

#define MainPerform(target,action,object) [target performSelectorOnMainThread:action withObject:object waitUntilDone:NO]
#define MainIfPerform(target,action,object) if (target && [target respondsToSelector:action]) {MainPerform(target,action,object);}

#ifndef iPhone5
#define iPhone5 ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(640, 1136), [[UIScreen mainScreen] currentMode].size)) || (CGSizeEqualToSize(CGSizeMake(320,568), [[UIScreen mainScreen] currentMode].size)) : NO)
// #define iPhone5 ( fabs( ( double )[ [ UIScreen mainScreen ] bounds ].size.height - ( double )568 ) < DBL_EPSILON )
#endif

/*--iphone4/iphone4s xib use---*/
#ifndef iPhone4S
#define iPhone4S ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? (CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size)) || (CGSizeEqualToSize(CGSizeMake(320,480), [[UIScreen mainScreen] currentMode].size)) : NO)
#endif
/*--iphone4/iphone4s xib use---*/
#define XIBUSE(s) iPhone4S ?  s : [NSString stringWithFormat:@"%@_iphone5",s]
#define RECEIBVABLE_CHANGE_AMOUNT_VIEW_TAG 987654

#define UITextFieldTintColor [UIColor colorWithRed:147.0 / 255.0 green:149.0 / 255.0 blue:150.0 / 255.0 alpha:1]

#define CCB_rgb(r,g,b) [UIColor colorWithRed:r/255.0 green:g/255.0 blue:b/255.0 alpha:1.0]
#define CCB_COLORSTRING(s) [UIColor colorWithRed:(float)[NLISOUtils intWithHexString:[s substringWithRange:NSMakeRange(0, 2)]]/255.0 green:(float)[NLISOUtils intWithHexString:[s substringWithRange:NSMakeRange(0, 2)]]/255.0 blue:(float)[NLISOUtils intWithHexString:[s substringWithRange:NSMakeRange(0, 2)]]/255.0 alpha:1.0]

#define G_DEVICE_IOS7 [[[UIDevice currentDevice]systemVersion] floatValue] >= 7.0

#define G_DATE_FORMAT(doubleValue) [[NSDate dateWithTimeIntervalSince1970:doubleValue / 1000.0f] dateFormateString:NSDateFormatStandardFull]

#define G_HIDDEN_KEYBOARD [[[UIApplication sharedApplication] keyWindow] endEditing:YES];

#define G_TOAST_SHOW [MBProgressHUD show];
#define G_TOAST_PROMPT(text) [MBProgressHUD prompt:text];
#define G_TOAST_HIDE [MBProgressHUD hide];

#define lgf NSLog( @"log ------ %@:(%d) >> ", [[NSString stringWithUTF8String:__FUNCTION__] lastPathComponent], __LINE__);
#define NSLogT(s, ... ) NSLog(@">>>>>>>>>>>>>>>>>>>>>>>>>>>> %@", [NSString stringWithFormat:(s), ##__VA_ARGS__]);
#endif

#define GET_IMAGE_RESOURCE(NSSTR_RESOURCE_NAME,NSSTR_RESOURCE_TYPE) ([UIImage imageWithContentsOfFile:[[NSBundle mainBundle] pathForResource:NSSTR_RESOURCE_NAME ofType:NSSTR_RESOURCE_TYPE]])

#define PI 3.14159265358979323846

#define ESIGNDIR(s) [[NSString stringWithFormat:@"%@/Library/Cache/Images/%@",NSHomeDirectory(),s] appSubDir]

#define CUSTOMPHOTO(s) [NSString stringWithFormat:@"%@/Images/%@",[NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0],s]

#define DATA_DIR [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) objectAtIndex:0]
