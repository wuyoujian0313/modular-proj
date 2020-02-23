//
//  WMAbstractCfg.h
//  modular
//
//  Created by wuyoujian on 2017/6/13.
//  Copyright © 2017年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>

//
@protocol WMWebViewPluginConfigProtocol <NSObject>
// 子类实现,解析configData数据
- (void)loadConfig;
// 配置的主键值
- (NSArray *)getNames;
@end

@interface WMAbstractCfg : NSObject<WMWebViewPluginConfigProtocol>
@property(nonatomic,strong,readonly) NSData  *configData;

// 解析数据
- (void)parseConfigByData:(NSData *)configData element:(NSString *)elementName attrKey:(NSString*)key;

// 解析数据
- (void)parseConfigByFile:(NSString *)configFile element:(NSString *)elementName attrKey:(NSString*)key;
- (NSDictionary *)getAll;

// help APIs
- (void)parseXMLConfigData:(NSData*)data element:(NSString *)elementName;
- (void)parseGlobalConfigData:(NSData*)data;

@end
