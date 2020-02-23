//
//  WMActionSheet.h
//  modular
//
//  Created by wuyoujian on 16/8/12.
//  Copyright © 2016年 WuYouJian. All rights reserved.
//

#import <UIKit/UIKit.h>


@class WMActionSheet ;
typedef void(^ WMActionSheetBlock )( WMActionSheet *actionSheet, NSInteger buttonIndex);

@protocol WMActionSheetDelegate <NSObject>
- (void)didSelectedActionSheet:(WMActionSheet *)actionSheet buttonIndex:(NSInteger)buttonIndex;
@end

@interface WMSheetItem : NSObject
@property (nonatomic, copy) NSString *title;
@property (nonatomic, copy) NSString *icon;
@property (nonatomic, copy) NSString *iconPath;
@end

@interface WMActionSheet : UIView
@property (nonatomic, readonly, assign) NSInteger cancelButtonIndex;

//
- (instancetype)initInParentView:(UIView*)parentView block:(WMActionSheetBlock )block;
- (instancetype)initInParentView:(UIView*)parentView delegate:(id <WMActionSheetDelegate >)delegate;
- (void)addActionItem:(WMSheetItem *)item;
- (void)clearAllItems;
- (void)show;


@end
