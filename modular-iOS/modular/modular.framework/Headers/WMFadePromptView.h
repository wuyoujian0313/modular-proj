//
//  WMFadePromptView.h
//
//  Created by wuyj on 5/27/13.
//  Copyright (c) 2013 wuyj. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef void (^WMFinishPrompt)(void);

static  const CGFloat kFadePromptViewMaxWidth = 300;

@interface WMFadePromptView : UIView

+(void)showPromptStatus:(NSString*)status duration:(NSTimeInterval)seconds finishBlock:(WMFinishPrompt)finish;
+(void)showPromptStatus:(NSString*)status duration:(NSTimeInterval)seconds positionY:(CGFloat)y finishBlock:(WMFinishPrompt)finish;

@end


