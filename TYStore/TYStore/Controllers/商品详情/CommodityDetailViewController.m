//
//  CommodityDetailViewController.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "CommodityDetailViewController.h"
#import "CommodityTabbarView.h"
#import "CustomImageView.h"

@interface CommodityDetailViewController ()<CommodityTabbarDelegate,UIScrollViewDelegate>

@property (strong, nonatomic) UIScrollView *scrollView;

@property (strong, nonatomic) UIView *detailInfoView,*bgView;

@property (strong, nonatomic) UILabel *branderLb,*sizeLb,*priceLb,*contentLb;

@property (strong, nonatomic) UILabel *pageLb;

@property (strong, nonatomic) NSArray *imageArr;

@end

@implementation CommodityDetailViewController
@synthesize branderLb,sizeLb,priceLb,contentLb,pageLb;
@synthesize scrollView;
@synthesize imageArr;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, kAppWidth, kViewHeight-60)];
    scrollView.backgroundColor = [UIColor clearColor];
    scrollView.pagingEnabled = YES;
    scrollView.showsHorizontalScrollIndicator = NO;
    scrollView.showsVerticalScrollIndicator = NO;
    scrollView.delegate = self;
    [self.view addSubview:scrollView];
    
    [self showImageView];
    [self createDetailView];
    
    CommodityTabbarView *tabbarView = [[CommodityTabbarView alloc] init];
    tabbarView.delegate = self;
    [self.view addSubview:tabbarView];
}

- (void)showImageView
{
    imageArr = [NSArray array];
    scrollView.contentSize = CGSizeMake(kAppWidth*imageArr.count, kViewHeight-60);
    pageLb = [self labelWithFrame:CGRectMake(0, 0, 30, 44) title:[NSString stringWithFormat:@"1/%d",imageArr.count] font:18.0 textColor:[UIColor whiteColor]];
    self.navigationItem.rightBarButtonItem = [[UIBarButtonItem alloc] initWithCustomView:pageLb];
    
    for (int i=0; i<imageArr.count; i++) {
        UIImage *image = [imageArr objectAtIndex:i];
        CustomImageView *imageView = [[CustomImageView alloc] initWithFrame:CGRectMake(i*kAppWidth, 0, kAppWidth, image.size.width/kAppWidth*image.size.height)];
        imageView.image = image;
        imageView.scrollView = self.scrollView;
        [scrollView addSubview:imageView];
    }
}

- (void)createDetailView
{
    self.bgView = [[UIView alloc] initWithFrame:CGRectMake(0, kViewHeight-60-140, kAppWidth, 140)];
    self.bgView.backgroundColor = [UIColor blackColor];
    self.bgView.alpha = 0.5;
    self.bgView.hidden = YES;
    [self.view addSubview:self.bgView];
    
    self.detailInfoView = [[UIView alloc] initWithFrame:CGRectMake(0, kViewHeight-60-140, kAppWidth, 140)];
    self.detailInfoView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:self.detailInfoView];
    self.detailInfoView.hidden = YES;
    
    // “品牌”
    UILabel *label1 = [self labelWithFrame:CGRectMake(20, 10, 60, 30) title:@"品牌:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label1];
    
    self.branderLb = [self labelWithFrame:CGRectMake(65, 10, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:branderLb];
    
    // “型号”
    UILabel *label2 = [self labelWithFrame:CGRectMake(20, 40, 60, 30) title:@"型号:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label2];
    
    self.sizeLb = [self labelWithFrame:CGRectMake(65, 40, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:sizeLb];
    
    // “价格”
    UILabel *label3 = [self labelWithFrame:CGRectMake(20, 70, 60, 30) title:@"价格:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label3];
    
    self.priceLb = [self labelWithFrame:CGRectMake(65, 70, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:priceLb];
    
    // “描述”
    UILabel *label4 = [self labelWithFrame:CGRectMake(20, 100, 60, 30) title:@"描述:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label4];
    
    self.contentLb = [self labelWithFrame:CGRectMake(65, 100, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:contentLb];
}

- (UILabel*)labelWithFrame:(CGRect)frame title:(NSString*)title font:(CGFloat)font textColor:(UIColor*)textColor
{
    UILabel *label = [[UILabel alloc] initWithFrame:frame];
    label.text = title;
    label.backgroundColor = [UIColor clearColor];
    label.font = [UIFont systemFontOfSize:font];
    label.textColor = textColor;
    
    return label;
}

#pragma mark CommodityTabbarDelegate
- (void)showLast
{
    
}

- (void)showNext
{
    
}

- (void)showDetail
{
    self.detailInfoView.hidden = !self.detailInfoView.hidden;
    self.bgView.hidden = !self.bgView.hidden;
}

- (void)doCollect
{
    
}

#pragma mark UIScrollView Delegate
- (void)scrollViewDidScroll:(UIScrollView *)scrollView
{
    pageLb.text = [NSString stringWithFormat:@"%d/%d",(int)scrollView.contentOffset.x/(int)kAppWidth+1,imageArr.count];
}

@end
