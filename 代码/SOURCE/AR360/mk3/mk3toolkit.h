#include "var_texture.h"


namespace mk3{

extern DllExport unsigned int initShaderByMem(const char* vShaderCode, const char* fShaderCode);
extern DllExport unsigned int initShaderByFile(const char* vShaderFile, const char* fShaderFile);

extern DllExport void ArFuncTest( int obj_id, double gl_para[16]);
extern DllExport void vrFuncTestLeft();
extern DllExport void vrFuncTestRight();

static const int   DEFAULT_SCREEN_WIDTH    = 640;
static const int   DEFAULT_SCREEN_HEIGHT   = 480;


extern DllExport void InitWin(
	int argc,char** argv,
	void(*main_loop)(void),
	char* window_name = "mk3 window",
	int width=DEFAULT_SCREEN_WIDTH, 
	int height=DEFAULT_SCREEN_HEIGHT, 
	int x=100,
	int y=100);
extern DllExport void MainLoop();
extern DllExport void BeginRender(
	int width=DEFAULT_SCREEN_WIDTH, 
	int height=DEFAULT_SCREEN_HEIGHT);
extern DllExport void EndRender();

extern DllExport void MergeSquare();
extern DllExport void NormalSquare();


class DllExport toolkit{

private:

	mk3::var_texture m_arTextureLeft;
	mk3::var_texture m_arTextureRight;
	int				 m_shaderProgram;

public:

	toolkit();
	~toolkit();

	void init(
		const char* filename,
		var_texture::arFunc af = 0,
		var_texture::vrFunc vfl = 0,
		var_texture::vrFunc vfr = 0, 
		int camID0 = 1, 
		int camID1 = 2);
	void clear();

	void set_vrFunc(var_texture::vrFunc fl,var_texture::vrFunc fr){
		m_arTextureLeft.set_vrFunc(fl);
		m_arTextureRight.set_vrFunc(fr);
	}
	void set_arFunc(var_texture::arFunc f){
		m_arTextureLeft.set_arFunc(f);
		m_arTextureRight.set_arFunc(f);
	}

	void rtt_vr(){
		m_arTextureLeft.rtt_vr();
		m_arTextureRight.rtt_vr();
	}
	void rtt_ar(){
		m_arTextureLeft.rtt_ar();
		m_arTextureRight.rtt_ar();
	}
	void rtt_cam(){
		m_arTextureLeft.rtt_cam();
		m_arTextureRight.rtt_cam();
	}

	void auto_calibr(){
		m_arTextureLeft == m_arTextureRight;
	}
	void manual_calibr(int manual_calibr_x,int manual_calibr_y){
		m_arTextureLeft.manual_calibr(manual_calibr_x,manual_calibr_y);
		m_arTextureRight.manual_calibr(-manual_calibr_x,-manual_calibr_y);
	}

	void camera_update(){
		m_arTextureLeft.camera_update();
		m_arTextureRight.camera_update();
	}
	void calibrate_roi(){
		m_arTextureLeft.calibrate_roi();
		m_arTextureRight.calibrate_roi();
	}
	void draw_keypoint(){
		m_arTextureLeft.draw_keypoint();
		m_arTextureRight.draw_keypoint();
	}

	void bind_left();
	void bind_right();
	void bind_double();
	void unbind_single();
	void unbind_double();

	void mergeShader();
	void normalShader();

	void set_parameter(const parameter* pPara){
		m_arTextureLeft.set_parameter(pPara);
		m_arTextureRight.set_parameter(pPara);
	}
};
}