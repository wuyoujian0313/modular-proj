//
//  WMBaseBean.h
//
//
//  Created by wuyj on 14-9-2.
//  Copyright (c) 2014年 wuyj. All rights reserved.
//

#import <Foundation/Foundation.h>

#define WMParserArray(key,type)    key##__Array__##type

@interface WMBaseBean : NSObject<NSCopying>

@property (nonatomic, copy)NSNumber     *code;                    // 返回代码
@property (nonatomic, copy)NSString     *message;                 // 返回描述


// 自动解析Json
// ！！！！！！目前仅支持整个报文解析成字典类型
- (void)autoParseJsonData:(NSData*)result;
- (void)parseNetResult:(NSDictionary *)jsonDictionary;


@end
