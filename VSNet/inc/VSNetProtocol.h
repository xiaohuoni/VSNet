//
//  VSNetProtocol.h
//  vsNet
//
//  Created by 莫晓文 on 16/6/15.
//  Copyright © 2016年 莫晓文. All rights reserved.
//

#ifndef VSNetProtocol_h
#define VSNetProtocol_h
#import "PPPPDefine.h"
#import <CoreVideo/CVPixelBuffer.h>

@protocol VSNetStatueProtocol <NSObject>
/**
 *  状态返回协议
 *  @param deviceIdentity 设备id
 *  @param statusType     状态类型
 *  @param status         状态值
 */
- (void) VSNetStatus: (NSString*) deviceIdentity statusType:(NSInteger) statusType status:(NSInteger) status;
@end


@protocol VSNetControlProtocol <NSObject>

/**
 *  控制返回协议
 *  @param deviceIdentity 设备id
 *  @param comType        命令类型
 *  @param retString      joson返回
 */
- (void) VSNetControl: (NSString*) deviceIdentity commandType:(NSInteger) comType buffer:(NSString*)retString length:(int)length charBuffer:(char *)buffer;

@end

@protocol VSNetDuimaProtocol <NSObject>

/**
 *  对码返回协议
 *  @param deviceIdentity 设备id
 *  @param sensorInfo      返回信息
 */
- (void) VSNetDuimaWithUid: (NSString*) deviceIdentity sensorAlarmInfo:(STRU_SENSOR_ALARM_INFO)sensorInfo;
@end



@protocol VSNetAlarmProtocol <NSObject>

/**
 *  报警返回协议
 *  @param deviceIdentity 设备id
 *  @param comType        报警类型
 *  @param retString      joson返回
 */
- (void) VSNetAlarm: (NSString*) deviceIdentity alarmType:(NSInteger) comType buffer:(NSString*)retString;

@end


@protocol VSNetDataProtocol <NSObject>

/**
 *  yuv数据返回协议
 *  @param deviceIdentity 设备id
 *  @param buff           图像YUV数据
 *  @param len            数据长度
 *  @param height         图像高度
 *  @param width          图像宽度
 *  @param time           设备的UTC时间
 *  @param origenelLen    原始数据大小，此值可用了统计数据量/每秒
 */
- (void) VSNetYuvData: (NSString*) deviceIdentity data:(Byte *) buff withLen:(NSInteger)len
               height:(NSInteger)height width:(NSInteger)width time:(NSUInteger)timestame origenelLen:(NSInteger) oLen;

- (void) VSNetVideoData:(NSString*) deviceIdentity Length:(int) length;

/**
 *  h264数据返回协议
 *  @param deviceIdentity 设备id
 *  @param buff           数据
 *  @param len            数据长度
 *  @param height         图像高度
 *  @param width          图像宽度
 */
- (void) VSNetH264Data: (NSString*) deviceIdentity data:(Byte *) buff withLen:(NSInteger)len
                height:(NSInteger)height width:(NSInteger)width time:(NSUInteger)timestame withType:(NSInteger)type;


/**
 *  h264数据返回协议
 *
 *  @param deviceIdentity 设备id
 *  @param image          数据
 */
- (void) VSNetImageNotify: (NSString*) deviceIdentity withImage: (NSData *)imageData timestamp: (NSInteger)timestamp;

- (void) VSNetParamNotify: (int) paramType params:(void*) params;

- (void) VSNetHardH264Data: (NSString*) deviceIdentity data:(CVPixelBufferRef ) pixeBuffer time:(NSUInteger)timestame origenelLen:(NSInteger) oLen;

//视频缓冲状态
- (void) VSNetVideoBufState: (NSString*) deviceIdentity State:(int)state;
@end

//TF卡回放
@protocol TFCardProtocol <NSObject>
/**
 解码后YUV视频数据回调协议
 @param yuv:        YUV视频数据
 @param length      YUV视频数据长度
 @param width       视频宽       当VType：为-1时，-100代表网络传输断开， -1000代表不支持高清回放
 @param height      视频高
 @param timestamp   视频当前UTC时间
 @param szdid       设备UID
 @param fpos        播放进度0.0~1.0
 @param fCachePospos缓存进度0.0~1.0
 @param VType       编码器：0->h264 1->h265 -1->回放失败
 **/
- (void) TFYUVNotify: (Byte*) yuv length:(int)length width: (int) width height:(int)height timestamp:(unsigned int)timestamp szdid:(NSString*)szdid pos:(float)fpos cachePos:(float)fCachePospos VType:(int)nType;

/**
 解码后MPEG图像回调协议
 @param image:      图像
 @param timestamp   视频当前UTC时间
 @param szdid       设备UID
 @param fpos        播放进度 0.0~1.0
 @param fCachePospos缓存进度 0.0~1.0
 **/
- (void) TFImageNotify: (id)image timestamp: (NSInteger)timestamp szdid:(NSString*)szdid pos:(float)fpos cachePos:(float)fCachePospos ;

/**
 下载TF卡回调协议
 @param ret:   1失败 0：成功
 @param fpos   下载进度 0.0~1.0
 @param szdid  设备UID
 **/
- (void) TFRECORDNotify:(int)ret  pos:(float)fpos szdid:(NSString*)szdid ;
@end

//低功耗设备返回
@protocol LowpowerDeviceProtocol <NSObject>
//nState:9->未知的 10->激活的 11->离线的 12、22->休眠的
-(void) DeviceStateNotify:(NSString*)strUID state:(int) nState;
@end

//搜索设备返回
@protocol VSNetSearchCameraResultProtocol
- (void) VSNetSearchCameraResult:(NSString *)mac Name:(NSString *)name Addr:(NSString *)addr Port:(NSString *)port DID:(NSString*)did;
@end

#endif /* VSNetProtocol_h */
