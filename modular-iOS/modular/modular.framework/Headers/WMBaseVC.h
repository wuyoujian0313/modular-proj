//
//  WMBaseVC.h
//
//
//  Created by wuyj on 14-12-8.
//  Copyright (c) 2014年 WuYoujian. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, WMUpdateType) {
    WMUpdateTypeCompatibility = 1,
    WMUpdateTypeForce,
    WMUpdateTypeNotUpdate
};

@interface WMBaseVC : UIViewController

- (void)setContentViewBackgroundColor:(UIColor*)color;

- (void)setNavTitle:(NSString*)title;
- (void)setNavTitle:(NSString*)title titleColor:(UIColor *)color;

- (UIBarButtonItem*)configBackButton;


- (UIButton*)configRightBarButtonWithImage:(UIImage*)image selectImage:(UIImage*)selectIamge target:(id)target selector:(SEL)selector frame:(CGRect)frame;
- (UIButton*)configLeftBarButtonWithImage:(UIImage*)image selectImage:(UIImage*)selectIamge target:(id)target selector:(SEL)selector;

- (UIBarButtonItem*)configBarButtonWithTitle:(NSString*)title titleTextAttributes:(NSDictionary*)attrDic target:(id)target selector:(SEL)selector;

- (UIBarButtonItem*)configBarButtonWithTitle:(NSString*)title target:(id)target selector:(SEL)selector;

- (void)configRightBarButtonWithCustomView:(UIView*)aView;
- (void)configLeftBarButtonWithCustomView:(UIView*)aView;
- (void)configTitleWithImage:(NSString*)imagename;

- (void)popBack;

- (void)checkVersion:(NSString*)versionConfigUrl;

//- (void)checkVersion:(NSString *)versionURL callback:(CheckVersionCallback)callback;


#pragma mark - 子类是实现
- (void)regieditKeyboardNotification;
- (void)keyboardWillShow:(NSNotification *)note;
- (void)keyboardDidShow:(NSNotification *)note;
- (void)keyboardWillHide:(NSNotification *)note;
- (void)didEnterBackgroundNotification:(NSNotification *)note;

@end
