//
//  WMCircleProgressButton.h
//  modular
//
//  Created by wuyoujian on 2017/7/8.
//  Copyright © 2017年 WuYouJian. All rights reserved.
//


#import <UIKit/UIKit.h>

typedef void(^WMCircleProgressBlock)(void);

@interface WMCircleProgressButton : UIButton

//轨迹的颜色
@property (nonatomic,strong)UIColor    *trackColor;

//沿着轨迹的进度颜色
@property (nonatomic,strong)UIColor    *progressColor;

//中间区域的背景颜色
@property (nonatomic,strong)UIColor    *fillColor;

//轨迹和进度的宽度
@property (nonatomic,assign)CGFloat    lineWidth;


- (void)startAnimationDuration:(CGFloat)duration withBlock:(WMCircleProgressBlock )block;

@end
