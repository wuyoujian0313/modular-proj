//
//  WMImagePickerController.h
//  modular
//
//  Created by wuyoujian on 16/5/13.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMCommonDef.h"

typedef NS_ENUM(NSInteger, WMImagePickerStatus) {
    WMImagePickerStatusSuccess,
    WMImagePickerStatusFail,
    WMImagePickerStatusCancel,
};

typedef NS_ENUM(NSInteger, WMImagePickerType) {
    WMImagePickerTypeUnknow,
    WMImagePickerTypeImage,
    WMImagePickerTypePhotograph,
    WMImagePickerTypeVideotape,
    WMImagePickerTypeScanQRCode,
};

// 注意！！！！！
// type==ImagePickerTypeVideotape,data是video的URL
typedef void(^WMImagePickerFinishBlock)(WMImagePickerType type, WMImagePickerStatus status, id _Nullable data);

@interface WMImagePickerController : NSObject

// 建议不用单例，建议把ImagePickerController作为类一个strong成员变量
// 可以跟随使用的页面对象释放而释放
WMSINGLETON_DEF(WMImagePickerController, sharedImagePickerController)
// 拍照和选择图片是否支持编辑
@property (nonatomic, assign) BOOL allowsEditing;

/**
 *  照片选择
 *  @param picker 当前的VC，主要从哪个VC弹出邮件VC
 */
- (void)pickerImageController:(UIViewController*_Nonnull)picker finish:(WMImagePickerFinishBlock _Nonnull )finishBlock;

/**
 *  调用摄像头拍照
 *  @param picker 当前的VC，主要从哪个VC弹出邮件VC
 */
- (void)pickerPhotographController:(UIViewController*_Nonnull)picker finish:(WMImagePickerFinishBlock _Nonnull )finishBlock;

/**
 *  调用摄像头录像
 *  @param picker 当前的VC，主要从哪个VC弹出邮件VC
 */
- (void)pickerVideotapeController:(UIViewController*_Nonnull)picker finish:(WMImagePickerFinishBlock _Nonnull )finishBlock;

/**
 *  二维码识别
 *  @param picker 当前的VC，主要从哪个VC弹出邮件VC
 */
- (void)pickerQRCodeController:(UIViewController*_Nonnull)picker finish:(WMImagePickerFinishBlock _Nonnull )finishBlock;

@end
