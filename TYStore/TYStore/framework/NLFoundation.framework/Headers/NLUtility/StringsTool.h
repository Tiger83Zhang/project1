//
//  StringsTool.h
//  Lakala
//
//  Created by chenqz on 12-3-7.
//  Copyright (c) 2012年 lakala.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

//姓名长度的限制
#define VALID_NAME_LENGTH 32

#define ENGINNO_LENGTH 20
#define CHEJIA_LENGTH 30


//字符串工具
@interface StringsTool : NSObject

//防止字符串中出现“NULL”
+ (NSString *)xNULL:(NSString *)str;
+ (BOOL)isPhoneNumber:(NSString *)str;
+ (BOOL)isPassword:(NSString *)str;
+ (BOOL)isEmailAddress:(NSString *)str;
+ (BOOL)isChineseIdentityCard:(NSString *)str; //是否是身份证号
+ (BOOL)isNumber:(NSString *)str;
+ (BOOL)isLetter:(NSString *)str;
+ (BOOL)isSpecialCharacters:(NSString *)str;
+ (BOOL)isInt:(NSString *)str;
+ (BOOL)isDecimal:(NSString *)str;
+ (BOOL)string:(NSString *)str lengthBetween:(NSUInteger)minLength to:(NSUInteger)maxLength;
+ (BOOL)isChineseCharacter:(NSString *)str;
+(BOOL)isChineseOrEnglishName:(NSString *)str;
+(BOOL)isCarPlateNumber:(NSString *)str;
+(BOOL)isCheJiaNumber:(NSString *)str;
+(BOOL)isEnginNumber:(NSString *)str;
+(BOOL)isZipCode:(NSString *)str;
+(BOOL)isTrainNumber:(NSString *)str;//是否是火车车次
+ (NSString *)upString:(NSString *)string;
//防止出现特殊字符
+ (BOOL)isAllowInputlCharacters:(NSString *)str;

//处理时间 isNeed ＝ YES 显示秒 
+ (NSString *)dateTransformation:(NSString *)str displaySecond:(BOOL)isNeed;

//处理手机号(没“－”时加“－”，有“－”时去“－”)
+ (NSString *)handlePhoneNumber:(NSString *)str;
//处理卡号(没“ ”时加“ ”，有“ ”时去“ ”)
+ (NSString *)handleCardNumber:(NSString *)str;

//去除一连串数字中的字符
+ (NSString *)deleteStringOther:(NSString *)string;

+(NSString *)getPinYinForChineseCharactor:(NSString *)charactor;
+ (NSString *)fomattedCardNumber:(NSString *)cardNumber;
//输入过程中验证卡号
+ (BOOL)verfictCardNumberField:(UITextField *)textField changeCharactersInRange:(NSRange)range replacementString:(NSString *)string cardNumberLength:(int)length;

+ (BOOL)isCardNumberField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;
+ (void)cardNumberFieldBeginEditing:(UITextField *)textField;//开始编辑，去掉空格
+ (void)cardNumberFieldEndEditing:(UITextField *)textField;//结束编辑，加上空格
+ (NSString *)clearCardNumber:(NSString *)str; //去掉空格

//输入过程中验证手机号
+ (BOOL)verfictPhoneNumberField:(UITextField *)textField changeCharactersInRange:(NSRange)range replacementString:(NSString *)string phoneNumberLength:(int)length cancelKeyboard:(BOOL)cancel;

+ (BOOL)isPhoneNumberField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string disappearKeyboard:(BOOL)disapper;
+ (void)phoneNumberFieldBeginEditing:(UITextField *)textField;//开始编辑，去掉“-”
+ (void)phoneNumberFieldEndEditing:(UITextField *)textField;//结束编辑，加上“-”
+ (NSString *)clearPhoneNumber:(NSString *)str; //去掉“-”

//输入过程中验证输入金额
+ (BOOL)verfictMoneyField:(UITextField *)textField replacementString:(NSString *)string;
+ (BOOL)isMoneyField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

//对输入金额完成后进行处理
+ (void)handleInputMoneysEndEditField:(UITextField *)textField;
//对输入卡号完成后的显示进行处理
+ (void)handleCardNumberEndedEditField:(UITextField *)textField;

//将一个浮点型变成金额的格式
+ (NSString *)moneyStringForNumber:(double)number;
//将一个银行卡号用暗文显示
+ (NSString *)bankCardHalfDisplay:(NSString *)bankCard;

//将一个带逗号的金额字符串变成一个普通的浮点数，比如1,500.00 -> 1500.00
+ (double )doubleValueFromMoneyString:(NSString *)moneyString;
//截取多余的字符串
+ (NSString *)deleteString:(NSString *)string subLen:(int)len;

+ (float)getTextFont:(NSString *)string;
//交易详情状态
+(NSString *) getTradeHisStatus:(NSString *) status;

//购买刷卡器电话号格式化
+ (NSString *)phoneStringFormater:(NSString *)phoneNum;
// 多个电话号码格式化，只取第一个 add by suzw
+ (NSString*)pickPhoneString:(NSString*)phoneNum;
// 从字符串中获取第一个手机或电话号码
+ (NSString*)pickPhoneNumberWithString:(NSString*)str;
// 获取链接url add by suzw
+ (NSArray*)pickLinkUrl:(NSString*)str;

+ (NSString *)randomString;

+ (BOOL)isHanzi:(NSString *)nameString;//检查是否全部为汉字
+ (BOOL)isLegalCardNumber:(NSString *)cardnum;//信用卡卡号校验是否合法

+ (NSString *)getTime;//获取当前时间
+ (NSString *)getSeries;//获取交易流水号
+ (NSString *)hideDetailNum:(NSString *)cardNum ;//卡号打*
+ (NSString *)hidedetailLoginName:(NSString *)loginName;//登录名打*
+ (NSString *)getLastSubCardNo:(NSString *)cardNo;//取卡号后4位

//时分秒格式转换 131010---13:10:10
+ (NSString *)timeHHMMSS:(NSString *)time;
//姓名校验
+ (BOOL)isValidateName:(NSString *)name;
//邮箱校验
+ (BOOL)isValidateEmail:(NSString *)email;
//四舍五入
+ (NSString *)rounding:(float)price afterPoint:(int)position;
//url编码
+ (NSString*)encodeURL:(NSString *)string;
// 过滤超文本标记
+ (NSString*)filterHtmlTag:(NSString*)html;

//日期格式化YYYY/MM/DD HH:MM:SS
+ (NSString *)dateTransformationNotHanZi:(NSString *)str displaySecond:(BOOL)isNeed;
//根据日期获取星期
+ (NSString *)weekFromDateString:(NSString *)datestring formate:(NSString *)formate;
//日期格式转换
+ (NSString *)stringFromDate:(NSString *)dateString orgformate:(NSString *)orgFromate formate:(NSString *)toformate;
//NSDate转换成指定格式NSString
+ (NSString *)stringFromDate:(NSDate *)date formate:(NSString *)formate;
+ (NSDate *)dateFromString:(NSString *)dateString formate:(NSString *)formate;
//获取前一天
+ (NSString *)lastDay:(NSString *)nowday formate:(NSString *)formate;
//获取后一天
+ (NSString *)nextDay:(NSString *)nowday formate:(NSString *)formate;
//获取后n天
+ (NSString *)dealyNDay:(NSString *)nowday days:(int)days formate:(NSString *)formate;
//获取前n天
+ (NSString *)beforeNDay:(NSString *)nowday days:(int)days formate:(NSString *)formate;
//获取前n个小时
+ (NSString *)beforeNHours:(NSString *)nowday hours:(int)hours formate:(NSString *)formate;
//获取后n个小时
+ (NSString *)delayNHours:(NSString *)nowday hours:(int)hours formate:(NSString *)formate;
//从身份证获取生日
+ (NSString *)getBirthdayFromIDcard:(NSString *)cardNumber;
//字母或则空格
+ (BOOL)isZiMu:(NSString *)name;
+ (BOOL)isLastDay:(NSString *)date;
+ (BOOL)isHanziAndZimu:(NSString *)nameString;
+ (BOOL)isIncludeZimu:(NSString *)str;
+ (BOOL)isIncludeHanzi:(NSString *)str;
+ (CGFloat)returnHeightWithLabel:(NSString*)labelstring font:(UIFont *)forn width:(float)width;
+ (BOOL)isURL:(NSString *)string;
@end
