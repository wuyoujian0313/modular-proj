//
//  WMWKWebViewExtendPlugin.m
//  modular
//
//  Created by Wu YouJian on 2019/7/5.
//  Copyright © 2019 AI. All rights reserved.
//

#import "WMWKWebViewExtendPlugin.h"


@implementation WMWKWebViewExtendPlugin

- (void)JN_TestMesage:(NSArray *)params {
    [WMFadePromptView showPromptStatus:@"测试接口" duration:2.0 finishBlock:^{
        //
    }];
}



@end
