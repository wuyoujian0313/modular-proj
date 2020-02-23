//
//  AICaptureView.h
//  modular
//
//  Created by wuyoujian on 16/7/31.
//  Copyright © 2016年 WuYouJian. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef void(^WMCaptureViewCallback)(UIImage *originImage,UIImage *croppedImage);

@interface WMCaptureView : UIView

+ (BOOL)checkAuthority;
- (void)photographWithCallback:(WMCaptureViewCallback)callback;
- (void)cropRectForInterest:(CGRect)cropRect;
- (void)startCapture;
@end
