//
//  WMMailSMSController.h
//  modular
//
//  Created by wuyoujian on 16/5/13.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MessageUI/MessageUI.h>
#import "WMCommonDef.h"


typedef NS_ENUM(NSInteger, WMSendStatus) {
    
    WMSendStatusSuccess,
    WMSendStatusFail,
    WMSendStatusSave,
    WMSendStatusCancel,
};

typedef NS_ENUM(NSInteger, WMSendType) {
    WMSendTypeMail,
    WMSendTypeSMS,
};

//
typedef void(^WMSendFinishBlock)(WMSendType type, WMSendStatus status);

@interface WMMailSMSController : NSObject<MFMessageComposeViewControllerDelegate,MFMailComposeViewControllerDelegate>

// 建议不用单例，建议把MailSMSController作为类一个strong成员变量
// 可以跟随使用的页面对象释放而释放
WMSINGLETON_DEF(WMMailSMSController, sharedMailSMSController)

/**
 *  邮件分享
 *  @param viewController 当前的VC，主要从哪个VC弹出邮件VC
 *  @param subject 邮件主题
 *  @param content 邮件内容
 */
- (void)pickerMailComposeViewController:(UIViewController*_Nonnull)viewController andRecipients:(NSArray*_Nonnull)recipients andSubject:(NSString*_Nonnull)subject andContent:(NSString*_Nonnull)content finish:(WMSendFinishBlock _Nonnull )finishBlock;

/**
 *  短信分享
 *
 *  @param viewController 当前的VC，主要从哪个VC弹出SMS VC
 *  @param content 短信内容
 */
- (void)pickerMessageComposeViewController:(UIViewController*_Nonnull)viewController andRecipients:(NSArray*_Nonnull)recipients andContent:(NSString*_Nonnull)content finish:(WMSendFinishBlock _Nonnull)finishBlock;

@end
