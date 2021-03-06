//
//  UIViewController+Utils.h
//  MKTest
//
//  Created by Deheng.Xu on 12-11-5.
//  Copyright (c) 2012年 Deheng.Xu. All rights reserved.
//

#if TARGET_OS_IPHONE

#import <UIKit/UIKit.h>

/* Fix: Implicit declaration of method 'osVersion' in C99 */
//#import "UIDevice+Ext.h"

#define VIEW_DID_UNLOAD_FUNCTION()   do{\
if ([[[UIDevice currentDevice] systemVersion] floatValue] < 6.0) {\
if ([self isViewLoaded] && ![[self view] window]) {\
[self viewDidUnload];\
}\
}\
}\
while(0)

@interface UIViewController (XCUP)

+ (NSString *)xibFileNameDefaultSuffix;
+ (instancetype)viewControllerWithNibName:(NSString *)nibName bundle:(NSBundle *)nibBundleOrNil;

- (BOOL)isSupportInteractivePopGestureRecognizer;

- (UINavigationController*)xc_navigationController;

- (instancetype)xc_present:(UIViewController*)presentedViewController animated:(BOOL)animated needNavigation:(BOOL)needed completion:(void(^)(void))completion;
- (instancetype)xc_present:(UIViewController*)presentedViewController animated:(BOOL)animated completion:(void(^)(void))completion;
- (instancetype)xc_dismissViewController:(BOOL)animated completion:(void(^)(void))completion;

@end

#endif
