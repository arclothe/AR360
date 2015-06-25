#include "ALL_PAGE.h"
#include "ArNode.h"
IRR_NAMESPACE

// GUI ID 的枚举
enum{
	GUI_ID_BUTTON_BACK_TO_INDEX
};

class PageDressEventReceiver : public IEventReceiver{

public:
	GreateSingletonGet(PageDressEventReceiver)

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

void PageDress::onInit(void* pData){

	s_device()->setEventReceiver(PageDressEventReceiver::Get());

	s_device()->setWindowCaption(L"PageDress");

	s_guienv()->addStaticText(L"Welcome to PageDress",
		rect<s32>(10, 10, 500, 50), true);


	s_guienv()->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"description:Back");


	ISceneManager* smgr = s_smgr();
	ArNode *myNode = new ArNode(smgr->getRootSceneNode(), smgr, 666);

	scene::ISceneNode* node = smgr->addLightSceneNode(0, core::vector3df(0, 0, 0),
		video::SColorf(1.0f, 0.6f, 0.7f, 1.0f), 800.0f);
	scene::ISceneNodeAnimator* anim = 0;
	anim = smgr->createFlyCircleAnimator(core::vector3df(0, 150, 0), 250.0f);
	node->addAnimator(anim);
	anim->drop();

	scene::IMeshSceneNode* calibrCube1 = smgr->addCubeSceneNode(100.0f);
	scene::IMeshSceneNode* calibrCube2 = smgr->addCubeSceneNode(100.0f);

	calibrCube1->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);
	calibrCube2->setMaterialType(video::EMT_TRANSPARENT_ALPHA_CHANNEL);

	myNode->addFriendNode(calibrCube1);
	myNode->addFriendNode(calibrCube2);


	scene::ICameraSceneNode* camera = smgr->addCameraSceneNode();
	camera->setPosition(core::vector3df(0, 0, 0));
	camera->setFarValue(10000.0f); // this increase a shadow visible range.
}


CreateStdPageOnShow(PageDress)
