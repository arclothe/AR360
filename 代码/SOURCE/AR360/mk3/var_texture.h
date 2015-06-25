#pragma once
#include "var_parameter.h"


namespace mk3{

extern DllExport void fprintCam(char* filename);				// 打印硬件摄像头信息

class DllExport var_texture{

private:
	void*	m_pKernel;

public:
	var_texture(void);
	~var_texture(void);

	void init_fbo(const int texture_width,const int texture_height);
	void clear_fbo();

	void init_cam(const int CamID);
	void clear_cam();

	static void init_objs(const char* filename);
	static void clear_objs();

	typedef void vrFunc();								// 虚拟现实函数指针
	typedef void arFunc(int obj_id, double gl_para[16]);// 增强现实函数指针
	void set_vrFunc(vrFunc f);
	void set_arFunc(arFunc f);

	void rtt_vr();
	void rtt_ar();
	void rtt_cam();

	void operator==(var_texture& that_ref);	//	自动校正
	void manual_calibr(int x,int y);		//	手动校正
	
	void camera_update();
	void calibrate_roi();
	void draw_keypoint();

	void bind_texture();
	
	void set_parameter(const parameter* pPara);

};
}
