//
//  ZLGDTAction.m
//  GDTActionDemo
//
//  Created by Twisted Fate on 2020/2/23.
//  Copyright © 2020 Twisted Fate. All rights reserved.
//

#import "ZLGDTAction.h"
#import "GDTAction.h"
#import "GDTAction+convenience.h"

static NSString *const kZLGDTActionId = @"";
static NSString *const kZLGDTActionKey = @"";

@implementation ZLGDTAction

- (void)initGDT {
    [GDTAction init:kZLGDTActionId secretKey:kZLGDTActionKey];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(applicationDidBecomeActive:) name:UIApplicationDidBecomeActiveNotification object:nil];
}
 
- (void)applicationDidBecomeActive {
    [ZLGDTAction zl_logAction:GDTSDKActionNameStartApp actionParams:@{@"value":@(123)}];
}


+ (void)zl_logAction:(NSString *)actionName actionParams:(NSDictionary *)actionParams {
    [GDTAction logAction:actionName actionParam:actionParams];
}

+ (void)zl_reportLoginActionWithMethod:(NSString *)method isSuccess:(BOOL)isSuccess {
    [GDTAction reportRegisterActionWithMethod:method isSuccess:isSuccess];
}

+ (void)zl_reportBindSocialAccountActionWithType:(NSString *)type isSuccess:(BOOL)isSuccess {
    [GDTAction reportBindSocialAccountActionWithType:type isSuccess:isSuccess];
}

+ (void)zl_reportViewContentActionWithContentType:(NSString *)type contentName:(NSString *)name contentID:(NSString *)contentID {
    [GDTAction reportViewContentActionWithContentType:type contentName:name contentID:contentID];
}
@end
