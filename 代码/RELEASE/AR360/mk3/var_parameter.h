#pragma once

#undef DllExport

#ifdef _WINDLL
#define DllExport __declspec(dllexport)
#else
#define DllExport
#endif

namespace mk3{

	struct DllExport parameter{
		// 和 AR 相关的参数
		int		ar_thresh;					// 一般是150
		int		ar_isShowSquare;				// 是否显示正方形
		unsigned char						// scm:square_color_match
			ar_scmR,
			ar_scmG,
			ar_scmB,
			ar_scmA;
		unsigned char						// scn:square_color_not_match
			ar_scnR,
			ar_scnG,
			ar_scnB,
			ar_scnA;


		// 和 SURF 相关的参数
		double  	surf_thresh;			// 过去是5000
		int		circle_num_min;
		int		circle_num_max;
		int		radius_thresh;				// 一般是15
		int		isAutoSurfThresh;

		void setScmRGBA(unsigned int c){
			ar_scmR = ((unsigned char)((c>>24)&0xff));
			ar_scmG = ((unsigned char)((c>>16)&0xff));
			ar_scmB = ((unsigned char)((c>>8)&0xff));
			ar_scmA = ((unsigned char)((c>>0)&0xff));
		}
		void setScnRGBA(unsigned int c){
			ar_scnR = ((unsigned char)((c>>24)&0xff));
			ar_scnG = ((unsigned char)((c>>16)&0xff));
			ar_scnB = ((unsigned char)((c>>8)&0xff));
			ar_scnA = ((unsigned char)((c>>0)&0xff));
		}

		void setDefault(){

			this->ar_thresh = 150;
			this->ar_isShowSquare = true;

			this->ar_scmR = 0x00;
			this->ar_scmG = 0xff;
			this->ar_scmB = 0x00;
			this->ar_scmA = 0xff;

			this->ar_scnR = 0xff;
			this->ar_scnG = 0x00;
			this->ar_scnB = 0x00;
			this->ar_scnA = 0xff;


			this->surf_thresh = 5000;
			this->circle_num_min = 10;
			this->circle_num_max = 20;
			this->radius_thresh = 15;
			this->isAutoSurfThresh = true;

		}

	};
}