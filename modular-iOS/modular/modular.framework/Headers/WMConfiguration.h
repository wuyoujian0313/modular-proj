//
//  WMConfiguration.h
//  modular
//
//  Created by wuyoujian on 16/8/2.
//  Copyright © 2016年 WuYouJian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMCommonDef.h"

/*
 专用于读取在mainBoundle里的properties的配置
 */
@interface WMConfiguration : NSObject
WMSINGLETON_DEF(WMConfiguration, sharedConfiguration)

// @param name 配置文件名
- (NSDictionary *_Nullable)configurationName:(NSString*_Nonnull)name;

// @param configData 配置文件数据
- (NSDictionary *_Nullable)configurationData:(NSData*_Nonnull)configData;

// @param configString 配置文件数据
- (NSDictionary *_Nullable)configurationString:(NSString*_Nonnull)configString;

@end
