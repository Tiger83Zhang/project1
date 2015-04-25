//
//  NLLogger.h
//  MTypeSDK
//
//  Created by su on 13-6-27.
//  Copyright (c) 2013年 suzw. All rights reserved.
//

#ifndef MTypeSDK_NLLogger_h
#define MTypeSDK_NLLogger_h
#if !(DEBUG)
//    #define NSLog(s, ... )
#endif
// TODO
//#import <NLConsole/iConsole.h>
//#define NSLog(s, ... ) [iConsole nlog:[NSString stringWithFormat:(s), ##__VA_ARGS__]]
#define XLog(format, ...) NSLog((@"%s[Line %d]" format), __PRETTY_FUNCTION__, __LINE__, ##__VA_ARGS__)

#define NLCLog_debug(s, ... ) NSLog( @"DEBUG: <%@:(%d)> %@", [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] );
#define NLLogger_info(s, ... ) NSLog( @"INFO: <%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] );
#define NLLogger_debug(s, ... ) NSLog( @"DEBUG: <%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] );
#define NLLogger_warn(s, ... ) NSLog( @"WARN: <%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] );
#define NLLogger_exp(s, ... ) NSLog( @"EXP: <%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] );
#define NLLogger_error(s, ... ) NSLog( @"ERROR: <%p %@:(%d)> %@", self, [[NSString stringWithUTF8String:__FILE__] lastPathComponent], __LINE__, [NSString stringWithFormat:(s), ##__VA_ARGS__] );

#define lgf NSLog( @"log ------ %@:(%d) >> ", [[NSString stringWithUTF8String:__FUNCTION__] lastPathComponent], __LINE__);
#define NLLogger_UnImpl NSLog( @"WARN: not implement yet!!!TODO %@:(%d) >> ", [[NSString stringWithUTF8String:__FUNCTION__] lastPathComponent], __LINE__);
#endif
