//
//  XOperationTemplate.h
//  FeedLibrary
//
//  NSOperation implementation template.
//  Implement operation statue attribution.
//  Implement statue notify.
//
//  Created by Deheng.Xu on 13-3-28.
//  Copyright (c) 2013年 Nicholas.Xu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface XOperationTemplate : NSOperation
{

@protected
    BOOL _isConcurrent;
    BOOL _isReady;
    BOOL _isCanceled;
    BOOL _isFinished;
    BOOL _isExecuting;
}

- (void)makeReady:(BOOL)value;
- (void)makeExecuting:(BOOL)value;
- (void)makeCanceled:(BOOL)value;
- (void)makeFinished:(BOOL)value;

- (void)makeKVOValueForKey:(NSDictionary *)valueAndKey;

@end