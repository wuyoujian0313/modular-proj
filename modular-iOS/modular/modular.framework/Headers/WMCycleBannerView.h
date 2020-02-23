//
//  WMCycleBannerView.h
//  modular
//
//  Created by wuyj on 16/2/27.
//  Copyright © 2016年 wuyj. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol WMCycleBannerViewDelegate <NSObject>

- (void)didSelectedBannerIndex:(NSInteger)index;

@end

typedef NS_ENUM(NSUInteger, WMPageControlPosition) {
    WMPageControlPositionLeft,
    WMPageControlPositionCenter,
    WMPageControlPositionRight
};

@interface WMCycleBannerView : UIView
@property(nonatomic, weak) id <WMCycleBannerViewDelegate> delegate;
@property(nonatomic, strong, readonly) UIPageControl *pageControl;
@property(nonatomic, assign) NSUInteger interval;
@property(nonatomic, assign) WMPageControlPosition pageControlPos;


- (instancetype)initWithFrame:(CGRect)frame;
- (void)reloadData:(NSArray<NSString*> *)imageURLs;

- (void)stopScroll;
- (void)autoScroll;

- (void)scrollToIndex:(NSInteger)index animated:(BOOL)animated;

@end
