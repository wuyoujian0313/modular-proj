//
//  WMWebViewPluginCfg.h
//  modular
//
//  Created by wuyoujian on 2017/6/13.
//
//

#import "WMAbstractCfg.h"
#import "WMCommonDef.h"

@interface WMWKWebViewPluginCfg : WMAbstractCfg

/*
 _CONFIG_FIND_PATH =     @"action";
 _CONFIG_ATTR_NAME =     @"name";
 _CONFIG_ATTR_CLASS =    @"class";
 */
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_FIND_PATH;
// 预置一些modular-plugin-iOS.xml字段名称

@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_NAME;
@property(nonatomic,copy,readonly) NSString* _Nonnull CONFIG_ATTR_CLASS;



WMSINGLETON_CLASS_DEF(WMWKWebViewPluginCfg,SharedObj);

- (NSDictionary *_Nullable)get:(NSString *_Nonnull)name;
- (NSString *_Nullable)attr:(NSString *_Nonnull)name attrName:(NSString*_Nonnull)attr;

@end
