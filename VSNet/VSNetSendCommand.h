//
//  VSNetSendCommand.h
//  Eye4
//
//  Created by 莫晓文 on 16/6/27.
//  Copyright © 2016年 莫晓文. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface VSNetSendCommand : NSObject
//设置设备的日期时间
/*
 did: 设备UID
 now: 表示从 1970-1-1 0:0:0 到指定时间所流逝的秒数，如附加该参数，设备则依据此时间进行校时
 tz: 时区设置
 ntp:表示 ntp 校时 0:禁止 1:允许
 ntp_svr:ntp 服务器地址
 */
+ (void) VSNetCommandSetDateTime:(NSString*) did isNow:(NSInteger) now timeZone:(NSInteger) tz npt:(NSInteger) ntp netServer:(NSString*)server;

//传感器设置指令
/*
 *cmd:0 ->布防 1->撤防 2->对码 3->取消对码 4->门铃声音 5->清除全部传感器
 *doorbell:门铃声音开关 0->关闭 1->开启(当 cmd=4 时才有效)
 */
+ (void) VSNetCommandSetSensorStatusWithDID:(NSString *)did cmd:(NSInteger )cmd doorbell:(NSInteger )doorbell user:(NSString *)user password:(NSString *)pwd;
//获取录像文件列表
/*
 *PageSize:一次最大返回录像文件数,默认为 100
 *PageIndex:访问 TF 卡录像文件第 PageIndex 个 PageSize 录像文件,默认为 0
 */
+ (void)VSNetCommandGetRecordFileWithDID:(NSString *)did user:(NSString *)user pwd:(NSString *)pwd loginuse:(NSString *)loginuse loginpas:(NSString *)loginpas pageSize:(NSInteger )pageSize pageIndex:(NSInteger )pageIndex;

//播放SD卡录像或者实时视频
/*
 *
 *
 */
+ (void)VSNetCommandPlayVedioWithStreamid:(NSInteger )streamid
                                     user:(NSString *)user
                                      pwd:(NSString *)pwd
                                 loginuse:(NSString *)loginuse
                                 loginpas:(NSString *)loginpas
                                    audio:(NSInteger )audio
                                      res:(NSInteger )res
                                substream:(NSInteger )substream
                                 filename:(NSString *)filename
                                   offset:(NSInteger )offset
                                      did:(NSString *)did;

@end
