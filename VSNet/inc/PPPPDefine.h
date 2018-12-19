
#ifndef _PPPP_DEFINE_H_
#define _PPPP_DEFINE_H_

//Message type
#define MSG_TYPE_P2P_STATUS         0x0
#define MSG_TYPE_P2P_MODE           0x1
#define MSG_TYPE_GET_CAMERA_PARAMS  0x2
#define MSG_TYPE_DECODER_CONTROL    0x3
#define MSG_TYPE_GET_PARAMS         0x4
#define MSG_TYPE_SNAPSHOT           0x5
#define MSG_TYPE_CAMERA_CONTROL     0x6
#define MSG_TYPE_SET_NETWORK        0x7
#define MSG_TYPE_REBOOT_DEVICE      0x8
#define MSG_TYPE_RESTORE_FACTORY    0x9
#define MSG_TYPE_SET_USER           0xa
#define MSG_TYPE_SET_WIFI           0xb
#define MSG_TYPE_SET_DATETIME       0xc
#define MSG_TYPE_GET_STATUS         0xd
#define MSG_TYPE_GET_PTZ_PARAMS     0xe
#define MSG_TYPE_SET_DDNS           0xf
#define MSG_TYPE_SET_MAIL           0x10
#define MSG_TYPE_SET_FTP            0x11
#define MSG_TYPE_SET_ALARM          0x12
#define MSG_TYPE_SET_PTZ            0x13
#define MSG_TYPE_WIFI_SCAN          0x14
#define MSG_TYPE_GET_ALARM_LOG      0x15
#define MSG_TYPE_GET_RECORD         0x16
#define MSG_TYPE_GET_RECORD_FILE    0x17
#define MSG_TYPE_SET_PPPOE          0x18
#define MSG_TYPE_SET_UPNP           0x19
#define MSG_TYPE_DEL_RECORD_FILE    0x1a
#define MSG_TYPE_SET_MEDIA          0x1b
#define MSG_TYPE_SET_RECORD_SCH     0x1c
#define MSG_TYPE_CLEAR_ALARM_LOG    0x1d
#define MSG_TYPE_WIFI_PARAMS        0x1f
#define MSG_TYPE_MAIL_PARAMS        0x20
#define MSG_TYPE_FTP_PARAMS         0x21
#define MSG_TYPE_NETWORK_PARAMS     0x22
#define MSG_TYPE_USER_INFO          0x23
#define MSG_TYPE_DDNS_PARAMS        0x24
#define MSG_TYPE_DATETIME_PARAMS    0x25
#define MSG_TYPE_ALARM_PARAMS       0x26
#define MSG_TYPE_SET_DEVNAME        0x27
#define MSG_TYPE_ALARM_NOTIFY       0x28
#define MSG_TYPE_SET_SENSOR_STATUS  0x29
#define MSG_TYPE_GET_SENSOR_STATUS  0x30
#define MSG_TYPE_DELETE_SENSOR      0x31
#define MSG_TYPE_EDIT_SENSOR        0x32
#define MSG_TYPE_GET_SENSOR_ALARM   0x33
#define MSG_TYPE_GET_SENSOR_LIST    0x34
#define MSG_TYPE_SET_PRESET_SENSOR  0x35//设置与传感器对应的预置位
#define MSG_TYPE_EDIT_SENSOR_WHITELIST 0x36
#define MSG_TYPE_SENSOR_GET_PRESET  0x37
#define MSG_TYPE_ALARMLOG           0x38

#define MSG_TYPE_GET_NVS_CAMERA     0x39

#define MSG_TYPE_SET_FACTORY_PUSH   0x40  //VSTZPF03
#define MSG_TYPE_GET_FACTORY_PARAM  0x41
#define MSG_TYPE_SET_PARAMS_AUDIO   0x42
#define MSG_TYPE_GET_MUSIC_PARAMETER   0x43
#define MSG_TYPE_GET_MUSIC_TENOERATYRE  0x44
#define MSG_TYPE_GET_CRY_CAMERA  0x45

//alarm notify
#define ALARM_MOTION    0x1
#define ALARM_IO    0x2

//decoder control command
#define CMD_PTZ_UP                      0
#define CMD_PTZ_UP_STOP                 1
#define CMD_PTZ_DOWN                    2
#define CMD_PTZ_DOWN_STOP               3
#define CMD_PTZ_LEFT                    4
#define CMD_PTZ_LEFT_STOP               5
#define CMD_PTZ_RIGHT                   6
#define CMD_PTZ_RIGHT_STOP              7

#define CMD_PTZ_CENTER                  25
#define CMD_PTZ_UP_DOWN                 26
#define CMD_PTZ_UP_DOWN_STOP            27
#define CMD_PTZ_LEFT_RIGHT              28
#define CMD_PTZ_LEFT_RIGHT_STOP         29

#define CMD_PTZ_LEFT_UP                 90
#define CMD_PTZ_RIGHT_UP                91
#define CMD_PTZ_LEFT_DOWN               92
#define CMD_PTZ_RIGHT_DOWN              93

#define CMD_PTZ_PREFAB_BIT_SET0         30
#define CMD_PTZ_PREFAB_BIT_SET1         32
#define CMD_PTZ_PREFAB_BIT_SET2         34
#define CMD_PTZ_PREFAB_BIT_SET3         36
#define CMD_PTZ_PREFAB_BIT_SET4         38
#define CMD_PTZ_PREFAB_BIT_SET5         40
#define CMD_PTZ_PREFAB_BIT_SET6         42
#define CMD_PTZ_PREFAB_BIT_SET7         44
#define CMD_PTZ_PREFAB_BIT_SET8         46
#define CMD_PTZ_PREFAB_BIT_SET9         48
#define CMD_PTZ_PREFAB_BIT_SETA         50
#define CMD_PTZ_PREFAB_BIT_SETB         52
#define CMD_PTZ_PREFAB_BIT_SETC         54
#define CMD_PTZ_PREFAB_BIT_SETD         56
#define CMD_PTZ_PREFAB_BIT_SETE         58
#define CMD_PTZ_PREFAB_BIT_SETF         60

#define CMD_PTZ_PREFAB_BIT_RUN0         31
#define CMD_PTZ_PREFAB_BIT_RUN1         33
#define CMD_PTZ_PREFAB_BIT_RUN2         35
#define CMD_PTZ_PREFAB_BIT_RUN3         37
#define CMD_PTZ_PREFAB_BIT_RUN4         39
#define CMD_PTZ_PREFAB_BIT_RUN5         41
#define CMD_PTZ_PREFAB_BIT_RUN6         43
#define CMD_PTZ_PREFAB_BIT_RUN7         45
#define CMD_PTZ_PREFAB_BIT_RUN8         47
#define CMD_PTZ_PREFAB_BIT_RUN9         49
#define CMD_PTZ_PREFAB_BIT_RUNA         51
#define CMD_PTZ_PREFAB_BIT_RUNB         53
#define CMD_PTZ_PREFAB_BIT_RUNC         55
#define CMD_PTZ_PREFAB_BIT_RUND         57
#define CMD_PTZ_PREFAB_BIT_RUNE         59
#define CMD_PTZ_PREFAB_BIT_RUNF         61

//msgtype
#define MSG_NOTIFY_TYPE_PPPP_STATUS 0   /* 设备连接状态 */
#define MSG_NOTIFY_TYPE_PPPP_MODE 1   /* pppp mode */

//设备连接状态
#define PPPP_STATUS_CONNECTING 0 /* connecting 正在连接中*/
#define PPPP_STATUS_INITIALING 1 /* initialing 正在初始化*/
#define PPPP_STATUS_ON_LINE 2 /* on line 在线状态*/
#define PPPP_STATUS_CONNECT_FAILED 3 /* connect failed 连接失败*/
#define PPPP_STATUS_DISCONNECT 4 /*connect is off 断开连接*/
#define PPPP_STATUS_INVALID_ID 5 /* invalid id 无效ID*/
#define PPPP_STATUS_DEVICE_NOT_ON_LINE 6 /* invalid id 不在线状态*/
#define PPPP_STATUS_CONNECT_TIMEOUT 7 /* connect timeout 连接超时*/
#define PPPP_STATUS_INVALID_USER_PWD 8 /*user or pwd is invalid 用户名或者密码错误*/

#define PPPP_STATUS_VIDEO_DATA_BUF_B 100 //视频卡缓冲数据开始
#define PPPP_STATUS_VIDEO_DATA_BUF_E 101 //视频卡缓冲数据结束

#define PPPP_STATUS_UNKNOWN 0xffffff //未知

//显示转发模式最后十秒的提示
#define PPPP_STATUS_RELAY_PLAYEND 9//转发观看模式结束
#define PPPP_STATUS_RELAY_TIMEOUT 10

#define PPPP_SENSOR_CANCELALARM @0
#define PPPP_SENSOR_NONCANCELALARM @1

//Sensor Status
#define PPPP_SENSOR_NONALARM 0
#define PPPP_SENSOR_ALARMING 1

#define PPPP_SENSOR_NONLOWBATT 0
#define PPPP_SENSOR_LOWBATT 1

#define PPPP_LOWBATT_KEY @"PPPPLOWBATTKEY"
#define PPPP_LOWBATT_VALUE @"PPPPLOWBATTVALUE"

#define PPPP_SENSOR_GARRISON 1
#define PPPP_SENSOR_CANCELGARRISON 0

#define PPPP_SENSOR_OPENDOOR @1
#define PPPP_SENSOR_CLOSEDOOR @(-1)
#define PPPP_SENSOR_DOORUNKOWN @0

//pppp mode
#define PPPP_MODE_P2P 1
#define PPPP_MODE_RELAY 2
#define PPPP_MODE_UNKNOWN 0xffffff

//PPPP SD Status
#define PPPP_SDCARD_STATUS_NON 0 /*没有SD卡*/
#define PPPP_SDCARD_STATUS_RECORDING 1 /*SD正在录像*/
#define PPPP_SDCARD_STATUS_STOP_RECORD 2 /*SD停止录像*/

typedef struct tag_STRU_SENSOR_ALARM_INFO{
    int cmd;/*#define ALARM_INFO_PUT_ALARM_INFO   0x01
             #define ALARM_LINK_SNAP_PICTURE     0x02
             #define ALARM_STATUS_INFO_RETURN    0x03*/
    int SensorID[3];
    int LinkPreset;
    char SensorName[64];
    int Sensortype;
    int SensorAction;
    int channel;//通道号
}STRU_SENSOR_ALARM_INFO, *PSTRU_SENSOR_ALARM_INFO;
#endif


