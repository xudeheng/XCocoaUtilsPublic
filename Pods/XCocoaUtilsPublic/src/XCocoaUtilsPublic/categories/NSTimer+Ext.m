//
//  NSTimer+Ext.m
//  XUtils
//
//  Created by Deheng.Xu on 13-6-19.
//
//

#import "NSTimer+Ext.h"
#import "FunctionSet.h"

@implementation NSTimer (Ext)

+ (void)cancelTimer:(NSTimer **)timer
{
    if ((*timer) != nil) {
        [(*timer) invalidate];
        SafeRelease(*timer);
    }
}

@end