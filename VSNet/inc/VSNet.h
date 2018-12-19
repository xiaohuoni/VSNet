//
//  VSNet.h
//  vsNet
//
//  Created by 莫晓文 on 16/6/14.
//  Copyright © 2016年 莫晓文. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "VSNetProtocol.h"

@interface VSNet : NSObject

+ (VSNet *)shareinstance;
#pragma mark /**************************初始化接口************************************/
- (void)PPPP_Initialize;

- (void)PPPP_DeInitialize;

- (void) RussP2P;

- (void) Eye4P2P;

- (void) ELSOP2P;

- (void) XQP2P_Initialize;

- (void) XQP2P_DeInitialize;

- (int) XQP2P_GetAPIVersion;

- (void) XQP2P_NetworkDetect;

#pragma mark /**************************连接与断开连接设备的接口************************************/
/**
 *  开始链接指定设备
 *  @param deviceIdentity 设备id
 *  @param user           用户名
 *  @param pwd            密码
 *  @param initializeStr  P2P串（此值尽量不要空，“前4个字符决定固定串”都应有固定的串，如果空了首次连接可能会失败）
 *  @param LanSearch      指定服务器
 *  @return true or false
 */
- ( BOOL ) start:(NSString*) deviceIdentity withUser:( NSString*)user withPassWord:(NSString*)pwd initializeStr:(NSString *)initializeStr LanSearch:(int) nEnable ;

/**
 *  开始链接指定设备（用于低功耗设备快速连接）
 *  @param deviceIdentity 设备id
 *  @param user           用户名
 *  @param pwd            密码
 *  @param initializeStr  P2P串（此值尽量不要空，“前4个字符决定固定串”设备都应有固定的串，如果空了首次连接可能会失败）
 *  @param LanSearch      指定服务器
 *  @return true or false
 */
- ( BOOL ) startLiteos:(NSString*) deviceIdentity withUser:( NSString*)user withPassWord:(NSString*)pwd initializeStr:(NSString *)initializeStr LanSearch:(int) nEnable ;

/**
 *  停止链接指定设备
 *  @param deviceIdentity 设备id
 *  @return true or false
 */
- ( BOOL ) stop:(NSString*) deviceIdentity;

/**
 *  停止所有设备的链接
 *  @return true or false
 */
- ( void ) stopAll;

#pragma mark /**************************设置代理接口************************************/
/**
 *  设置状态代理 设备状态通知
 *  @param deviceIdentity 设备id
 *  @param delegate       代理
 *  @return true or false
 */
- ( BOOL ) setStatusDelegate: (NSString*) deviceIdentity  withDelegate: (id<VSNetStatueProtocol>) delegate;

/**
 *  设置参数代理，发送指令后设备回复
 *  @param deviceIdentity 设备id
 *  @param delegate       代理
 *  @return true or false
 */
- ( BOOL ) setControlDelegate: (NSString*) deviceIdentity withDelegate: (id<VSNetControlProtocol>) delegate;

/**
 *  设置对码代理
 *  @param deviceIdentity 设备id
 *  @param delegate       代理
 *  @return true or false
 */
- ( BOOL ) setDuimaDelegate: (NSString*) deviceIdentity withDelegate: (id<VSNetDuimaProtocol>) delegate;

/**
 *  设置报警代理
 *  @param deviceIdentity 设备id
 *  @param delegate       代理
 *  @return true or false
 */
- ( BOOL ) setAlarmDelegate: (NSString*) deviceIdentity withDelegate: (id <VSNetAlarmProtocol>) delegate;

/**
 *  设置视频数据代理,视频数据通过改代理返回
 *  @param deviceIdentity 设备id
 *  @param delegate       代理
 *  @return true or false
 */

- ( BOOL ) setDataDelegate: (NSString*) deviceIdentity withDelegate: (id <VSNetDataProtocol>) delegate;

#pragma mark /**************************实时视频接口************************************/
/**
 *  开始预览视频
 *  @param deviceIdentity 设备id
 *  @param stream         主码流 APP定为10
 *  @param substream      子码流 0、1、14、15、16、17、18、19、20、21、22 -> 1280*720
                                2、3、7、8、9、10、11、12 -> 640*360
                                5、6 -> 320*180
 *  @return true or false
 */
- ( BOOL ) startLivestream:(NSString*) deviceIdentity withStream: (int) stream withSubStream: (int) substream;

/**
 *  停止预览视频
 *  @param deviceIdentity 设备id
 *  @return true or false
 */
- ( BOOL ) stopLivestream : (NSString*) deviceIdentity ;

/**
 *  录制当前视频
 *  @param strPath 存放路径
 *  @param deviceIdentity 设备id
 *  @param completion  成功与失败
 */
- (void)StartRecord:(NSString*) strPath cameraUid:(NSString *)deviceIdentity completion:(void (^)(BOOL success, int nError)) returnResult;
//停止录制视频
- (void)StopCameraUid:(NSString *)deviceIdentity;
#pragma mark /**************************发送指令到设备接口************************************/
/**
 *  发送cgi指令
 *  @param cgi            cgi 指令
 *  @param deviceIdentity 设备id
 *  @return true or false
 */
- ( BOOL ) sendCgiCommand: (NSString*) cgi withIdentity: (NSString*) deviceIdentity;

- ( BOOL ) sendCgiCommandWithCgi: (NSString*) cgi withIdentity: (NSString*) deviceIdentity;

#pragma mark /**************************对讲与监听接口************************************/
/**
 *  打开监听
 *  @param deviceIdentity 设备id
 *  @param withEchoCancellationVer 是否支持双向对讲
 */
- ( void ) startAudio:(NSString *) deviceIdentity withEchoCancellationVer:(BOOL)echoCancellationVer;

/**
 *  关闭监听
 *  @param deviceIdentity 设备id
 */
- ( void) stopAudio:(NSString *) deviceIdentity;

/**
 *  打开对讲
 *  @param deviceIdentity 设备id
 *  @param withEchoCancellationVer 是否支持双向对讲
 */
- (void) startTalk:(NSString *) deviceIdentity withEchoCancellationVer:(BOOL)echoCancellationVer;

/**
 *  关闭对讲
 *  @param deviceIdentity 设备id
 */
- (void) stopTalk:(NSString *) deviceIdentity;

#pragma mark/**************************TF卡回放接口beg************************************/
/**
 *  播放 SD 卡
 *  @param deviceIdentity 设备id
 *  @param Name           文件名
 *  @param offset         播放偏移
 *  @param size           文件大小
 *  @param SupportHD      设备是否支持1440高清 0不支持，1支持
 *  @param delegate      @protocol TFCardProtocol
 */
- (void) startPlayBack:(NSString *)deviceIdentity fileName:(NSString *)Name withOffset:(NSInteger)offset fileSize:(NSInteger) size delegate:(id) delegate SupportHD:(int) isHD;
/**
 *  录制TF卡
 *  @param deviceIdentity 设备id
 *  @param fileName       录制文件存放路
 * @param width          视频宽
 * @param height         视频高
 */
- (void) startRcrodTF:(NSString *)deviceIdentity fileName:(NSString *)strRecordPath width:(int)videoW height:(int)videoH ;
//停止录制TF卡
- (void) stopRcrodTF:(NSString *)deviceIdentity ;
//拖动回放进度
- (NSInteger) movePlaybackPos:(NSString *)deviceIdentity POS:(float) fos ;
//根据拖动回放进度去设置回放进度
- (void) setPlaybackPos:(NSString *)deviceIdentity time:(NSUInteger) time ;
/**
 *  停止播放 SD 卡
 *
 *  @param deviceIdentity 设备id
 */
- (void) stopPlayBack:(NSString *)deviceIdentity ;

/**
 *  暂停回放
 *  @param deviceIdentity 设备id
 *  @param isPause      0:暂停回放与录制 1:恢复回放与录制 2:暂停回放 3:恢复回放 4:暂停录制 5:恢复录制
 */
- (void) PausePlayback:(NSString *)deviceIdentity pause:(int) isPause;

#pragma mark/**************************TF卡回放接口end************************************/

#pragma mark/**************************低功耗设备端接口beg************************************/
//置前台需要连接服务器
- (int)MagLowpowerDeviceConnect:(NSString*) strIP;
//置后台需要断开服务器
- (void)MagLowpowerDeviceDisconnect;

- (void)setLowpowerDeviceDelegate: (id <LowpowerDeviceProtocol>) delegate;

- (int)GetConnectStatus;

//初化设备
- (int)MagLowpowerInitDevice:(NSString *)deviceIdentity;
//取设备状态
- (int)MagLowpowerGetDeviceStatus:(NSString *)deviceIdentity;
//唤醒设备
- (int)MagLowpowerAwakenDevice:(NSString *)deviceIdentity;
#pragma mark/**************************低功耗设备端接口end************************************/

#pragma mark/**************************局域网内搜索在线设备接口********************************/
//开始搜索 delegate是代理，回调搜索到的设备
-(void)StartSearchDVS:(id<VSNetSearchCameraResultProtocol>)delegate;
//停止搜索
-(void)StopSearchDVS;


//h265设备接口改变设备编码器，Operation:0切成h264 1切成H265 2查当前使用的编码器
-(int) SwitchDeviceEncoder:(NSString *)deviceIdentity Operation:(int) opt;
//APP是否进入后台，IsBG=YES:是 IsBG=NO:否
-(void) EnterBackground:(BOOL)IsBG;
//特殊设备指定视频解码回调
- (void)setCameraIsPanorama:(BOOL)isPanorama withUid:(NSString *)deviceIdentity;
//重置视频解码器
- (void)ResetH264Init:(NSString *)deviceIdentity;
@end
