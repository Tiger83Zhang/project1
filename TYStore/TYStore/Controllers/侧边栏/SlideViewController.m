//
//  SlideViewController.m
//  TestProject
//
//  Created by Lw on 15/4/24.
//  Copyright (c) 2015年 shencw. All rights reserved.
//

#import "SlideViewController.h"
#import <NLFoundation/NLUtility/UILabel+Custom.h>
#import "CommodityListViewController.h"

@interface SlideViewController ()<UITableViewDataSource,UITableViewDelegate>

@property (strong, nonatomic) UITableView *tableV;

@property (strong, nonatomic) NSMutableArray *dataArr;

@property (strong, nonatomic) UILabel *titleLb;

@end

@implementation SlideViewController
@synthesize tableV;

- (void)setCurrListViewController:(CommodityListViewController*)listVC
{
    self.listVC = listVC;
    
    _titleLb.text = listVC.labTitle.text;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self textData];
    
    self.titleLb = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, kAppWidth-70, 40)];
    _titleLb.backgroundColor = [UIColor clearColor];
    _titleLb.textColor = [UIColor whiteColor];
    _titleLb.textAlignment = NSTextAlignmentCenter;
    _titleLb.font = [UIFont systemFontOfSize:18.0];
    
    tableV = [[UITableView alloc] initWithFrame:CGRectMake(0, 0, kAppWidth-70, kViewHeight) style:UITableViewStylePlain];
    tableV.delegate = self;
    tableV.dataSource = self;
    tableV.backgroundColor = [UIColor clearColor];
    tableV.backgroundView = nil;
    tableV.tableFooterView = [[UIView alloc] init];
    [self.view addSubview:tableV];
}

- (void)textData
{
    NSDictionary *dic111 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"1",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"3",@"level",
                           nil];
    NSDictionary *dic112 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"2",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"3",@"level",
                           nil];
    NSArray *arr11 = [NSArray arrayWithObjects:dic111,dic112, nil];
    
    NSDictionary *dic11 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"11",@"title",
                          arr11,@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                          nil];
    NSDictionary *dic12 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"22",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                          nil];
    
    NSArray *arr1 = [NSArray arrayWithObjects:dic11,dic12, nil];
    NSDictionary *dic1 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"111",@"title",
                          arr1,@"nextArr",
                          @(NO),@"isAttached",
                          @"1",@"level",
                          nil];
    
    NSDictionary *dic21 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"11",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                          nil];
    NSDictionary *dic22 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"22",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                          nil];
    NSDictionary *dic23 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"33",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                           nil];
    NSArray *arr2 = [NSArray arrayWithObjects:dic21,dic22,dic23, nil];
    NSDictionary *dic2 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"222",@"title",
                          arr2,@"nextArr",
                          @(NO),@"isAttached",
                          @"1",@"level",
                          nil];
    
    NSDictionary *dic31 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"11",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                           nil];
    NSDictionary *dic32 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"22",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                           nil];
    NSDictionary *dic33 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"33",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                           nil];
    NSDictionary *dic34 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                           @"44",@"title",
                           [NSArray array],@"nextArr",
                           @(NO),@"isAttached",
                           @"2",@"level",
                           nil];
    NSArray *arr3 = [NSArray arrayWithObjects:dic31,dic32,dic33,dic34, nil];
    NSDictionary *dic3 = [NSMutableDictionary dictionaryWithObjectsAndKeys:
                          @"333",@"title",
                          arr3,@"nextArr",
                          @(NO),@"isAttached",
                          @"1",@"level",
                          nil];
    
    self.dataArr = [NSMutableArray arrayWithObjects:dic1,dic2,dic3, nil];
}

#pragma mark UITableView DataSource

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return self.dataArr.count;
}

- (UITableViewCell*)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    UITableViewCell *cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:nil];
    cell.backgroundColor = [UIColor clearColor];
    cell.contentView.backgroundColor = [UIColor clearColor];
    
    NSDictionary *dic = [self.dataArr objectAtIndex:indexPath.row];
    
    UILabel *titleLb = [[UILabel alloc] initWithFrame:CGRectMake(10, 0, 200, 44)];
    titleLb.text = [dic objectForKey:@"title"];
    titleLb.font = [UIFont systemFontOfSize:16.0];
    titleLb.textColor = [UIColor whiteColor];
    titleLb.backgroundColor = [UIColor clearColor];
    [cell addSubview:titleLb];
    
    NSInteger level = [[dic objectForKey:@"level"] intValue];
    if (level == 2) {
        titleLb.frame = CGRectMake(30, 0, 200, 44);
    }
    else if (level == 3) {
        titleLb.frame = CGRectMake(50, 0, 200, 44);
    }
    
    NSArray *arr = [dic objectForKey:@"nextArr"];
    if (arr.count > 0) {
        UIImageView *iconView = [[UIImageView alloc] initWithFrame:CGRectMake(0, 0, 10, 20)];
        iconView.image = [UIImage imageNamed:@"icon_right_arrow_black.png"];
        cell.accessoryView = iconView;
    }
    
    return cell;
}

#pragma mark UITableView Delegate
- (CGFloat)tableView:(UITableView *)tableView heightForHeaderInSection:(NSInteger)section
{
    return 40;
}

- (UIView*)tableView:(UITableView *)tableView viewForHeaderInSection:(NSInteger)section
{
    UIView *headerView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, kAppWidth-70, 40)];
    headerView.backgroundColor = [UIColor clearColor];
    [headerView addSubview:_titleLb];
    
    return headerView;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    NSMutableDictionary *dic = [self.dataArr objectAtIndex:indexPath.row];
    _titleLb.text = [dic objectForKey:@"title"];
    
    NSArray *arr = [dic objectForKey:@"nextArr"];
    NSMutableArray *indexArr = [NSMutableArray array];
    BOOL isAttached = [[dic objectForKey:@"isAttached"] boolValue];
    
    NSInteger currIndex = indexPath.row;
    for (int i=0;i < arr.count ; i++) {
        NSIndexPath *index = [NSIndexPath indexPathForRow:currIndex + 1 inSection:indexPath.section];
        [indexArr addObject:index];
        currIndex ++;
        
        NSMutableDictionary *subDic = [arr objectAtIndex:i];
        if (isAttached) {
            if ([[subDic objectForKey:@"isAttached"] boolValue]) {
                NSArray *subArr = [subDic objectForKey:@"nextArr"];
                for (int j=0; j<subArr.count; j++) {
                    NSIndexPath *index = [NSIndexPath indexPathForRow:currIndex + 1 inSection:indexPath.section];
                    [indexArr addObject:index];
                    currIndex ++;
                    
                    [self.dataArr removeObjectAtIndex:indexPath.row + i + 1];
                }
                [subDic setObject:@(NO) forKey:@"isAttached"];
            }
            [self.dataArr removeObjectAtIndex:indexPath.row +1];
        }
        else {
            [self.dataArr insertObject:subDic atIndex:indexPath.row + i + 1];
        }
    }
    
    
    if (isAttached) {
        [tableView beginUpdates];
        [tableView deleteRowsAtIndexPaths:indexArr withRowAnimation:UITableViewRowAnimationMiddle];
        [tableView endUpdates];
        
        [dic setObject:@(NO) forKey:@"isAttached"];
    }
    else {
        [tableView beginUpdates];
        [tableView insertRowsAtIndexPaths:indexArr withRowAnimation:UITableViewRowAnimationMiddle];
        [tableView endUpdates];
        
        [dic setObject:@(YES) forKey:@"isAttached"];
    }
}

@end
