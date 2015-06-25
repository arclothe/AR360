/*

此文件是对mk3的简单封装，本质是个单实例。

整个Ar360项目访问mk3都通过这个接口。

本想用更好的架构，但实验失败，此架构算是一种妥协

好在并不复杂

*/


#define MK3_Marker_Front_Up			0	// 对Marker的标识，如0代表证明正面上方
#define MK3_Marker_Front_Down		1
#define MK3_Marker_Left_Up			2
#define MK3_Marker_Left_Down		3
#define MK3_Marker_Right_Up			4
#define MK3_Marker_Right_Down		5

#define MK3_Marker_Total_Num		6  // 当前一个衣服上有6个Marker


// 常量，多重marker的信息文件
static const char*  Path_Multi_Marker = "Ar360Res/Marker/multi_marker.txt";

// 常量，校准模型的路径
static const char*  Path_Calibr = "Ar360Res/Calibr/Calibr.obj";

// 常量，摄像头采集图像的尺寸，初期只做标准640，480的
static const int Cam_Width  = 640;
static const int Cam_Height = 480;

// 常量，增强现实的初始阈值，范围是0~255，灯光越强，阈值应该越高
static const int Thresh_Init = 100;

// Mk3 的头文件，及其库
#include "mk3/mk3toolkit.h"
#include "mk3/input_control.h"
#pragma comment (lib ,"mk3.lib")



// Mk3简单封装，单实例，Ar360访问Mk3的接口
class Mk3TexSingleton{
	static mk3::var_texture* s_pTex;
public:
	// 模块组件初始化
	static void init(){

		s_pTex = new mk3::var_texture();
		mk3::parameter pm;
		pm.setDefault();
		pm.ar_thresh = Thresh_Init;
		s_pTex->init_fbo(Cam_Width, Cam_Height);
		s_pTex->init_cam(0);
		s_pTex->init_objs(Path_Multi_Marker);
		s_pTex->set_parameter(&pm);
	}
	// 模块组件清理
	static void uninit(){
		if (s_pTex)
			delete s_pTex;
	}
	// 设置Ar回调函数指针
	static void set_arFunc(mk3::var_texture::arFunc f){
		s_pTex->set_arFunc(f);
	}
	// 更新摄像头，渲染Ar，并更新模型位置
	static void update(){
		if (s_pTex){
			s_pTex->camera_update();
			s_pTex->rtt_ar();
		}
	}
};