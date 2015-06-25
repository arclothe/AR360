#include "ALL_PAGE.h"

extern bool dress_or_chest;

enum{
	GUI_ID_BUTTON_DRESS,
	GUI_ID_BUTTON_BUY,
	GUI_ID_BUTTON_SHARE,
	GUI_ID_BUTTON_RECOMM,
	GUI_ID_BUTTON_TEST3D,
	GUI_ID_BUTTON_MAKER,
	GUI_ID_BUTTON_CHEST
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
				dress_or_chest=true;
				JumpPage(PageChest);
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
			case GUI_ID_BUTTON_MAKER:
				JumpPage(PageMaker);
				return true;
			case GUI_ID_BUTTON_CHEST:
				dress_or_chest=false;
				JumpPage(PageChest);
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

	s_guienv()->addImage(s_driver()->getTexture("Ar360Res/UI/homepage.jpg"),
		position2d<int>(0, 0));

	s_guienv()->addButton(rect<s32>(15, 92, 15+173, 92 + 75), 0, GUI_ID_BUTTON_DRESS,
		L"", L"")->setImage(s_driver()->getTexture("Ar360Res/UI/BTdress.jpg"));
	s_guienv()->addButton(rect<s32>(15, 176, 15+173, 176+75), 0, GUI_ID_BUTTON_BUY,
		L"", L"")->setImage(s_driver()->getTexture("Ar360Res/UI/BTbuy.jpg"));
	s_guienv()->addButton(rect<s32>(15, 261, 15+173,261+75), 0, GUI_ID_BUTTON_MAKER,
		L"", L"")->setImage(s_driver()->getTexture("Ar360Res/UI/BTmaker.jpg"));
	s_guienv()->addButton(rect<s32>(15, 355, 15+173,355+75), 0, GUI_ID_BUTTON_CHEST,
		L"", L"")->setImage(s_driver()->getTexture("Ar360Res/UI/BTchest.jpg"));;
	//s_guienv()->addButton(rect<s32>(10, 400, 110, 400 + 32), 0, GUI_ID_BUTTON_TEST3D,
	//	L"TEST3D", L"description:TEST3D");
}


CreateStdPageOnShow(PageIndex)
