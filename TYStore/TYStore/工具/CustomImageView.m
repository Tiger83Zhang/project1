//
//  CustomImageView.m
//  TestProject
//
//  Created by Lw on 15/4/25.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "CustomImageView.h"

@interface CustomImageView (){
    CGRect oldFrame;    //保存图片原来的大小
    CGRect largeFrame;  //确定图片放大最大的程度
}

@property (strong, nonatomic) UIPinchGestureRecognizer *pinchGestureRecognizer;
@property (strong, nonatomic) UIPanGestureRecognizer *panGestureRecognizer;

@end

@implementation CustomImageView

- (id)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        [self setUserInteractionEnabled:YES];
        [self setMultipleTouchEnabled:YES];
        
        oldFrame = frame;
        largeFrame = CGRectMake(0 - kAppWidth, 0 - kViewHeight, 3 * oldFrame.size.width, 3 * oldFrame.size.height);
        
        [self addGestureRecognizerToView:self];
    }
    
    return self;
}

// 添加所有的手势
- (void)addGestureRecognizerToView:(UIView *)view
{
    // 旋转手势
//    UIRotationGestureRecognizer *rotationGestureRecognizer = [[UIRotationGestureRecognizer alloc] initWithTarget:self action:@selector(rotateView:)];
//    [view addGestureRecognizer:rotationGestureRecognizer];
    
    // 缩放手势
    self.pinchGestureRecognizer = [[UIPinchGestureRecognizer alloc] initWithTarget:self action:@selector(pinchView:)];
    [view addGestureRecognizer:_pinchGestureRecognizer];
    
    // 移动手势
    self.panGestureRecognizer = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(panView:)];
}

// 处理旋转手势
- (void)rotateView:(UIRotationGestureRecognizer *)rotationGestureRecognizer
{
    UIView *view = rotationGestureRecognizer.view;
    if (rotationGestureRecognizer.state == UIGestureRecognizerStateBegan || rotationGestureRecognizer.state == UIGestureRecognizerStateChanged) {
        view.transform = CGAffineTransformRotate(view.transform, rotationGestureRecognizer.rotation);
        [rotationGestureRecognizer setRotation:0];
    }
}

// 处理缩放手势
- (void) pinchView:(UIPinchGestureRecognizer *)pinchGestureRecognizer
{
    UIView *view = pinchGestureRecognizer.view;
    if (pinchGestureRecognizer.state == UIGestureRecognizerStateBegan || pinchGestureRecognizer.state == UIGestureRecognizerStateChanged) {
        view.transform = CGAffineTransformScale(view.transform, pinchGestureRecognizer.scale, pinchGestureRecognizer.scale);
        
        if (view.frame.size.width < oldFrame.size.width) {
            //让图片无法缩得比原图小
            view.frame = oldFrame;
        }
        if (view.frame.size.width > 3 * oldFrame.size.width) {
            view.frame = largeFrame;
        }
        pinchGestureRecognizer.scale = 1;
    }
    
    if (pinchGestureRecognizer.state == UIGestureRecognizerStateEnded) {
        NSLog(@"view = %@",view);
        if (view.frame.size.width == oldFrame.size.width) {
            [view removeGestureRecognizer:self.panGestureRecognizer];
            self.scrollView.scrollEnabled = YES;
        }
        else {
            [self addGestureRecognizer:self.panGestureRecognizer];
            self.scrollView.scrollEnabled = NO;
        }
    }
    
}

// 处理拖拉手势
- (void)panView:(UIPanGestureRecognizer *)panGestureRecognizer
{
    UIView *view = panGestureRecognizer.view;
    if (panGestureRecognizer.state == UIGestureRecognizerStateBegan || panGestureRecognizer.state == UIGestureRecognizerStateChanged) {
        CGPoint translation = [panGestureRecognizer translationInView:view.superview];
        [view setCenter:(CGPoint){view.center.x + translation.x, view.center.y + translation.y}];
        [panGestureRecognizer setTranslation:CGPointZero inView:view.superview];
    }
}

@end
