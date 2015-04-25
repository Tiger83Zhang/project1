//
//  FileUtil.h
//  Lakala
//
//  Created by su on 13-1-31.
//  Copyright (c) 2013年 lakala.com. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSString (AppDocument)
/*!
 @method 取得沙盒Documents目录
 @discussion
 @result 当前应用沙盒目录下Documents目录路径
 */
+ (NSString*)appDocumentDir;
/*!
 @method 取得沙盒Temp目录
 @discussion
 @result 当前应用沙盒目录下Temp目录路径
 */
+ (NSString*)appTempDir;
/*!
 @method 取得沙盒子目录
 @abstract 沙盒不存在该子目录则创建，并返回该目录路径
 @discussion
 @result 当前应用沙盒目录下self目录路径
 */
- (NSString *)appSubDir;
// 返回沙盒指定子目录下资源路径，子目录未创建则先创建该子目录
- (NSString*)localPathInAppSubDir:(NSString*)dir;
- (NSData*)localDataInAppSubDir:(NSString*)dir;

@end

@interface IOUtil : NSObject

+ (NSInteger)filesCountOfDir:(NSString*)dirPath;
+ (NSArray*)subFileNamesOfDir:(NSString*)dirPath inDeep:(BOOL)yn;
+ (BOOL)copyFilesFromDir:(NSString*)srcDirPath toDir:(NSString*)destDirPath;
+ (void)removeDir:(NSString*)dirPath;
+ (BOOL)clearDir:(NSString*)dirPath;

@end
