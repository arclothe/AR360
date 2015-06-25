
#include "mk3/mk3toolkit.h"
#include "mk3/input_control.h"

#pragma comment (lib ,"mk3.lib")


class Mk3TexSingleton{
	static mk3::var_texture* s_pTex;
public:
	static void init(){

		s_pTex = new mk3::var_texture();
		mk3::parameter pm;
		pm.setDefault();
		pm.ar_thresh = 100;
		s_pTex->init_fbo(640, 480);
		s_pTex->init_cam(0);
		s_pTex->init_objs("Data/object_data2");
		s_pTex->set_parameter(&pm);
	}
	static void uninit(){
		if (s_pTex)
			delete s_pTex;
	}
	static void set_arFunc(mk3::var_texture::arFunc f){
		s_pTex->set_arFunc(f);
	}
	static void update(){
		if (s_pTex){
			s_pTex->camera_update();
			s_pTex->rtt_ar();
		}
	}
};