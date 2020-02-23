//
//  WMWebViewResInterceptor.h
//  modular
//
//  Created by Wu YouJian on 2018/12/10.
//

#import <Foundation/Foundation.h>

// 拦截器的参数
@interface WMInterceptorParam: NSObject
@property(nonatomic,strong)NSArray      *cacheExtensions;
@property(nonatomic,assign)BOOL         forceCache;
@property(nonatomic,assign)NSInteger    connectTimeout;
@property(nonatomic,strong)NSString     *cachePath;
@property(nonatomic,strong)NSString     *aesEncryptKey;
@property(nonatomic,strong)NSString     *aesEncryptIV;
@property(nonatomic,assign)BOOL         isDebug;
// 过滤一些不需要拦截的URL，可以支持URL前缀形式，可以实现过滤一个域名的或者一个ip的
// 也可以精准匹配某一个url
@property(nonatomic,strong)NSArray      *ignoreUrls;
@end

@interface WMWebViewResInterceptor : NSURLProtocol
+ (void)registerInterceptor:(WMInterceptorParam *)builder;
+ (void)unregisterInterceptor;
+ (BOOL)clearCache;
@end




