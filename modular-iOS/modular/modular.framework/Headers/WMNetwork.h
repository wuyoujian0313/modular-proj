//
//  NetworkTask.h
//  CommonProject
//
//  Created by wuyoujian on 16/7/4.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WMCommonDef.h"




typedef NS_ENUM(NSInteger, WMNetworkStatusCode) {
    WMNetworkStatusCodeSuccess = 1,
    WMNetworkStatusCodeUnknown,
};

#define WMNetworkStatusCodeSuc(status)    (status == WMNetworkStatusCodeSuccess)
#define WMNetworkStatusCodeFail(status)   (status != WMNetworkStatusCodeSuccess)

@interface WMUploadFileInfo : NSObject
@property(nonatomic,copy) NSString      * _Nonnull fileName;
@property(nonatomic,copy) NSString      * _Nonnull mimeType;
@property(nonatomic,strong) NSData      * _Nonnull fileData;
@property(nonatomic,copy) NSString      * _Nonnull fileKey;
@end


@class WMBaseBean;
@class AFHTTPSessionManager;
@protocol WMNetworkDelegate <NSObject>

@optional
-(void)networkSuccessBack:(WMBaseBean *_Nonnull)result forInfo:(id _Nonnull )customInfo;
-(void)networkFailBack:(NSString *_Nonnull)errorDesc errorCode:(NSInteger)errorCode forInfo:(id _Nonnull )customInfo;

@end

@interface WMNetwork : NSObject

@property(nonatomic, assign) NSTimeInterval                 taskTimeout;
@property(nonatomic, copy) NSString                         * _Nonnull serverAddress;
@property(nonatomic, strong,readonly)AFHTTPSessionManager   * _Nonnull afManager;

WMSINGLETON_DEF(WMNetwork, sharedNetwork)

+(NSString *_Nonnull)errerDescription:(NSInteger)statusCode;

// upload File 带上传文件的
- (void)startUploadTaskApi:(NSString*_Nonnull)api
                  forParam:(NSDictionary *_Nonnull)param
                  fileData:(NSData*_Nonnull)fileData
                   fileKey:(NSString*_Nonnull)fileKey
                  fileName:(NSString*_Nonnull)fileName
                  mimeType:(NSString*_Nonnull)mimeType
                  delegate:(id <WMNetworkDelegate>_Nonnull)delegate
                 resultObj:(WMBaseBean*_Nonnull)resultObj
                customInfo:(id _Nonnull)customInfo;

- (void)startUploadTaskApi:(NSString*_Nonnull)api
                  forParam:(NSDictionary *_Nonnull)param
                  filePath:(NSString*_Nonnull)filePath
                   fileKey:(NSString*_Nonnull)fileKey
                  fileName:(NSString*_Nonnull)fileName
                  mimeType:(NSString*_Nonnull)mimeType
                  delegate:(id <WMNetworkDelegate>_Nonnull)delegate
                 resultObj:(WMBaseBean*_Nonnull)resultObj
                customInfo:(id _Nonnull)customInfo;

- (void)startUploadTaskApi:(NSString*_Nonnull)api
                  forParam:(NSDictionary *_Nonnull)param
                     files:(NSArray<WMUploadFileInfo*>*_Nonnull)files
                  delegate:(id <WMNetworkDelegate>_Nonnull)delegate
                 resultObj:(WMBaseBean*_Nonnull)resultObj
                customInfo:(id _Nonnull)customInfo;

// GET
- (void)startGETTaskURL:(NSString*_Nonnull)urlString
               delegate:(id <WMNetworkDelegate>_Nonnull)delegate
              resultObj:(WMBaseBean*_Nonnull)resultObj
             customInfo:(id _Nonnull)customInfo;

- (void)startGETTaskApi:(NSString*_Nonnull)api
               forParam:(NSDictionary *_Nonnull)param
               delegate:(id <WMNetworkDelegate>_Nonnull)delegate
              resultObj:(WMBaseBean*_Nonnull)resultObj
             customInfo:(id _Nonnull)customInfo;

// POST
- (void)startPOSTTaskApi:(NSString*_Nonnull)api
                forParam:(NSDictionary *_Nonnull)param
                delegate:(id <WMNetworkDelegate>_Nonnull)delegate
               resultObj:(WMBaseBean*_Nonnull)resultObj
              customInfo:(id _Nonnull)customInfo;

// PUT
- (void)startPUTTaskApi:(NSString*_Nonnull)api
               forParam:(NSDictionary *_Nonnull)param
               delegate:(id <WMNetworkDelegate>_Nonnull)delegate
              resultObj:(WMBaseBean*_Nonnull)resultObj
             customInfo:(id _Nonnull)customInfo;

// DELETE
- (void)startDELETETaskApi:(NSString*_Nonnull)api
                  forParam:(NSDictionary *_Nonnull)param
                  delegate:(id <WMNetworkDelegate>_Nonnull)delegate
                 resultObj:(WMBaseBean*_Nonnull)resultObj
                customInfo:(id _Nonnull )customInfo;

@end
