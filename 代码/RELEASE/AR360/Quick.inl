#pragma once

// 创建一个事件响应器的单实例
#define GreateSingletonGet(TypeName)	Ar360			\
	static IEventReceiver* Get(){						\
		static TypeName r;								\
		return &r;										\
	}

// 替你制造一个标准的onShow函数，你也可以自己写
// 一般来讲，onShow自动生成就行~ 除非想渲染到纹理啥的。。。
#define CreateStdPageOnShow(PageName)	Ar360			\
	void PageName::onShow(){							\
		IRR_NAMESPACE;									\
		if (s_device()->isWindowActive()){				\
			s_driver()->beginScene(						\
				true, true, SColor(0, 255, 255, 255));	\
			s_smgr()->drawAll();						\
			s_guienv()->drawAll();						\
			s_driver()->endScene();						\
		}												\
	}


// 替你制造一个标准的onInit函数，你也可以自己写
// 一般来讲，除非是及其简单的静态页面可以自动，不然都要手写
#define CreateStdPageOnInit(PageName)	Ar360			\
	void PageName::onInit(void* pData){					\
		s_guienv()->loadGUI(#PageName##".xml");			\
		s_device()->setEventReceiver(					\
						PageName##EventReceiver::Get());\
	}

