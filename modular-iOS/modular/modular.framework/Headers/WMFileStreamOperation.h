//
//  WMFileStreamOperation.h
//  modular
//
//  Created by wuyoujian on 16/7/6.
//  Copyright © 2016年 wuyoujian. All rights reserved.
//

#import <Foundation/Foundation.h>

#define kFileFragmentMaxSize         1024 * 512 // 512k


@class WMFileFragment;

/**
 *  文件流操作类, 支持保存到NSUserdefault中（需要采用NSKeyedArchiver方式固化到NSUserdefault）
 */
@interface WMFileStreamOperation : NSObject<NSCoding>
@property (nonatomic, readonly, copy) NSString *fileName;// 包括文件后缀名的文件名
@property (nonatomic, readonly, assign) NSUInteger fileSize;// 文件大小
@property (nonatomic, readonly, copy) NSString *filePath;// 文件所在的文件目录
@property (nonatomic, readonly, strong) NSArray<WMFileFragment*> *fileFragments;// 文件分片数组

// 若为读取文件数据，打开一个已存在的文件。
// 若为写入文件数据，如果文件不存在，会创建的新的空文件。
- (instancetype)initFileOperationAtPath:(NSString*)path forReadOperation:(BOOL)isReadOperation;

// 获取当前偏移量
- (NSUInteger)offsetInFile;

// 设置偏移量, 仅对读取设置
- (void)seekToFileOffset:(NSUInteger)offset;

// 将偏移量定位到文件的末尾
- (NSUInteger)seekToEndOfFile;

// 关闭文件
- (void)closeFile;

#pragma mark - 读操作
// 通过分片信息读取对应的片数据
- (NSData*)readDateOfFragment:(WMFileFragment*)fragment;

// 从当前文件偏移量开始
- (NSData*)readDataOfLength:(NSUInteger)bytes;

// 从当前文件偏移量开始
- (NSData*)readDataToEndOfFile;

#pragma mark - 写操作
// 写入文件数据
- (void)writeData:(NSData *)data;

@end

// 上传文件片
@interface WMFileFragment : NSObject<NSCoding>
@property (nonatomic,copy)NSString          *fragmentId;    // 片的唯一标识
@property (nonatomic,assign)NSUInteger      fragmentSize;   // 片的大小
@property (nonatomic,assign)NSUInteger      fragmentOffset;// 片的偏移量
@property (nonatomic,assign)BOOL            fragmentStatus; // 上传状态 YES上传成功
@end
