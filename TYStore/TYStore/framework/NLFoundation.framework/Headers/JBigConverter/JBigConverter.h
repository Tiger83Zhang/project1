//
//  JBigConverter.h
//  JBigConverter
//
//  Created by su on 14-1-9.
//  Copyright (c) 2014年 suzw. All rights reserved.
//

#import <UIKit/UIImage.h>

@interface JBigConverter : NSObject
+ (NSData*)convertJBigWithImage:(UIImage*)image error:(NSError**)err;
+ (NSData*)convertJBigWithPbmFile:(NSString*)srcPath destFile:(NSString*)destPath error:(NSError**)err;
+ (UIImage*)convertImageWithJBigData:(NSData*)jbigData error:(NSError**)err;
@end
