//
//  XLogging.h
//  XCocoaUtilsPublic
//
//  Created by Deheng Xu on 2019/1/6.
//  Copyright © 2019 Deheng.Xu. All rights reserved.
//

#ifndef XLogging_h
#define XLogging_h

#include <stdio.h>
#import <objc/runtime.h>

#ifdef cpusplus
extern "C" {
#endif

#pragma mark - Tag logging

#ifndef TagLogging
	#define TagLogging(TAG, fmt, ...) NSLog(@"<"#TAG"> "fmt, ##__VA_ARGS__)
#endif

#ifndef TagLoggingv
	#define TagLoggingv(TAG, fmt, args) NSLogv([NSString stringWithFormat:@"<"#TAG"> %@", fmt], args)
#endif

#ifndef DeclareNewLogPrefixAndTag
	#define DeclareNewLogPrefixAndTag(prefix, tag) extern void prefix##Log(NSString *fmt, ...) NS_FORMAT_FUNCTION(1,2) NS_NO_TAIL_CALL
#endif

#ifndef DeclareNewLogger
#define DeclareNewLogger(prefix) DeclareNewLogPrefixAndTag(prefix, prefix)
#endif

//#ifndef DefineNewLogger
//#define DefineNewLogger(prefix, tag) void prefix##Log(NSString *fmt, ...) {\
//va_list args; va_start(args, fmt); TagLoggingv(tag, fmt, args); va_end(args);\
//}
//#endif

#ifndef DefineNewLogger
#define DefineNewLogger(prefixAndTag) void prefixAndTag##Log(NSString *fmt, ...) {\
if ([log_##prefixAndTag respondsToSelector:@selector(isLoggingEnabled)] && ![log_##prefixAndTag isLoggingEnabled]) return;\
va_list args; va_start(args, fmt); TagLoggingv(prefixAndTag, fmt, args); va_end(args);\
}
#endif

#pragma mark - Logging module class

#ifndef SwiftDeclareLoggerWithTag
#define SwiftDeclareLoggerWithTag(Tag)\
@interface swiftlog_##Tag: NSObject @end;\
extern void Tag##LogSwift(NSString *logs);\
DeclareLoggingSwitcher(swiftlog_##Tag);
#endif

#ifndef SwiftDefineLoggerWithTag
#define SwiftDefineLoggerWithTag(prefixAndTag) \
void prefixAndTag##LogSwift(NSString *fmt) {\
if ([swiftlog_##prefixAndTag respondsToSelector:@selector(isLoggingEnabled)] && ![swiftlog_##prefixAndTag isLoggingEnabled]) return;\
NSLog(@"<"#prefixAndTag"> %@", fmt);\
}\
@implementation swiftlog_##prefixAndTag @end;\
DefineLoggingSwitcher(swiftlog_##prefixAndTag)
#endif



/** 声明模块类日志及开关 */
#ifndef DeclareLoggerWithTag
#define DeclareLoggerWithTag(Tag)\
@interface log_##Tag: NSObject @end;\
DeclareNewLogger(Tag);\
DeclareLoggingSwitcher(log_##Tag);
#endif

// Logger definition

/** 定义日志函数及开关 */
#ifndef DefineLoggerWithTag
#define DefineLoggerWithTag(prefixAndTag) \
DefineNewLogger(prefixAndTag);\
@implementation log_##prefixAndTag @end;\
DefineLoggingSwitcher(log_##prefixAndTag)
#endif

// Logging switcher
/** 声明日志开关*/
#ifndef DeclareLoggingSwitcher
#define DeclareLoggingSwitcher(ModuleClass)\
@interface ModuleClass (Logger)\
+ (BOOL)isLoggingEnabled;\
+ (void)setLoggingEnabled:(BOOL)isEnabled;\
@end
#endif

/** 定义日志开关*/
#ifndef DefineLoggingSwitcher
#define DefineLoggingSwitcher(ModuleClass) \
@implementation ModuleClass (Logger)\
+ (BOOL)isLoggingEnabled\
{\
char * const objKey = "is_logging_enabled";\
id islogging = objc_getAssociatedObject(self, objKey);\
if (!islogging) { return NO; }\
return [islogging boolValue];\
}\
\
+ (void)setLoggingEnabled:(BOOL)isEnabled\
{\
char * const objKey = "is_logging_enabled";\
objc_setAssociatedObject(self, objKey, @(isEnabled), OBJC_ASSOCIATION_ASSIGN);\
}\
@end
#endif

#ifdef cpusplus
}
#endif

#endif /* XLogging_h */
