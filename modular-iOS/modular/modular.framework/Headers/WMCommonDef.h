//
//  WMCommonDef.h
//  modular
//
//  Created by wuyoujian on 16/9/1.
//  Copyright © 2016年 WuYouJian. All rights reserved.
//

#ifndef WMCommonDef_h
#define WMCommonDef_h

// 定义单例方法，有些类是允许非单例模式的
#ifndef _WMSINGLETON_API_
#define _WMSINGLETON_API_

#define WMSINGLETON_DEF(type,APIName)       + ( type * _Nonnull) APIName;
#define WMSINGLETON_IMP(type,APIName)       \
+ ( type * _Nonnull) APIName {              \
    static type *obj = nil;                 \
    static dispatch_once_t onceToken;       \
    dispatch_once(&onceToken, ^{            \
        obj = [[self alloc] init];          \
    });                                     \
    return obj;                             \
}
#endif // _WMSINGLETON_API_

// 定义单例类
#ifndef _WMSINGLETON_CLASS_
#define _WMSINGLETON_CLASS_

#define WMSINGLETON_CLASS_DEF(type,APIName)             + ( type * _Nonnull) APIName;
#define WMSINGLETON_CLASS_IMP(type,APIName)             \
+ ( type * _Nonnull) APIName {                          \
    static type *obj = nil;                             \
    static dispatch_once_t onceToken;                   \
    dispatch_once(&onceToken, ^{                        \
        obj = [[super allocWithZone:NULL] init];        \
    });                                                 \
    return obj;                                         \
}                                                       \
                                                        \
+ (instancetype)allocWithZone:(struct _NSZone * _Nonnull)zone {  \
    return [self APIName ];                             \
}                                                       \
                                                        \
- (instancetype)copy{                                   \
    return [[self class] APIName ];                     \
}
#endif // _WMSINGLETON_CLASS_



#endif /* WMCommonDef_h */
