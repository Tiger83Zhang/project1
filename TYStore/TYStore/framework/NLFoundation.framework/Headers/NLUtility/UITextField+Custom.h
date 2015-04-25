//
//  UITextField+Custom.h
//  Lakala
//
//  Created by zw SU on 12-10-24.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum {
    LKLTextFieldTypeNum,       // 数字收入框
    LKLTextFieldTypeCard,      // 银行卡号输入框
    LKLTextFieldTypeMoney,     // 金额输入框
    LKLTextFieldTypeTel,       // 手机号输入框
    LKLTextFieldTypePickTel,   // 手机号选择输入框 
    LKLTextFieldTypeBank,      // 银行输入框
    LKLTextFieldTypeHandInput, // 手写输入框
    LKLTextFieldTypePassword, // 密码输入框
    LKLTextFieldTypePasswordHighLevel, // 中英文符号6~20位
} LKLTextFieldType;

@interface UITextField (Custom)

// 设置textField的type
- (void)setType:(LKLTextFieldType)type;

// 该type被绑定在type变量中
- (LKLTextFieldType) type;

+ (UITextField *)textFieldWithFrame:(CGRect)rect placeholder:(NSString *)tip;

// 该type被绑定在type变量中
+ (UITextField*)textFieldWithFrame:(CGRect)rect type:(LKLTextFieldType)type placeholder:(NSString *)tip;

//完成按钮Action响应textfieldShouldReturn
+ (UITextField*)textFieldActionReturnWithFrame:(CGRect)rect type:(LKLTextFieldType)type placeholder:(NSString *)tip;

// 中文输入框
+ (UITextField*)chineseNameTextField;

// 不同type的输入框进行编辑前处理
- (void)textFieldShouldBeginEditing;

// 不同type的输入框进行编辑结束前处理，并返回编辑后的文本
- (NSString*)textFieldDidEndEditing;

// 对于设置了type的textField，delegate方法该直接从调用此方法返回
- (BOOL)shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

// 校验输入框
- (BOOL)isNotValid;
// 输入框真实数据（非格式化，无新增空格逗号等符号）
- (NSString*)realText;

// 输入框开始编辑时判断末三位是否为.00，如果是则去掉，加快用户输入
- (void)fixMoneyInputEditingBegin;

//输入框选中是键盘上方增加一个完成按钮,传入完成按钮的动作ac
- (void)addDoneButtonToolBar:(id)target action:(SEL)ac;
@end
