#include "ALL_PAGE.h"
IRR_NAMESPACE


// GUI ID 的枚举
enum{
	GUI_ID_BUTTON_BACK_TO_INDEX
};

class PageTest3DEventReceiver : public IEventReceiver{

public:
	GreateSingletonGet(PageTest3DEventReceiver)

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

void PageTest3D::onInit(void* pData){
	
	s_device()->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	s_guienv()->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10, 10, 260, 22), true);

	IAnimatedMesh* mesh = s_smgr()->getMesh("media/sydney.md2");

	IAnimatedMeshSceneNode* node = s_smgr()->addAnimatedMeshSceneNode(mesh);


	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture(0, s_driver()->getTexture("media/sydney.bmp"));
	}

	s_smgr()->addCameraSceneNode(0, vector3df(0, 30, -40), vector3df(0, 5, 0));
	//s_guienv()->loadGUI("PageTest.xml");
	s_guienv()->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"description:Back");
	s_device()->setEventReceiver(PageTest3DEventReceiver::Get());
}


CreateStdPageOnShow(PageTest3D)
