//
//  ViewController.m
//  demopnp
//
//  Created by 陈小聪 on 2018/12/12.
//  Copyright © 2018 陈小聪. All rights reserved.
//

#import "ViewController.h"
#import "VSNetProtocol.h"
#import "PPPPDefine.h"
#import "VSNet.h"
#import "cmdhead.h"

@interface ViewController ()<VSNetStatueProtocol, VSNetControlProtocol, VSNetDataProtocol, UIScrollViewDelegate>
{
    IJKSDLGLView *myGLViewController;
//    IBOutlet UIImageView *imgView;
    IBOutlet UIScrollView *scrollView;
    int m_nScreenHeight;
    int m_nScreenWidth;
}

@property (strong, nonatomic) NSString *strDID;
@property (strong, nonatomic) NSString *strPWD;


@end

@implementation ViewController


- (void)viewDidLoad {
    [super viewDidLoad];
     myGLViewController = nil;
    CGRect getFrame = [[UIScreen mainScreen]applicationFrame];
    m_nScreenHeight = getFrame.size.width;
    m_nScreenWidth = getFrame.size.height;
    scrollView.delegate = self;
    
    _strDID = @"TCXF009750UJFGM";
    _strPWD = @"12345678";
    // Do any additional setup after loading the view, typically from a nib.
    int nRet = [[VSNet shareinstance] start:_strDID withUser:@"admin" withPassWord:_strPWD initializeStr:nil LanSearch:1];
    if(nRet==0){
        __weak __typeof(self) weakSelf  = self;
        //连接不成功，3秒后再试一次
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(3 * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
            
            [[VSNet shareinstance] start:weakSelf.strDID withUser:@"admin" withPassWord:weakSelf.strPWD initializeStr:nil LanSearch:1];
            [[VSNet shareinstance] setStatusDelegate:weakSelf.strDID withDelegate:weakSelf];
            [[VSNet shareinstance] setControlDelegate:weakSelf.strDID withDelegate:weakSelf];
            
            //实时视频
//            [[VSNet shareinstance] startLivestream:weakSelf.strDID withStream:10 withSubStream:2];
//            [[VSNet shareinstance] setDataDelegate:weakSelf.strDID withDelegate:weakSelf];
        });
    }else{
        [[VSNet shareinstance] setStatusDelegate:_strDID withDelegate:self];
        [[VSNet shareinstance] setControlDelegate:_strDID withDelegate:self];
        //实时视频
//        [[VSNet shareinstance] startLivestream:_strDID withStream:10 withSubStream:2];
//        [[VSNet shareinstance] setDataDelegate:_strDID withDelegate:self];
    }
}
//- (IBActuon)play:(id)sender{
//    [[VSNet shareinstance] startLivestream:_strDID withStream:10 withSubStream:2];
//    [[VSNet shareinstance] setDataDelegate:_strDID withDelegate:self];
//}
- (void)VSNetStatus:(NSString *)deviceIdentity statusType:(NSInteger)statusType status:(NSInteger)status{
    NSLog(@"PPPPStatus .... strDID: %@, statusType: %ld ",deviceIdentity,statusType,status);
    if(statusType == MSG_NOTIFY_TYPE_PPPP_STATUS){
        //如果是ID号无效，则停止该设备的P2P
        if( status == PPPP_STATUS_INVALID_ID
            || status == PPPP_STATUS_CONNECT_TIMEOUT
            || status == PPPP_STATUS_DEVICE_NOT_ON_LINE
            || status == PPPP_STATUS_CONNECT_FAILED
            || status == PPPP_STATUS_INVALID_USER_PWD ){
            NSLog(@"设备连接失败");
        }else if( PPPP_STATUS_ON_LINE == status){
            NSLog(@"设备在线");
            //实时视频
            [[VSNet shareinstance] startLivestream:self.strDID withStream:10 withSubStream:2];
            [[VSNet shareinstance] setDataDelegate:self.strDID withDelegate:self];
        }else if( PPPP_STATUS_CONNECTING == status){
            NSLog(@"连接中...");
        }else if( PPPP_STATUS_INITIALING == status){
            NSLog(@"正在初始化");
        }
        return ;
    }
}

- (void)VSNetControl:(NSString *)deviceIdentity commandType:(NSInteger)comType buffer:(NSString *)retString length:(int)length charBuffer:(char *)buffer{
    
    NSLog(@"VSNet返回数据 UID:%@ comtype %ld",deviceIdentity,(long)comType);
    switch (comType) {
        case CGI_IESET_SNAPSHOT:
            
            break;
            
        default:
            break;
    }
}

//- (void) CreateGLView
//{
//    myGLViewController = [[MyGLViewController alloc] init];
//    if ([[UIApplication sharedApplication] statusBarOrientation]== UIInterfaceOrientationLandscapeLeft || [[UIApplication sharedApplication] statusBarOrientation]== UIInterfaceOrientationLandscapeRight) {
//        myGLViewController.view.frame = imgView.frame;//CGRectMake(0, 0, m_nScreenWidth, m_nScreenHeight);
//    }else{
//        myGLViewController.view.frame = imgView.frame;//CGRectMake(0, 224, 768, 576);
//    }
//
//    [self.view addSubview:myGLViewController.view];
////    [self.view bringSubviewToFront:timeoutLabel];
////    [self.view bringSubviewToFront:OSDLabel];
////    [self.view bringSubviewToFront:TimeStampLabel];
////    [self.view bringSubviewToFront:toolBarTop];
////    [self.view bringSubviewToFront:playToolBar];
////    [self.view bringSubviewToFront:labelContrast];
////    [self.view bringSubviewToFront:sliderContrast];
////    [self.view bringSubviewToFront:sliderBrightness];
////    [self.view bringSubviewToFront:labelBrightness];
//
////    [myGLViewController.view addSubview:self.imageDown];
////    [myGLViewController.view addSubview:self.imageUp];
////    [myGLViewController.view addSubview:self.imageLeft];
////    [myGLViewController.view addSubview:self.imageRight];
////
////    [self.view bringSubviewToFront:self.imageDown];
////    [self.view bringSubviewToFront:self.imageLeft];
////    [self.view bringSubviewToFront:self.imageRight];
////    [self.view bringSubviewToFront:self.imageUp];
//
//}

- (void) CreateGLView
{
    if (myGLViewController != nil) {
        return;
    }
    
    myGLViewController = [[IJKSDLGLView alloc] initWithFrame:CGRectMake(0, 0, m_nScreenWidth, m_nScreenHeight)];
    myGLViewController.backgroundColor = [UIColor blackColor];
    myGLViewController.userInteractionEnabled = YES;
    [scrollView addSubview:myGLViewController];
//    [self.view bringSubviewToFront:navigationBar];
//    [self.view bringSubviewToFront:bottomView];
}

- (UIView *)viewForZoomingInScrollView:(UIScrollView *)scrollView{
    if (myGLViewController != nil) {
        return myGLViewController;
    }
    return scrollView;
}

- (void)VSNetYuvData:(NSString *)deviceIdentity data:(Byte *)buff withLen:(NSInteger)len height:(NSInteger)height width:(NSInteger)width time:(NSUInteger)timestame origenelLen:(NSInteger)oLen{
     NSLog(@"VSNet返回数据 buff %ld",(long)buff);
//    if([deviceIdentity isEqualToString:_strDID] == NO ){
//        return;
//    }
    
    [self performSelectorOnMainThread:@selector(CreateGLView) withObject:nil waitUntilDone:NO];
    
    if(myGLViewController){
        SDL_VoutOverlay stOverlay;
        memset(&stOverlay, 0, sizeof(stOverlay));
        stOverlay.w = (int)width;
        stOverlay.h = (int)height;
        stOverlay.pitches[0] = width;
        stOverlay.pitches[1] = stOverlay.pitches[2] = width/2;
        stOverlay.pixels[0]=buff;
        stOverlay.pixels[1]=buff+ width*height;
        stOverlay.pixels[2]=buff+width*height*5/4;
        [myGLViewController display:&stOverlay];
//        [myGLViewController WriteYUVFrame:buff Len:(int)len width:(int)width height:(int)height];
//        SDL_VoutOverlay stOverlay;
//        memset(&stOverlay, 0, sizeof(stOverlay));
//        stOverlay.w = (int)width ;
//        stOverlay.h = (int)height;
//        stOverlay.pitches[0] = width;
//        stOverlay.pitches[1] = stOverlay.pitches[2] = width /2;
//        stOverlay.pixels[0] = yuv;
//        stOverlay.pixels[1] = yuv + width*height;
//        stOverlay.pixels[2] = yuv + width*height*5/4;
//        [myGLViewController display:&stOverlay];
    }
}

//- (void) ptzImageTouched: (UITapGestureRecognizer*)sender
//{
//    UIImageView *imageView = (UIImageView*)[sender view];
//
//    // NSLog(@"ptzImageTouched... tag: %d", imageView.tag);
//    int command = 0;
//    switch (imageView.tag) {
//        case 0: //up
//            command = CMD_PTZ_UP;
//            break;
//        case 1: //down
//            command = CMD_PTZ_DOWN;
//            break;
//        case 2: //left
//            command = CMD_PTZ_LEFT;
//            break;
//        case 3: //right
//            command = CMD_PTZ_RIGHT;
//            break;
//
//        default:
//            return;
//    }
//    //m_pPPPPChannelMgt->PTZ_Control([strDID UTF8String], command);
//    int onestep = 0;
//    NSString *cgi = [NSString stringWithFormat:@"GET /decoder_control.cgi?command=%d&onestep=%d&" ,command, onestep];
//    [[VSNet shareinstance] sendCgiCommand:cgi withIdentity:self.strDID];
//}

- (void) VSNetVideoData:(NSString*) deviceIdentity Length:(int) length{
//     NSLog(@"VSNetVideoData");
}

/**
 *  h264数据返回协议
 *  @param deviceIdentity 设备id
 *  @param buff           数据
 *  @param len            数据长度
 *  @param height         图像高度
 *  @param width          图像宽度
 */
- (void) VSNetH264Data: (NSString*) deviceIdentity data:(Byte *) buff withLen:(NSInteger)len
                height:(NSInteger)height width:(NSInteger)width time:(NSUInteger)timestame withType:(NSInteger)type{
//     NSLog(@"h264数据返回协议VSNetH264Data");
}


/**
 *  h264数据返回协议
 *
 *  @param deviceIdentity 设备id
 *  @param imageData          数据
 */
- (void) VSNetImageNotify: (NSString*) deviceIdentity withImage: (NSData *)imageData timestamp: (NSInteger)timestamp{
//     NSLog(@"h264数据返回协议VSNetImageNotify");
}

- (void) VSNetParamNotify: (int) paramType params:(void*) params{
//     NSLog(@"VSNetParamNotify");
}

- (void) VSNetHardH264Data: (NSString*) deviceIdentity data:(CVPixelBufferRef ) pixeBuffer time:(NSUInteger)timestame origenelLen:(NSInteger) oLen{
//    NSLog(@"VSNetHardH264Data");
}

//视频缓冲状态
- (void) VSNetVideoBufState: (NSString*) deviceIdentity State:(int)state{
    
//     NSLog(@"视频缓冲状态");
}


@end
