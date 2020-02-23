//
//  AIPluginLoader.h
//  CommonProject
//
//  Created by wuyoujian on 2017/6/19.
//
//

#import <Foundation/Foundation.h>
#import "WMNavigationController.h"
#import "WMCommonDef.h"

@protocol WMPluginProtocol <NSObject>
- (void)setPluginParam:(NSDictionary*_Nullable)params;
@end


typedef NS_ENUM(NSInteger,WMPluginLoadStatus) {
    
    WMPluginLoadStatusNone = 0,
    WMPluginLoadStatusUnDownload = 1,     // 没有下载
    WMPluginLoadStatusDownloading = 2,    // 下载中
    WMPluginLoadStatusDownloaded = 3,     // 下载完毕
    WMPluginLoadStatusException = 4,      // 加载异常
    
};

@interface WMPluginLoader : NSObject

WMSINGLETON_DEF(WMPluginLoader,SharedObj);

// 获取插件的状态
- (WMPluginLoadStatus)pluginloadStatus:(NSString*_Nonnull)pluginURL;

// 下载插件
- (void)downloadPlugin:(NSString*_Nonnull)pluginURL;

// 加载插件
- (void)loadPluginName:(NSString*_Nonnull)frameworkName
                   nav:(WMNavigationController*_Nonnull)navVC
      enterVCClassName:(NSString*_Nonnull)className;

// 加载插件
- (UIViewController<WMPluginProtocol> *_Nullable)loadPluginName:(NSString*_Nonnull)frameworkName enterVCClassName:(NSString*_Nonnull)className;

@end
