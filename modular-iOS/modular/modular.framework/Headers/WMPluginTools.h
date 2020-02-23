//
//  WMPluginTools.h
//  modular
//
//  Created by wuyoujian on 2017/6/21.
//  Copyright © 2017年 WuYouJian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "WMCommonDef.h"

@interface WMPluginTools : NSObject

WMSINGLETON_DEF(WMPluginTools,SharedObj);

// 从framework根目录下加载图片
- (UIImage *_Nullable)roadImageWithName:(NSString *_Nonnull)name;

// 从framework根目录下的包名：@param bunleName 中加载图片，例如，res.bundle
- (UIImage *_Nullable)roadImageWithName:(NSString *_Nonnull)name inResBundle:(NSString*_Nonnull)bundleName;

// 从矢量图加载图片
- (UIImage *_Nullable)roadVectorImageWithName:(NSString *_Nonnull)name;

// 从framework根目录下加载其他资源
- (NSData *_Nullable)roadResWithName:(NSString*_Nonnull)name;

// 从framework根目录下的包名：@param bunleName 中加载其他资源，例如，res.bundle
- (NSData *_Nullable)roadResWithName:(NSString*_Nonnull)name inResBundle:(NSString *_Nonnull)bundleName;

// 返回资源路径
- (NSString *_Nullable)resPathWithName:(NSString*_Nonnull)name;

// 返回资源路径
- (NSString *_Nullable)resPathWithName:(NSString*_Nonnull)name inResBundle:(NSString *_Nonnull)bundleName;


@end
