//
//  UIImage+Formater.h
//  JBigConverter
//
//  Created by su on 14-1-9.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <UIKit/UIImage.h>

@interface UIImage (Formater)
/*!
 @method convert2PBM
 @abstract 将bitmap转换为pbm文件数据流
 @discussion 可直接将该二进制数据存储到文件，作为pbm文件
 */
- (NSData*)convert2PBM;
/*!
 @method imageWithPbmData
 @abstract 将pbm文件流数据转换为png UIImage对象
 @discussion 从pbm文件提取二进制流数据，转为png图片格式
 */
+ (UIImage*)imageWithPbmData:(NSData*)pbmData;
@end
