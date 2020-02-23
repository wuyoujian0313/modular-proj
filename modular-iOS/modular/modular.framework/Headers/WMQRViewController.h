//
//  WMQRViewController.h
//  modular
//
//  Created by wuyoujian on 16/5/13.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "WMBaseVC.h"


typedef NS_ENUM(NSInteger, WMQRCodeScanStatus) {
    WMQRCodeScanStatusSuccess,
    WMQRCodeScanStatusFail,
    WMQRCodeScanStatusCancel,
};

typedef void(^WMQRCodeFinishBlock)(NSString *result, WMQRCodeScanStatus status);

@interface WMQRViewController : WMBaseVC
- (void)setScanCallback:(WMQRCodeFinishBlock)callback;
@end
