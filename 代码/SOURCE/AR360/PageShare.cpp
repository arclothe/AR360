#include "ALL_PAGE.h"
IRR_NAMESPACE

// GUI ID 的枚举
enum{
	GUI_ID_BUTTON_BACK_TO_INDEX,
	GUI_ID_BUTTON_RENREN,
	GUI_ID_BUTTON_QQ,
	GUI_ID_BUTTON_SINA,
	GUI_ID_BUTTON_YES,
	GUI_ID_BUTTON_CANCEL
};

class PageShareEventReceiver : public IEventReceiver{
private:
		IGUIEditBox* account;
		IGUIEditBox* password;
public:
	GreateSingletonGet(PageShareEventReceiver)

		// 对GUI事件的处理
		bool onGUIEvent(const SEvent& event){
			IGUIWindow* win;

			switch (event.GUIEvent.EventType){
			case EGET_BUTTON_CLICKED:
				switch (event.GUIEvent.Caller->getID()){
				case GUI_ID_BUTTON_BACK_TO_INDEX:
					JumpPage(PageIndex);
					return true;
				case GUI_ID_BUTTON_QQ:
					win=s_guienv()->addWindow(rect<s32>(100,100,400,300),true,L"Please input you message");
					s_guienv()->addButton(rect<s32>(100,150,150,180),win,GUI_ID_BUTTON_YES,L"YES");
					s_guienv()->addButton(rect<s32>(160,150,210,180),win,GUI_ID_BUTTON_CANCEL,L"CANCEL");
					s_guienv()->addStaticText(L"Account:",rect<s32>(10,55,50,80),false,true,win);
					s_guienv()->addStaticText(L"Pass:",rect<s32>(10,105,50,130),false,true,win);
					account=s_guienv()->addEditBox(L"",rect<s32>(60,50,260,80),true,win);
					password=s_guienv()->addEditBox(L"",rect<s32>(60,100,260,130),true,win);
					password->setPasswordBox(true);
					return true;
				case GUI_ID_BUTTON_RENREN:
					win=s_guienv()->addWindow(rect<s32>(100,100,400,300),true,L"Please input you message");
					s_guienv()->addButton(rect<s32>(100,150,150,180),win,GUI_ID_BUTTON_YES,L"YES");
					s_guienv()->addButton(rect<s32>(160,150,210,180),win,GUI_ID_BUTTON_CANCEL,L"CANCEL");
					s_guienv()->addStaticText(L"Account:",rect<s32>(10,55,50,80),false,true,win);
					s_guienv()->addStaticText(L"Pass:",rect<s32>(10,105,50,130),false,true,win);
					account=s_guienv()->addEditBox(L"",rect<s32>(60,50,260,80),true,win);
					password=s_guienv()->addEditBox(L"",rect<s32>(60,100,260,130),true,win);
					password->setPasswordBox(true);
					return true;
				case GUI_ID_BUTTON_SINA:
					win=s_guienv()->addWindow(rect<s32>(100,100,400,300),true,L"Please input you message");
					s_guienv()->addButton(rect<s32>(100,150,150,180),win,GUI_ID_BUTTON_YES,L"YES");
					s_guienv()->addButton(rect<s32>(160,150,210,180),win,GUI_ID_BUTTON_CANCEL,L"CANCEL");
					s_guienv()->addStaticText(L"Account:",rect<s32>(10,55,50,80),false,true,win);
					s_guienv()->addStaticText(L"Pass:",rect<s32>(10,105,50,130),false,true,win);
					account=s_guienv()->addEditBox(L"",rect<s32>(60,50,260,80),true,win);
					password=s_guienv()->addEditBox(L"",rect<s32>(60,100,260,130),true,win);
					password->setPasswordBox(true);
					return true;
				case GUI_ID_BUTTON_YES:
					s_guienv()->addMessageBox(L"lala",account->getText(),true);
					return true;
				default:
					return false;
				}//switch ID
				break;
			default:
				break;
			}//switch TYPE
		}

	// 这个是必须要有的
	virtual bool OnEvent(const SEvent& event){
		if (event.EventType == EET_GUI_EVENT){
			onGUIEvent(event);
		}
		return false;
	}
};

void PageShare::onInit(void* pData){

	s_device()->setEventReceiver(PageShareEventReceiver::Get());

	s_device()->setWindowCaption(L"PageShare");

	s_guienv()->addStaticText(L"Welcome to PageShare",
		rect<s32>(10, 10, 500, 50), true);
	s_guienv()->addButton(rect<s32>(550,400,600,450),0,GUI_ID_BUTTON_RENREN)->setImage(s_driver()->getTexture("Ar360Res/UI/人人.bmp"));
	s_guienv()->addButton(rect<s32>(480,400,530,450),0,GUI_ID_BUTTON_QQ)->setImage(s_driver()->getTexture("Ar360Res/UI/空间.bmp"));
	s_guienv()->addButton(rect<s32>(410,400,460,450),0,GUI_ID_BUTTON_SINA)->setImage(s_driver()->getTexture("Ar360Res/UI/微博.bmp"));
	//s_guienv()->addImage(s_driver()->getTexture("res/Share.bmp"),
	//	position2d<int>(10, 20));

	s_guienv()->addButton(rect<s32>(10, 400, 110, 400 + 32), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"description:Back");
	//loadGUIload
}


CreateStdPageOnShow(PageShare)
