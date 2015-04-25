//
//  AsyncCache.h
//  Lakala
//
//  Created by su on 12-11-23.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

extern NSString *const AppImageCacheDirName;

@interface NSString (LocalCache)
/*!
 @method 取得沙盒图片缓存目录
 @abstract 不存在本地图片缓存目录则创建，并返回该目录路径
 @discussion
 @result 当前应用沙盒目录下ImageCache目录路径
 */
+ (NSString *)localCacheImageDir;
- (NSString*)localCacheImagePath;
- (NSData*)localCacheImageData;

@end


typedef  void (^CacheBlock)(NSData *data);
@interface NSURL (AsyncOrCache)
/**
 * 将指定url下载缓存到指定沙盒dir子目录下，以name作为文件名保存。如果已经有缓存，则返回NO，否则返回YES。
 * block处理缓存或者下载下来的NSData
 */
- (BOOL)cacheQueueDownloadWithSaveName:(NSString*)name inAppSubDir:(NSString*)dir isCurrentQueue:(BOOL)yn block:(CacheBlock)block;
/**
 * 将指定url的内容下载下来，为data形式
 */
- (void)cacheQueueDownloadInCurrentQueue:(BOOL)yn block:(CacheBlock)block;

@end

@interface NSString (AsyncOrCache)
/*!
 @method 默认采取另外创建一个线程队列，异步缓存资源到指定沙盒子目录中
 @abstract 根据url字符串的地址，发起网络请求并添加到一个新创建的线程队列中，进行下载并缓存。本地已缓存该文件，将不进行下载
 @discussion 资源保存到沙盒dir子目录目录下，以URL字符串的MD5值作为文件名，最后返回该完整。可在block中处理NSData
 @param dir 应用沙盒子目录，缓存资源保存的位置
 @return 返回缓存资源所在的路径
 */
- (NSString*)urlMD5PathCacheQueueDownloadInAppSubDir:(NSString*)dir block:(CacheBlock)block;
/*!
 @method 异步缓存资源到指定沙盒子目录中
 @abstract 根据url字符串的地址，发起网络请求并添加到一个新创建的线程队列中，进行下载并缓存。本地已缓存该文件，将不进行下载
 @discussion 资源保存到沙盒dir子目录目录下，以URL字符串的MD5值作为文件名，最后返回该完整。可在block中处理NSData
 @param dir 应用沙盒子目录，缓存资源保存的位置
 @param yn 是否使用当前线程队列来进行异步多任务，否则将新创建一个线程队列
 @return 返回缓存资源所在的路径
 */
- (NSString*)urlMD5PathCacheQueueDownloadInAppSubDir:(NSString*)dir isCurrentQueue:(BOOL)yn block:(CacheBlock)block;

@end


@interface UIImageView (AsyncOrCache)
/*!
 @method 异步加载图片到ImageView中并缓存到本地
 @abstract 根据给定url地址，发起网络请求并添加到一个新创建的线程队列中，进行下载并缓存，最后加载该图片到视图中
 @discussion 图片保存到沙盒ImageCache目录下，以URL MD5值作为文件名
 @param url 图片欲异步加载的url地址
 */
- (void)loadImageWithDownloadUrl:(NSString*)url;
/*!
 @method 异步加载图片到ImageView中并缓存到本地
 @abstract 根据给定url地址，发起网络请求并添加到线程队列中，进行下载并缓存，最后加载该图片到视图中
 @discussion 图片保存到沙盒ImageCache目录下，以URL MD5值作为文件名
 @param url 图片欲异步加载的url地址
 @param yn 是否使用当前线程队列来进行异步多任务，否则将新创建一个线程队列
 */
- (void)loadImageWithDownloadUrl:(NSString*)url isCurrentQueue:(BOOL)yn;
/*!
 @method 异步加载图片到ImageView中并缓存到本地
 @abstract 根据给定url地址，发起网络请求并添加到线程队列中，进行下载并缓存，最后加载该图片到视图中
 @discussion 图片保存到沙盒dirName目录下，以URL MD5值作为文件名
 @param dirName 沙盒缓存子目录
 @param url 图片欲异步加载的url地址
 @param yn 是否使用当前线程队列来进行异步多任务，否则将新创建一个线程队列
 */
- (void)loadImageWithDownloadUrl:(NSString*)url inSubDir:(NSString*)dirName isCurrentQueue:(BOOL)yn;

@end

