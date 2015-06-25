#include "ALL_PAGE.h"
IRR_NAMESPACE

// GUI ID 的枚举
enum{
	GUI_ID_BUTTON_BACK_TO_INDEX
};

class PageRecommEventReceiver : public IEventReceiver{

public:
	GreateSingletonGet(PageRecommEventReceiver)

		// 对GUI事件的处理
		bool onGUIEvent(const SEvent& event){

			switch (event.GUIEvent.EventType){
			case EGET_BUTTON_CLICKED:
				switch (event.GUIEvent.Caller->getID()){
				case GUI_ID_BUTTON_BACK_TO_INDEX:
					JumpPage(PageIndex);
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

void PageRecomm::onInit(void* pData){

	s_device()->setEventReceiver(PageRecommEventReceiver::Get());

	s_device()->setWindowCaption(L"PageRecomm");

	s_guienv()->addStaticText(L"Welcome to PageRecomm",
		rect<s32>(10, 10, 500, 50), true);

	s_guienv()->addImage(s_driver()->getTexture("Ar360Res/UI/Recomm.bmp"),
		position2d<int>(10, 20));


	s_guienv()->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"description:Back");

}


CreateStdPageOnShow(PageRecomm)
