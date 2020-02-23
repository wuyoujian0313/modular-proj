//
//  WMListenNetWorkingStatus.h
//  modular
//
//  Created by Wu YouJian on 2018/11/20.
//

#import <Foundation/Foundation.h>
#import "WMCommonDef.h"

NS_ASSUME_NONNULL_BEGIN

@interface WMListenNetWorkingStatus : NSObject

WMSINGLETON_CLASS_DEF(WMListenNetWorkingStatus, sharedNetListener)
- (void)listen;
@end

NS_ASSUME_NONNULL_END
