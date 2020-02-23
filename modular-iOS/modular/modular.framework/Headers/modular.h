//
//  modular.h
//  modular
//
//  Created by Wu YouJian on 2019/11/23.
//  Copyright © 2019 WuYouJian. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

//! Project version number for modular.
FOUNDATION_EXPORT double modularVersionNumber;

//! Project version string for modular.
FOUNDATION_EXPORT const unsigned char modularVersionString[];

#ifndef _WMMODULAR_
    #define _WMMODULAR_

    // CategoryKits
	#import "NSData+Crypto.h"
	#import "NSString+Utility.h"
    #import "UIAlertController+Orientations.h"
 	#import "UIColor+Utility.h"
	#import "UIImage+ResizeMagick.h"
    #import "UIImage+Utility.h"
    #import "UIView+SizeUtility.h"
    #import "NSDictionary+Utility.h"

	// WKWebViewKits
    #import "WMAbstractCfg.h"
	#import "WMGlobalCfg.h"
	#import "WMWKWebViewPluginCfg.h"
    #import "WMWKWebViewBasePlugin.h"
    #import "WMWebViewResInterceptor.h"
    #import "WMWKWebViewController.h"
	#import "WMWKWebViewBasePlugin.h"

	// CertificateCameraKits
	#import "WMCertificateCameraViewController.h"
	#import "WMCaptureView.h"

    // common
    #import "Reachability.h"
  	#import "RSA.h"
	#import "WMActionSheet.h"
	#import "WMAutoCacheURLProtocol.h"
	#import "WMBaseVC.h"
	#import "WMCaptchaControl.h"
	#import "WMCircleProgressButton.h"
	#import "WMCommonDef.h"
	#import "WMConfiguration.h"
	#import "WMCycleBannerView.h"
	#import "WMDeviceInfo.h"
	#import "WMDispatchTimer.h"
	#import "WMFadePromptView.h"
	#import "WMFileCache.h"
	#import "WMFileStreamOperation.h"
	#import "WMGesturePasswordManager.h"
	#import "WMGesturePasswordView.h"
	#import "WMGridMenuView.h"
	#import "WMImagePickerController.h"
	#import "WMLineView.h"
	#import "WMListenNetWorkingStatus.h"
	#import "WMLoadingView.h"
	#import "WMLocCacheURLProtocol.h"
	#import "WMMailSMSController.h"
	#import "WMNavigationController.h"
	#import "WMOpenDocumentController.h"
	#import "WMPasteboard.h"
	#import "WMSave2Keychain.h"
	#import "WMSignatureView.h"
	#import "WMUtils.h"

    // DynamicLibKits
	#import "WMPluginLoader.h"
	#import "WMPluginTools.h"

    // NetworkKits
	#import "WMNetwork.h"
    #import "WMBaseBean.h"

	// QRCodeKits
	#import "WMQRViewController.h"

    // minzip
    #import "minzip/ZipArchive.h"
    #import "minzip/ZipArchiveEx.h"

    // AFNeworking
    #import "AFNetworking/AFNetworking.h"

    // SDWebImage
    #import "SDWebImage/MKAnnotationView+WebCache.h"
    #import "SDWebImage/NSData+ImageContentType.h"
    #import "SDWebImage/SDImageCache.h"
    #import "SDWebImage/SDWebImageCompat.h"
    #import "SDWebImage/SDWebImageDecoder.h"
    #import "SDWebImage/SDWebImageDownloader.h"
    #import "SDWebImage/SDWebImageDownloaderOperation.h"
    #import "SDWebImage/SDWebImageManager.h"
    #import "SDWebImage/SDWebImageOperation.h"
    #import "SDWebImage/SDWebImagePrefetcher.h"
    #import "SDWebImage/UIButton+WebCache.h"
    #import "SDWebImage/UIImage+GIF.h"
    #import "SDWebImage/UIImage+MultiFormat.h"
    #import "SDWebImage/UIImage+WebP.h"
    #import "SDWebImage/UIImageView+HighlightedWebCache.h"
    #import "SDWebImage/UIImageView+WebCache.h"
    #import "SDWebImage/UIView+WebCacheOperation.h"

#endif /* _WMMODULAR_ */





