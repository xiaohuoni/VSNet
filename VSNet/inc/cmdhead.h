#ifndef __CMD_HEAD_H_
#define __CMD_HEAD_H_

//nvs
#define CGI_BINDNVS 10000
#define CGI_GETNVSSCENE 20
#define CGI_AddParameter 10020
#define CGI_NvsPartsList 10
#define CGI_NvsToPlay 30
#define CGI_NvsDoToPlay 131
#define CGI_NvsSencelistNow 22
#define CGI_NvsControlSence 120
#define CGI_NvsOneDevStatus 110
#define CGI_NvsControlDev 111



//IE CGI CMD
#define CGI_IEGET_STATUS			0x6001
#define CGI_IEGET_PARAM				0x6002
#define CGI_IEGET_CAM_PARAMS		0x6003
#define CGI_IEGET_LOG				0x6004
#define CGI_IEGET_MISC				0x6005
#define CGI_IEGET_RECORD			0x6006
#define CGI_IEGET_RECORD_FILE		0x6007
#define CGI_IEGET_WIFI_SCAN			0x6008
#define CGI_IEGET_FACTORY			0x6009
#define CGI_IESET_IR				0x600a
#define CGI_IESET_UPNP				0x600b
#define CGI_IESET_ALARM				0x600c
#define CGI_IESET_LOG				0x600d
#define CGI_IESET_USER				0x600e
#define CGI_IESET_ALIAS				0x600f
#define CGI_IESET_MAIL				0x6010
#define CGI_IESET_WIFI				0x6011
#define CGI_CAM_CONTROL				0x6012
#define CGI_IESET_DATE				0x6013
#define CGI_IESET_MEDIA				0x6014
#define CGI_IESET_SNAPSHOT			0x6015
#define CGI_IESET_DDNS				0x6016
#define CGI_IESET_MISC				0x6017
#define CGI_IEGET_FTPTEST			0x6018
#define CGI_DECODER_CONTROL			0x6019
#define CGI_IESET_DEFAULT			0x601a
#define CGI_IESET_MOTO				0x601b
#define CGI_IEGET_MAILTEST			0x601c
#define CGI_IESET_MAILTEST			0x601d
#define CGI_IEDEL_FILE				0x601e
#define CGI_IELOGIN                 0x601f
#define CGI_IESET_DEVICE			0x6020
#define CGI_IESET_NETWORK			0x6021
#define CGI_IESET_FTPTEST			0x6022
#define CGI_IESET_DNS				0x6023
#define CGI_IESET_OSD				0x6024
#define CGI_IESET_FACTORY			0x6025
#define CGI_IESET_PPPOE				0x6026
#define CGI_IEREBOOT				0x6027
#define CGI_IEFORMATSD				0x6028
#define CGI_IESET_RECORDSCH			0x6029
#define CGI_IESET_WIFISCAN			0x602a
#define CGI_IERESTORE				0x602b
#define CGI_IESET_FTP				0x602c
#define CGI_IESET_RTSP				0x602d
#define CGI_IEGET_VIDEOSTREAM		0x602e
#define CGI_UPGRADE_APP				0x602f
#define CGI_UPGRADE_SYS				0x6030
#define CGI_CHECK_USER              0x60a0
#define CGI_SENSOR_LIST             0x60b6
#define CGI_SENSOR_ALARM_FILE       0x60b5
#define CGI_SENSOR_STATUS           0x60b2
#define CGI_SENSOR_DELETE_STATUS    0x60b3
#define CGI_SENSOR_ALARM            0x6040
#define CGI_SENSOR_OPENCODE         0x60b1
#define CGI_SENSOR_WHITELIST        0x60b8
#define CGI_SENSOR_GETPRESET        0x60b9
#define CGI_GET_CAMERA_LIST         0x60BC
#define CGI_PUSH_ALARMSERVER        0x6009
#define CGI_MUSIC_OPERATION         0x60d1


#define STREAM_CODEC_TYPE   0x6040
#define STREAM_CODEC_TYPE_JPEG 0
#define STREAM_CODEC_TYPE_H264 1

#define CGI_SET_IIC				0x6031
#define CGI_GET_IIC				0x6032

#define CGI_IEGET_ALARMLOG			0x6033
#define CGI_IESET_ALARMLOGCLR		0X6034

#define CGI_IEGET_SYSWIFI                      	0x6035
#define CGI_IESET_SYSWIFI                   	0X6036

#define CGI_IEGET_LIVESTREAM                    0X6037
 

////视频参数
//typedef struct tag_STRU_CAMERA_PARAM
//{
//    int resolution;
//    int bright;
//    int contrast;
//    int hue;
//    int saturation;
//    int osdenable;
//    int mode;
//    int flip;
//    int enc_framerate;
//    int sub_enc_framerate;
//}STRU_CAMERA_PARAM,*PSTRU_CAMERA_PARAM;
//
//typedef struct _stBcastParam
//{
//	char            szIpAddr[16];		//IP地址
//	unsigned char            szMask[16];		//子网掩码
//	char            szGateway[16];		//网关
//	char            szDns1[16];		//dns1
//	char            szDns2[16];		//dns2
//	char            szMacAddr[6];		//设备MAC地址
//	unsigned short          nPort;			//设备端口
//	char            dwDeviceID[32]; 		//platform deviceid
//	char            szDevName[32];		//设备名称
//	char            sysver[16];		//固件版本
//	char            appver[16];		//软件版本
//	char            szUserName[32];		//修改时会对用户认证
//	char            szPassword[32];		//修改时会对用户认证
//	char            sysmode;        		//0->baby 1->HDIPCAM
//	char            other[3];       		//other
//	char            other1[20];     		//other1
//	
//}BCASTPARAM, *PBCASTPARAM;


#endif

