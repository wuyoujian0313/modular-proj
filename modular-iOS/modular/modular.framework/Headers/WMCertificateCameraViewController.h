//
//  WMCertificateCameraViewController.h
//  modular
//
//  Created by Wu YouJian on 2018/10/24.
//  Copyright © 2018年 WuYouJian. All rights reserved.
//

#import "WMBaseVC.h"


typedef void(^WMTakeFinishCallback)(UIImage *croppedImage);

@interface WMCertificateCameraViewController : WMBaseVC
- (void)setTakeCallback:(WMTakeFinishCallback)callback;
@end

