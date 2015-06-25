#include "ALL_PAGE.h"


enum{
	GUI_ID_BUTTON_DRESS,
	GUI_ID_BUTTON_BUY,
	GUI_ID_BUTTON_SHARE,
	GUI_ID_BUTTON_RECOMM,
	GUI_ID_BUTTON_TEST3D
};


IRR_NAMESPACE
class PageIndexEventReceiver : public IEventReceiver{

public:
	GreateSingletonGet(PageIndexEventReceiver)

	bool onGUIEvent(const SEvent& event){

		switch (event.GUIEvent.EventType){

		case EGET_BUTTON_CLICKED:

			switch (event.GUIEvent.Caller->getID()){

			case GUI_ID_BUTTON_DRESS:
				JumpPage(PageDress);
				return true;

			case GUI_ID_BUTTON_BUY:
				JumpPage(PageBuy);
				return true;

			case GUI_ID_BUTTON_SHARE:
				JumpPage(PageShare);
				return true;

			case GUI_ID_BUTTON_RECOMM:
				JumpPage(PageRecomm);
				return true;

			case GUI_ID_BUTTON_TEST3D:
				JumpPage(PageTest3D);
				return true;

			default:
				return false;
			}
			break;


		default:
			break;
		}
	}

	virtual bool OnEvent(const SEvent& event){

		if (event.EventType == EET_GUI_EVENT){
			onGUIEvent(event);
		}
		return false;
	}
};

void PageIndex::onInit(void* pData){

	s_device()->setEventReceiver(PageIndexEventReceiver::Get());

	s_device()->setWindowCaption(L"Ar360");

	s_guienv()->addStaticText(L"Welcome to Ar360",
		rect<s32>(10, 10, 500, 50), true);

	s_guienv()->addImage(s_driver()->getTexture("/index.bmp"),
		position2d<int>(10, 20));


	s_guienv()->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, GUI_ID_BUTTON_DRESS,
		L"Dress", L"description:Dress");
	s_guienv()->addButton(rect<s32>(10, 280, 110, 280 + 32), 0, GUI_ID_BUTTON_BUY,
		L"BUY", L"description:BUY");
	s_guienv()->addButton(rect<s32>(10, 320, 110, 320 + 32), 0, GUI_ID_BUTTON_SHARE,
		L"SHARE", L"description:SHARE");
	s_guienv()->addButton(rect<s32>(10, 360, 110, 360 + 32), 0, GUI_ID_BUTTON_RECOMM,
		L"RECOMM", L"description:RECOMM");
	s_guienv()->addButton(rect<s32>(10, 400, 110, 400 + 32), 0, GUI_ID_BUTTON_TEST3D,
		L"TEST3D", L"description:TEST3D");
}


CreateStdPageOnShow(PageIndex)
