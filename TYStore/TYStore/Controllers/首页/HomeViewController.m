//
//  HomeViewController.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "HomeViewController.h"
#import "HomeMenuData.h"
#import "HomeMenuView.h"
#import "CommodityListViewController.h"
#import "SlideViewController.h"
#import "RESideMenu.h"
#import "CompanyDetailViewController.h"
#import "MoreViewController.h"

#define SPACE 2
#define SCALE kScreenHeight / 480
#define HEIGHT (kAppHeight - 6*SPACE)/7.0
#define WIDTH (kAppWidth-3*SPACE)/2.0
#define HALF_WIDTH ((kAppWidth-3*SPACE)/2.0 - SPACE)/2.0

@interface HomeViewController ()

@property (strong, nonatomic) NSArray *menuDataArr;

@end

@implementation HomeViewController

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    [self.navigationController setNavigationBarHidden:YES animated:YES];
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self modifyMenuData];
    
    for (HomeMenuData *data in self.menuDataArr) {
        HomeMenuView *menuView = [[HomeMenuView alloc] initWithMenuData:data];
        [self.view addSubview:menuView];
    }
}

- (void)modifyMenuData
{
    CGFloat initHeight = G_DEVICE_IOS7?20:0;
    self.menuDataArr = [NSArray arrayWithObjects:
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(SPACE, SPACE+initHeight, kAppWidth-2*SPACE, 2*HEIGHT) backgroundColor:RGBCOLOR(109, 167, 170) title:@"公司简介" icon:@"icon_home_company.png" menuType:HomeMenuTypeCompany target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(SPACE, 2*(HEIGHT+SPACE)+initHeight, WIDTH, 2*HEIGHT) backgroundColor:RGBCOLOR(19, 180, 184) title:@"种类" icon:@"icon_home_class.png" menuType:HomeMenuTypeClass target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(2*SPACE+WIDTH, 2*(HEIGHT+SPACE)+initHeight, HALF_WIDTH, HEIGHT) backgroundColor:RGBCOLOR(236, 121, 108) title:@"特价" icon:@"icon_home_special.png" menuType:HomeMenuTypeSpecial target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(3*SPACE+WIDTH+HALF_WIDTH, 2*(HEIGHT+SPACE)+initHeight, HALF_WIDTH, HEIGHT) backgroundColor:RGBCOLOR(95, 147, 183) title:@"收藏" icon:@"icon_home_collection.png" menuType:HomeMenuTypeCollection target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(SPACE, 3*SPACE+4*HEIGHT+initHeight, HALF_WIDTH, HEIGHT) backgroundColor:RGBCOLOR(177, 95, 159) title:@"热卖" icon:@"icon_home_hot.png" menuType:HomeMenuTypeHot target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(2*SPACE+HALF_WIDTH, 3*SPACE+4*HEIGHT+initHeight, HALF_WIDTH, HEIGHT) backgroundColor:RGBCOLOR(136, 200, 154) title:@"新品" icon:@"icon_home_new.png" menuType:HomeMenuTypeNew target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(2*SPACE+WIDTH, 3*(SPACE+HEIGHT)+initHeight, WIDTH, 2*HEIGHT) backgroundColor:RGBCOLOR(188, 127, 228) title:@"品牌" icon:@"icon_home_brander.png" menuType:HomeMenuTypeBrander target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(SPACE, 4*SPACE+5*HEIGHT+initHeight, 1.3*WIDTH, HEIGHT) backgroundColor:RGBCOLOR(219, 128, 133) title:@"更新数据" icon:@"icon_home_update.png" menuType:HomeMenuTypeUpdate target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(2*SPACE+1.3*WIDTH, 4*SPACE+5*HEIGHT+initHeight, kAppWidth-3*SPACE-1.3*WIDTH, HEIGHT) backgroundColor:RGBCOLOR(136, 200, 154) title:@"更多" icon:@"icon_home_set.png" menuType:HomeMenuTypeMore target:self action:@selector(toBusniss:)],
                        
                        [[HomeMenuData alloc] initWithFrame:CGRectMake(SPACE, 5*SPACE+6*HEIGHT+initHeight, kAppWidth-2*SPACE, HEIGHT) backgroundColor:RGBCOLOR(94, 147, 183) title:@"联系我们" icon:@"icon_home_call.png" menuType:HomeMenuTypeCall target:self action:@selector(toBusniss:)],
                        nil];
}

- (void)toBusniss:(UIButton*)button
{
    HomeMenuData *data = [self.menuDataArr objectAtIndex:button.tag];
    switch (button.tag) {
        case HomeMenuTypeCompany: // 公司简介
        {
            CompanyDetailViewController *detailVC = [[CompanyDetailViewController alloc] init];
            detailVC.title = data.title;
            detailVC.navColor = data.backgroundColor;
            [MAIN_NAVIGATION pushViewController:detailVC animated:YES];
        }
            break;
        case HomeMenuTypeClass: // 种类
        {
            CommodityListViewController *listVC = [[CommodityListViewController alloc] init];
            listVC.title = data.title;
            listVC.navColor = data.backgroundColor;
            [MAIN_SIDEVIEW setCurrListViewController:listVC];
            [MAIN_NAVIGATION pushViewController:listVC animated:YES];
        }
            break;
        case HomeMenuTypeSpecial: // 特价
        {
            CommodityListViewController *listVC = [[CommodityListViewController alloc] init];
            listVC.title = data.title;
            listVC.navColor = data.backgroundColor;
            [MAIN_SIDEVIEW setCurrListViewController:listVC];
            [MAIN_NAVIGATION pushViewController:listVC animated:YES];
        }
            break;
        case HomeMenuTypeCollection: // 收藏
        {
            CommodityListViewController *listVC = [[CommodityListViewController alloc] init];
            listVC.title = data.title;
            listVC.navColor = data.backgroundColor;
            [MAIN_NAVIGATION pushViewController:listVC animated:YES];
        }
            break;
        case HomeMenuTypeHot: // 热卖
        {
            CommodityListViewController *listVC = [[CommodityListViewController alloc] init];
            listVC.title = data.title;
            listVC.navColor = data.backgroundColor;
            [MAIN_SIDEVIEW setCurrListViewController:listVC];
            [MAIN_NAVIGATION pushViewController:listVC animated:YES];
        }
            break;
        case HomeMenuTypeNew: // 新品
        {
            CommodityListViewController *listVC = [[CommodityListViewController alloc] init];
            listVC.title = data.title;
            listVC.navColor = data.backgroundColor;
            [MAIN_SIDEVIEW setCurrListViewController:listVC];
            [MAIN_NAVIGATION pushViewController:listVC animated:YES];
        }
            break;
        case HomeMenuTypeBrander: // 品牌
        {
            CommodityListViewController *listVC = [[CommodityListViewController alloc] init];
            listVC.title = data.title;
            listVC.navColor = data.backgroundColor;
            [MAIN_SIDEVIEW setCurrListViewController:listVC];
            [MAIN_NAVIGATION pushViewController:listVC animated:YES];
        }
            break;
        case HomeMenuTypeUpdate: // 更新数据
        {
            
        }
            break;
        case HomeMenuTypeMore: // 更多
        {
            MoreViewController *moreVC = [[MoreViewController alloc] init];
            moreVC.navColor = data.backgroundColor;
            [MAIN_NAVIGATION pushViewController:moreVC animated:YES];
        }
            break;
        case HomeMenuTypeCall: // 联系我们
        {
            
        }
            break;
        default:
            break;
    }
}

@end
