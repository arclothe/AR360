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
	

	IAnimatedMesh* mesh = s_smgr()->getMesh("Ar360Res/UI/t5.obj");
	s_smgr()->setAmbientLight(SColor(255, 160, 160, 160));
	IAnimatedMeshSceneNode* node = s_smgr()->addAnimatedMeshSceneNode(mesh);
	
	scene::ISceneNodeAnimator* anim =
		s_smgr()->createRotationAnimator(core::vector3df(0.0f, 1.0f, 0.0f));
	node->setMaterialFlag(EMF_LIGHTING, true);
	node->addAnimator(anim);
	anim->drop();
		anim = 0;
	//node->setMD2Animation(scene::EMAT_STAND);
	//node->setMaterialTexture(0, s_driver()->getTexture("Ar360Res/UI/sydney.bmp"));
	//

	s_smgr()->addCameraSceneNode(0, vector3df(0, 0, -20), vector3df(0, 5, 0));

	s_guienv()->addButton(rect<s32>(10, 240, 110, 240 + 32), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"description:Back");
	s_device()->setEventReceiver(PageTest3DEventReceiver::Get());
}


CreateStdPageOnShow(PageTest3D)
