#include "ALL_PAGE.h"
#include "windows.h"
IRR_NAMESPACE

///////////////////////////////////////	
IGUIButton **rec;

IGUIButton *image;
IGUIButton *switchImg;

//////////////////////////////////////
DWORD WINAPI SwitchAnime(PVOID lpParam)
{
	char *file=(char *)lpParam;
	switchImg->setImage(s_driver()->getTexture(file));

	for(int i=0;i<30;i++)
	{
		switchImg->setRelativePosition(rect<s32>(640-i*(625/29),10,1225-i*(625/29),420));
		Sleep(30);
	}
	image->setImage(s_driver()->getTexture(file));
	switchImg->setRelativePosition(rect<s32>(0,0,1,1));
	
	return 1;
}

// GUI ID 的枚举
enum{
	GUI_ID_BUTTON_BACK_TO_INDEX,
	GUI_ID_BUTTON_REC1,
	GUI_ID_BUTTON_REC2,
	GUI_ID_BUTTON_REC3
};

class PageRecommEventReceiver : public IEventReceiver{
	
public:
	GreateSingletonGet(PageRecommEventReceiver)
		HANDLE hThread;
		path file;
		// 对GUI事件的处理
		bool onGUIEvent(const SEvent& event){
			switch (event.GUIEvent.EventType){
			case EGET_BUTTON_CLICKED:
				switch (event.GUIEvent.Caller->getID()){
				case GUI_ID_BUTTON_BACK_TO_INDEX:
					delete rec;
					JumpPage(PageIndex);
					return true;
				case GUI_ID_BUTTON_REC1:
					rec[0]->setImage(s_driver()->getTexture("Ar360Res/UI/rec2.bmp"));
					rec[1]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
					rec[2]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
					rec[0]->setEnabled(false);
					rec[1]->setEnabled(true);
					rec[2]->setEnabled(true);

					hThread=CreateThread(NULL,0, SwitchAnime,"Ar360Res/UI/recshow1.jpg", 0,NULL);
					CloseHandle(hThread);
					return true;
				case GUI_ID_BUTTON_REC2:
					rec[0]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
					rec[1]->setImage(s_driver()->getTexture("Ar360Res/UI/rec2.bmp"));
					rec[2]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
					rec[0]->setEnabled(true);
					rec[1]->setEnabled(false);
					rec[2]->setEnabled(true);

					hThread=CreateThread(NULL,0, SwitchAnime,"Ar360Res/UI/recshow2.jpg", 0,NULL);
					CloseHandle(hThread);
					return true;
				case GUI_ID_BUTTON_REC3:
					rec[0]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
					rec[1]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
					rec[2]->setImage(s_driver()->getTexture("Ar360Res/UI/rec2.bmp"));
					rec[0]->setEnabled(true);
					rec[1]->setEnabled(true);
					rec[2]->setEnabled(false);

					hThread=CreateThread(NULL,0, SwitchAnime,"Ar360Res/UI/recshow3.jpg", 0,NULL);
					CloseHandle(hThread);
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

	image=s_guienv()->addButton(rect<s32>(15,10,620,420));
	switchImg=s_guienv()->addButton(rect<s32>(0,0,1,1));
	switchImg->setScaleImage(true);
	image->setScaleImage(true);

	switchImg->setImage(s_driver()->getTexture("Ar360Res/UI/recshow2.jpg"));
	image->setImage(s_driver()->getTexture("Ar360Res/UI/recshow1.jpg"));
	//为了之后可以切换图片
	s_guienv()->addButton(rect<s32>(0,0,1,1))->setImage(s_driver()->getTexture("Ar360Res/UI/recshow3.jpg"));

	rec=new IGUIButton*[3];
	for(int i=0;i<3;i++)
	{
		rec[i]=s_guienv()->addButton(rect<s32>(260+i*30,430,280+i*30,450),0,GUI_ID_BUTTON_REC1+i);
		rec[i]->setScaleImage(true);
		rec[i]->setImage(s_driver()->getTexture("Ar360Res/UI/rec1.bmp"));
	}
	rec[0]->setImage(s_driver()->getTexture("Ar360Res/UI/rec2.bmp"));
	rec[0]->setEnabled(false);

	s_guienv()->addButton(rect<s32>(560, 440, 600, 460), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"description:Back");
}

CreateStdPageOnShow(PageRecomm)
