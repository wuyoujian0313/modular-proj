//
//  WMUtils.h
//  modular
//
//  Created by Wu YouJian on 2019/11/28.
//  Copyright © 2019 WuYouJian. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^WMTouchIDFinish)(NSError * _Nonnull error);

@interface WMUtils : NSObject
+ (void)telephoneToNumber:(NSString*)phoneNumber;
+ (void)telephone:(NSNotification*)notification;
+ (void)touchIDPolicy:(WMTouchIDFinish)finish;
@end

NS_ASSUME_NONNULL_END
