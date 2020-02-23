//
//  NSDictionary.h
//  modular
//
//  Created by Wu YouJian on 2019/12/6.
//  Copyright © 2019 WuYouJian. All rights reserved.
//

#import <Foundation/Foundation.h>


@interface NSDictionary(Utility)
- (NSString *)toJSONString;
- (NSDictionary *)toDictionary:(NSString *)JSONString;
@end

