//
//  NSData+XCUPCompress.h
//  XCocoaUtilsPublic
//
//  Created by Deheng Xu on 2020/1/30.
//  Copyright © 2020 Deheng.Xu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <zlib.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSData (XCUPGzip)

- (NSData *)xcup_gzipDataError:(NSError **)error;
- (NSData *)xcup_ungzipDataError:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
