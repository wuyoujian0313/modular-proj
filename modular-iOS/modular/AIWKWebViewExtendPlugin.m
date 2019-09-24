//
//  AIWKWebViewExtendPlugin.m
//  mesop
//
//  Created by Wu YouJian on 2019/7/5.
//  Copyright © 2019 AI. All rights reserved.
//

#import "AIWKWebViewExtendPlugin.h"


@implementation AIWKWebViewExtendPlugin

- (NSString *)URLEncodedString:(NSString *)string {
    NSString *result = (NSString *)CFBridgingRelease(CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault, (CFStringRef )string,NULL, CFSTR("!*'();:@&=+$,/?%#[]"), kCFStringEncodingUTF8));
    return result;
}

- (void)JN_OpenOcrScanComp:(NSArray *)params {
    if (params != nil && [params count] > 6) {
        NSDictionary *dicData = @{ @"transactionID":params[0],
                                   @"billId":params[1],
                                   @"account":params[2],
                                   @"channelCode":params[3],
                                   @"provinceCode":params[4],
                                   @"signature":params[5],
                                   @"mode":@"3"
                                   };
        NSData *jsonDataa = [NSJSONSerialization dataWithJSONObject:dicData options:NSJSONWritingPrettyPrinted error:nil];
        
        NSString *jsonString = [[NSString alloc] initWithData:jsonDataa encoding:NSUTF8StringEncoding];
        jsonString = [self URLEncodedString:jsonString];
        NSString *scheme = @"IDENTITYAUTHENTICATION://";
        NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"%@%@",scheme ,jsonString]];
        [[UIApplication sharedApplication] openURL:url];
    }
    
    // 监听通知
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(receivePortalNotification:) name:@"toPlugin10085Notification" object:nil];
}

- (void)receivePortalNotification:(NSNotification *)notification {
    /*
     {
     address = "****";
     birthday = "****";
     id = ********;
     name = "****";
     period = "2009.06.22-2029.06.22";
     result = 1;
     resultCode = 1;
     sex = "\U7537";
     signer = "****";
     }
     
     String idCardJson = "{\"currScanPath\":\"0\",\"name\":\"崔新娟\",\"cardNo\":\"610121199501035124\",\"birth\":\"1995年01月03日\",\"signer\":\"xxxx分局\",\"address\":\"第三个地方个地方个地方规范\",\"gender\":\"1\",\"period\":\"2016.01.19-长期..\",\"nation\":\"汉\",\"TRANSACTION_ID\": \"123123123123\"}";
     
     */
    
    NSDictionary *param = [notification object];
    if (param == nil && [param count] == 0) {
        dispatch_async(dispatch_get_main_queue(), ^{
            [self callback:@"JN_OpenOcrScanComp" param:@"fail"];
        });
        return;
    }
    
    NSArray *allKeys = [param allKeys];
    NSString *paramJson = @"{";
    for (int i = 0; i < [allKeys count]; i ++) {
        NSString *key = [allKeys objectAtIndex:i];
        NSString *value = [param objectForKey:key];
        if ([key isEqualToString:@"id"]) {
            paramJson = [paramJson stringByAppendingFormat:@"\"cardNo\":\"%@\"",value];
        } else if ([key isEqualToString:@"result"] || [key isEqualToString:@"resultCode"]) {
            continue;
        } else {
            paramJson = [paramJson stringByAppendingFormat:@"\"%@\":\"%@\"",key,value];
        }
        
        if (i != [allKeys count] - 1) {
            paramJson = [paramJson stringByAppendingString:@","];
        } else {
            paramJson = [paramJson stringByAppendingString:@"}"];
        }
    }
    
    if ([paramJson length] > 0) {
        dispatch_async(dispatch_get_main_queue(), ^{
             [self callback:@"JN_OpenOcrScanComp" param:paramJson];
        });
    }
}



@end
