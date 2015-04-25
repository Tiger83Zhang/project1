//
//  CompanyDetailViewController.m
//  TestProject
//
//  Created by Lw on 15/4/25.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "CompanyDetailViewController.h"
#import "CustomImageView.h"

@interface CompanyDetailViewController ()

@property (strong, nonatomic) UIScrollView *scrollView;

@property (strong, nonatomic) UIView *detailInfoView,*bgView;

@property (strong, nonatomic) UILabel *contentLb,*addressLb1,*addressLb2,*phoneLb;

@end

@implementation CompanyDetailViewController
@synthesize scrollView;
@synthesize contentLb,addressLb1,addressLb2,phoneLb;

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self createRightButtonWithNormalImage:@"icon_btnshwo_def.png" selectImage:@"icon_btnshwo_cli.png" action:@selector(showDetailInfo)];
    
    self.scrollView = [[UIScrollView alloc] initWithFrame:CGRectMake(0, 0, kAppWidth, kViewHeight)];
    scrollView.backgroundColor = [UIColor clearColor];
    scrollView.pagingEnabled = YES;
    scrollView.showsHorizontalScrollIndicator = NO;
    scrollView.showsVerticalScrollIndicator = NO;
    [self.view addSubview:scrollView];
    
    [self showImageView];
    [self createDetailView];
}

- (void)showImageView
{
    NSArray *imageArr = [NSArray array];
    scrollView.contentSize = CGSizeMake(kAppWidth*imageArr.count, kViewHeight);
    
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
    self.bgView = [[UIView alloc] initWithFrame:CGRectMake(0, kViewHeight-140, kAppWidth, 140)];
    self.bgView.backgroundColor = [UIColor blackColor];
    self.bgView.alpha = 0.5;
    self.bgView.hidden = YES;
    [self.view addSubview:self.bgView];
    
    self.detailInfoView = [[UIView alloc] initWithFrame:CGRectMake(0, kViewHeight-140, kAppWidth, 140)];
    self.detailInfoView.backgroundColor = [UIColor clearColor];
    [self.view addSubview:self.detailInfoView];
    self.detailInfoView.hidden = YES;
    
    // “简介”
    UILabel *label1 = [self labelWithFrame:CGRectMake(20, 10, 80, 30) title:@"简介:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label1];
    
    self.contentLb = [self labelWithFrame:CGRectMake(90, 10, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:contentLb];
    
    // “地址”
    UILabel *label2 = [self labelWithFrame:CGRectMake(20, 40, 80, 30) title:@"地址:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label2];
    
    self.addressLb1 = [self labelWithFrame:CGRectMake(90, 40, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:addressLb1];
    
    self.addressLb2 = [self labelWithFrame:CGRectMake(90, 70, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:addressLb2];
    
    // “联系电话”
    UILabel *label3 = [self labelWithFrame:CGRectMake(20, 100, 80, 30) title:@"联系电话:" font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:label3];
    
    self.phoneLb = [self labelWithFrame:CGRectMake(90, 100, 200, 30) title:nil font:16.0 textColor:[UIColor whiteColor]];
    [self.detailInfoView addSubview:phoneLb];
}

- (void)modifyAddress:(NSString*)address
{
    for (int i=0; i<address.length; i++) {
        NSString *subStr = [address substringToIndex:address.length-i];
        CGSize size = [subStr sizeWithFont:[UIFont systemFontOfSize:16.0]];
        
        if (size.width <= 200) {
            addressLb1.text = subStr;
            addressLb2.text = [address substringFromIndex:address.length-i];
            break;
        }
    }
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

- (void)showDetailInfo
{
    self.detailInfoView.hidden = !self.detailInfoView.hidden;
    self.bgView.hidden = !self.bgView.hidden;
}

@end
