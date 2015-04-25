//
//  config.h
//  jsums
//
//  Created by su on 13-11-28.
//  Copyright (c) 2013年 suzw. All rights reserved.
//
#ifndef jsums_config_h
#define jsums_config_h

#define CCB_SERVER_ADDRESS_PRODUCT @"https://ibsbjstar.ccb.com.cn/app/InternetPosServlet"
#define CCB_SERVER_ADDRESS_2 @"http://128.128.96.2:8001/app/InternetPosServlet"
#define CCB_SERVER_ADDRESS_175 @"http://128.128.96.175:8001/app/InternetPosServlet"
#define CCB_SERVER_ADDRESS_118 @"http://128.128.96.118:8001/app/InternetPosServlet"
#define CT_SERVER_ADDRESS @"http://192.168.48.50:8098/TransTest/InternetPosServlet.action"
// 是否测试交易
#define IS_TEST_BUSINESS 0
// 是否匹配终端商户号
#define IS_MATCH_DEVICE 0
// 是否开启定位POS设备
#define IS_LBS_DEVICE 1

#define CCB_DEBUG_FLAG_SOCKET 0 // socket通信标记
// 手势启用
#define GESTUREPASSWORDFLAG(userId) [NSString stringWithFormat:@"GesturePasswordFlag_%@",userId]
//交易完打印签购单
#define PRINTCONSUMEFLAG [NSString stringWithFormat:@"PrintConsumeFlag_%@",[CCBUser currentUser].userID]
//打印商户联
#define PRINTSTOREFLAGE [NSString stringWithFormat:@"PrintStoreFlag_%@",[CCBUser currentUser].userID]
// 背景图片
#define BACKGROUNDPHOTO @"BackgroundPhoto.png"
// 头像自定义图片
#define USERHEADPHOTO @"UserHeadPhoto.png"
// 保存唯一标识
#define CCBUUID @"com.ccb.mpos"
// 获取本地头像图片
#define HEAD_ICON(index) [UIImage imageNamed:[NSString stringWithFormat:@"icon_head_%d.png",index]]
// 验证码确认时间
#define CCBTIME_SECONDE 60

#define SERVICE_TEST_ADDRESS_SET @"serviceTestAddress"

// 是否显示第三方调用内容
#define IS_SHOW_THIRD 0

// 屏幕状态栏高度
#define kStatusBarHeight 20
// 应用导航栏高度
#define kNavBarHeight 44
// 屏幕宽度
#define kScreenWidth [[UIScreen mainScreen] bounds].size.width
// 屏幕高度
#define kScreenHeight [[UIScreen mainScreen] bounds].size.height
// 应用屏幕宽度
#define kAppWidth kScreenWidth
// 应用屏幕高度
#define kAppHeight (kScreenHeight - kStatusBarHeight)
// 应用视图高度（不包含状态栏、导航栏高度）
#define kViewHeight (kAppHeight - kNavBarHeight)
// 缩放比例
#define scalW (CGFloat)kAppWidth/320
// 长度拉伸
#define scalH (CGFloat)kScreenHeight/480
// 屏幕尺寸系数
#define screenScale ([UIScreen mainScreen].scale)

#define RGBCOLOR(r, g, b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]

#define  iphone5Height 568
#define  iphone6Height 667
#define  iphone6PHeight 736

//新大陆设备
#define NLDEVICENAME @"NL"
//百富设备
#define PAXDEVICENAME @"PAX"
//联迪设备
#define LDDEVICENAME @"LD"
//升腾设备
#define CTDEVICENAME @"CT"

#endif
