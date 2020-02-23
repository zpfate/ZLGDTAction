//
//  ZLGDTAction.h
//  GDTActionDemo
//
//  Created by Twisted Fate on 2020/2/23.
//  Copyright © 2020 Twisted Fate. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZLGDTAction : NSObject

/// 初始化方法
- (void)initGDT;

/// 行为上报接口，支持上报行为参数
/// @param actionName 行为类型名，系统支持的actionName见下
/// @param actionParams 行为参数，行为参数是"Key-Value"类型，Key只可以为String类型，只能包含字母、数字和下划线，必须以字母开头，长度不能超过255；Value可以是String/Number/Boolean/JSONArray其中一种，当Value为JSONArray时，它的元素只能为String/Number/Boolean中的一种，且所有元素必须是同一个类型
+ (void)zl_logAction:(NSString *)actionName actionParams:(NSDictionary *)actionParams;


/// 用户完成注册调用
/// @param method 用户注册方式, 如注册方式为手机号：method = @"phone" 微信注册：method = @“WeChat” 邮箱：method = @"mail"等
/// @param isSuccess 注册结果 是否成功
+ (void)zl_reportRegisterActionWithMethod:(NSString *)method isSuccess:(BOOL)isSuccess;

/// 用户登录调用
/// @param method 登录方式
/// @param isSuccess 登录结果
+ (void)zl_reportLoginActionWithMethod:(NSString *)method isSuccess:(BOOL)isSuccess;


/// 绑定社交账号调用
/// @param type 社交账号类型 如如微信、微博等
/// @param isSuccess 是否绑定成功
+ (void)zl_reportBindSocialAccountActionWithType:(NSString *)type isSuccess:(BOOL)isSuccess;


/// 查看内容/商品详情时调用此接口
/// @param type 内容类型如“配备”、“皮肤”
/// @param name 商品或内容名称
/// @param contentID 商品或内容标识符
+ (void)zl_reportViewContentActionWithContentType:(NSString *)type contentName:(NSString *)name contentID:(NSString *)contentID;

/// 提交购买/下单时调用此接口
/// @param type 内容类型如“配备”、“皮肤"
/// @param name 商品或内容名称
/// @param contentID 商品或内容标识符
/// @param number 商品数量
/// @param isVirtualCurrency 是否使用的是虚拟货币
/// @param virtualCurrencyType 虚拟货币类型，如"元宝"、“金币”等
/// @param realCurrencyType 真实货币类型，ISO 4217代码，如：“USD”
/// @param isSuccess 提交购买/下单是否成功
+ (void)reportCheckoutActionWithContentType:(NSString *)type contentName:(NSString *)name contentID:(NSString *)contentID contentNumber:(NSUInteger)number isVirtualCurrency:(BOOL)isVirtualCurrency virtualCurrencyType:(NSString *)virtualCurrencyType realCurrencyType:(NSString *)realCurrencyType isSuccess:(BOOL)isSuccess;


/// 支付时调用此接口
/// @param type 内容类型如“配备”、“皮肤”
/// @param name 商品或内容名称
/// @param contentID 商品或内容标识符
/// @param number 商品数量
/// @param channel 支付渠道名，如支付宝、微信等
/// @param realCurrency 真实货币类型，ISO 4217代码，如：“USD”
/// @param amount 本次支付的真实货币的金额
/// @param isSuccess 支付是否成功
+ (void)reportPurchaseActionWithContentType:(NSString *)type contentName:(NSString *)name contentID:(NSString *)contentID contentNumber:(NSUInteger)number paymentChannel:(NSString *)channel realCurrency:(NSString *)realCurrency currencyAmount:(unsigned long long)amount isSuccess:(BOOL)isSuccess;
@end

NS_ASSUME_NONNULL_END
