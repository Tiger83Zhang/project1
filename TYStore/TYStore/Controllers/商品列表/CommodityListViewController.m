//
//  CommodityListViewController.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "CommodityListViewController.h"
#import "CommodityView.h"
#import "CommodityDetailViewController.h"
#import "SlideViewController.h"

@interface CommodityListViewController ()<UITableViewDataSource,UITableViewDelegate>

@property (strong, nonatomic) UITableView *tableV;
@property (strong, nonatomic) NSArray *dataArr;

@end

@implementation CommodityListViewController
@synthesize tableV;
@synthesize dataArr;

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    if (![((UILabel*)self.navigationItem.titleView).text isEqualToString:@"收藏"]) {
        MAIN_SIDEMENU.open = YES;
    }
    
    MAIN_SIDEVIEW.view.backgroundColor = self.navColor;
    MAIN_SIDEVIEW.listVC = self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    tableV = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kAppWidth, kViewHeight) style:UITableViewStylePlain];
    tableV.delegate = self;
    tableV.dataSource = self;
    tableV.separatorStyle = UITableViewCellSeparatorStyleNone;
    tableV.backgroundColor = [UIColor clearColor];
    tableV.backgroundView = nil;
    [self.view addSubview:tableV];
}

#pragma mark UITableView DataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return 2;//(dataArr.count + 1) / 2;
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *identify = @"cell";
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:identify];
    
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:identify];
        cell.selectionStyle = UITableViewCellSelectionStyleNone;
        
        CommodityView *view1 = [[CommodityView alloc] init];
        view1.tag = 111;
        [cell addSubview:view1];
        
        CommodityView *view2 = [[CommodityView alloc] init];
        view2.tag = 222;
        view2.center = CGPointMake(view2.center.x+kAppWidth/2, view2.center.y);
        [cell addSubview:view2];
    }
    
    CommodityView *view1 = (CommodityView*)[cell viewWithTag:111];
    CommodityView *view2 = (CommodityView*)[cell viewWithTag:222];
    
    [view1 updateViewWithData:nil];
    [view2 updateViewWithData:nil];
    
    return cell;
}

#pragma mark UITableView Delegate
- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 200;
}

@end
