//
//  WMGlobalCfg.h
//  modular
//
//  Created by wuyoujian on 2017/6/13.
//
//

#import "WMAbstractCfg.h"
#import "WMCommonDef.h"

/*
 _CONFIG_FIELD_ONLINE_ADDR       = @"online.addr";
 _CONFIG_FIELD_VERSION           = @"version";
 _CONFIG_FIELD_VERSION_URL       = @"version.url";
 _CONFIG_FIELD_USERAGENT         = @"userAgent";
 _CONFIG_FIELD_ISCACHE_RES       = @"isCache.res";
 _CONFIG_FIELD_ISDEBUG           = @"isDebug";
 _CONFIG_FIELD_UPDATETYPE        = @"iOS.updateType";
 _CONFIG_FIELD_APP_NAME          = @"app.name";
 
 _CONFIG_FIELD_AES_KEY           = @"aes.key";
 _CONFIG_FIELD_AES_IV            = @"ase.iv";
 _CONFIG_FIELD_RSA_PUBLICKEY     = @"rsa.publicKey";
 */

@interface WMGlobalCfg : WMAbstractCfg

// 预置一些global.properties字段名称
@property(nonatomic,copy,readonly) NSString* _Nonnull  CONFIG_FIELD_ONLINE_ADDR;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_VERSION;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_VERSION_URL;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_USERAGENT;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_ISCACHE_RES;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_ISDEBUG;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_UPDATETYPE;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_RSA_PUBLICKEY;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_AES_IV;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_AES_KEY;
@property(nonatomic,copy,readonly) NSString* _Nullable CONFIG_FIELD_APP_NAME;


WMSINGLETON_CLASS_DEF(WMGlobalCfg,SharedObj);
- (NSString *_Nullable)attr:(NSString*_Nonnull)attr;
@end
