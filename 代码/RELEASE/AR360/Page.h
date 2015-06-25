#pragma once
#include <irrlicht.h>

// 返回单实例指针
extern irr::IrrlichtDevice*		  s_device();
extern irr::video::IVideoDriver*  s_driver();
extern irr::scene::ISceneManager* s_smgr();
extern irr::gui::IGUIEnvironment* s_guienv();


// 一个使用3D引擎实现的，类页面接口
class IPage{
public:
	// 页面初始化函数，布局在这里完成
	virtual void onInit(void* pData=0) = 0;
	// 渲染流程控制
	virtual void onShow() = 0;
};


#define Ar360						// 为了格式美观而设计的占位符，无意义

#define IRR_NAMESPACE		Ar360					\
	using namespace		irr;						\
	using namespace		core;						\
	using namespace		scene;						\
	using namespace		video;						\
	using namespace		io;							\
	using namespace		gui;


// 指向当前的Page的全局指针,系统内部使用
extern IPage*	_$CurrentPage;

// 清空当前Page内容
inline void ClearPage(){
	s_smgr()->clear();
	s_guienv()->clear();
}

// 跳转到某个Page，可以传递参数
#define JumpPage(PageName,...){							\
	IPage* Page = new PageName;							\
	::ClearPage();										\
	Page->onInit(__VA_ARGS__);							\
	if (_$CurrentPage){									\
		delete _$CurrentPage;							\
		_$CurrentPage =  0;								\
	}													\
	_$CurrentPage = Page;								\
}


// 声明一个新的Page类
#define DeclPage(PageName)	Ar360						\
class PageName :public IPage{							\
	public:												\
		virtual void onInit(void* pData = 0);			\
		virtual void onShow();							\
};

// 一些快速制造Page的工具，初期不建议使用
#include "Quick.inl"