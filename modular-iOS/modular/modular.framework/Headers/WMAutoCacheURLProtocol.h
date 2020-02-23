//
//  WMAutoCacheURLProtocol.h
//  modular
//
//  Created by wuyoujian on 16/6/2.
//  Copyright © 2016年 WuYouJian. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WMAutoCacheURLProtocol : NSURLProtocol
+ (BOOL)registerProtocolWithIgnoreURLs:(NSArray*)ignores;
+ (void)unregisterCacheURLProtocol;
+ (void)setIgnoreURLs:(NSArray *)iURLs;
@end
