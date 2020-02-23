//
//  WMDispatchTimer.h
//  modular
//
//  Created by wuyj on 16/2/18.
//  Copyright © 2016年 WuYouJian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMCommonDef.h"


@protocol WMDispatchTimerDelegate <NSObject>
- (void)dispatchTimerTask;
@end

typedef void (^WMDispatchTimerBlock)(void);

/*
 采用GCD实现timer，这个实现不会出现timer不释放的问题；
 */
@interface WMDispatchTimer : NSObject

WMSINGLETON_DEF(WMDispatchTimer, sharedDispatchTimer)

// 采用代理的方式,建议采用这种方式
- (void)createDispatchTimerInterval:(NSUInteger)interval delegate:(id <WMDispatchTimerDelegate>_Nonnull)delegate repeats:(BOOL)yesOrNo;

/* !!!!!! 采用block 的方式，一定要注意block retain self的问题
 
 类似这样使用：
 __weak CycleScrollView *wself = self;
 [[DispatchTimer sharedDispatchTimer] createDispatchTimerInterval:_interval block:^{
 CycleScrollView *sself = wself;
 
 [sself autoJumpPage];
 } repeats:YES];
 */

- (void)createDispatchTimerInterval:(NSUInteger)interval block:(WMDispatchTimerBlock _Nonnull )timerBlock repeats:(BOOL)yesOrNo;

// 停止循环执行的timer
- (void)invalidate;

@end
