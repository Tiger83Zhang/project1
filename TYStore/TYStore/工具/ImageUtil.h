//
//  ImageUtil.h
//  MESDKTest
//
//  Created by su on 14/12/23.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@interface ImageUtil : NSObject
+(UIImage *)image:(UIImage *)image rotation:(UIImageOrientation)orientation;
+(UIImage *)reSizeImage:(UIImage *)image toSize:(CGSize)reSize;
+(UIImage *)flipImage:(UIImage *)image;
/*!
 *  @brief  color转换成image
 *
 *  @param color UIColor
 *
 *  @return UIImage
 */
+ (UIImage*) createImageWithColor: (UIColor*) color;
/*!
 *  @brief  通过比例缩放图片
 *
 *  @param image       图片对象
 *  @param scaleFactor 比例系数 乘以
 *
 *  @return 缩放后的图片
 */
+ (UIImage *)reSizeImage:(UIImage *)image scaleFactor:(CGFloat)scaleFactor;
/*!
 *  @brief  灰度处理
 *
 *  @param sourceImage 原图像
 *
 *  @return 处理后的图像
 */
+(UIImage*)getGrayImage:(UIImage*)sourceImage;


@end
