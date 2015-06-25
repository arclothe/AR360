#include "ALL_PAGE.h"
#include <windows.h>
#include "BrowseDir.h"

IRR_NAMESPACE
////////////////////////////////////////////////
CBrowseDir *modelBrowse;
IAnimatedMeshSceneNode *node[6];
ICameraSceneNode *camera;
ISceneNode* cube;

extern IAnimatedMesh *mesh;
extern ITexture *texture;
bool dress_or_chest=true;
////////////////////////////////////////////////
enum{
	GUI_ID_BUTTON_BACK_TO_INDEX,
	GUI_ID_BUTTON_NEXT,
	GUI_ID_BUTTON_PREVIOUS
};

class PageChestEventReceiver : public IEventReceiver{

public:
	GreateSingletonGet(PageChestEventReceiver)

	bool onGUIEvent(const SEvent& event){
		TCHAR director[260];

		switch (event.GUIEvent.EventType){
		case EGET_BUTTON_CLICKED:

			switch (event.GUIEvent.Caller->getID()){

			case GUI_ID_BUTTON_BACK_TO_INDEX:
				delete modelBrowse;
				JumpPage(PageIndex);
				return true;
			case GUI_ID_BUTTON_NEXT:
				GetCurrentDirectoryW(260,director);
				modelBrowse->SetInitDir("Ar360Res/Model/");
				modelBrowse->BeginBrowse("*.obj",true);
				SetCurrentDirectoryW(director);
				return true;
			case GUI_ID_BUTTON_PREVIOUS:
				GetCurrentDirectoryW(260,director);
				modelBrowse->SetInitDir("Ar360Res/Model/");
				modelBrowse->BeginBrowse("*.obj",false);
				SetCurrentDirectoryW(director);
				return true;
			default:
				return false;
			}
			break;


		default:
			break;
		}
	}
	bool onMouseEvent(const SEvent& event)
	{
		line3d<f32> ray;
		ISceneNode *n=NULL;

		switch(event.MouseInput.Event)
		{
		case EMIE_LMOUSE_DOUBLE_CLICK:
				cube->setVisible(false);
				ray=s_smgr()->getSceneCollisionManager()->getRayFromScreenCoordinates(vector2d<s32>(event.MouseInput.X,event.MouseInput.Y),camera);
				n=s_smgr()->getSceneCollisionManager()->getSceneNodeFromRayBB(ray);
				if(n)
				{
					if(dress_or_chest)
					{
						mesh=((IAnimatedMeshSceneNode*)n)->getMesh();
						texture=((IAnimatedMeshSceneNode*)n)->getMaterial(0).getTexture(0);
						JumpPage(PageDress);
					}
					else
					{
						s_guienv()->addMessageBox(L"Cloth Message",L"a wide range of the material science and fiber science aspects of the technology including: *electrically active polymeric materials and the applications of nonionic polymer gel and elastomers for artificial muscles *thermally sensitive fibres and fabrics *cross-linked polyol fibrous substrates stimuli-responsive interpenetrating polymer network hydrogel *permeation control through stimuli-responsive polymer membranes *"
							,true);
						cube->setVisible(true);
					}
				}
				break;
		}

		return true;
	}

	virtual bool OnEvent(const SEvent& event){

		if (event.EventType == EET_GUI_EVENT){
			onGUIEvent(event);
		}
		if (event.EventType == irr::EET_MOUSE_INPUT_EVENT){
			onMouseEvent(event);
		}
		return false;
	}
};
void PageChest::onInit(void* pData){
	TCHAR director[260];

	s_device()->setEventReceiver(PageChestEventReceiver::Get());

	s_device()->setWindowCaption(L"Ar360");


	s_smgr()->setAmbientLight(SColor(255, 160, 160, 160));
	ILightSceneNode *light=s_smgr()->addLightSceneNode(0, core::vector3df(0, 0, -100),
		video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 1500.0f);
	
	ISceneNodeAnimator* a=s_smgr()->createFlyCircleAnimator(vector3df(0,0,40),
			40,0.001f);
	light->addAnimator(a);
	a->drop();
	a=0;
	modelBrowse=new CBrowseDir;
	
	for(int i=0;i<6;i++)
	{
		IAnimatedMesh* mesh = s_smgr()->getMesh("Ar360Res/Model/shirt.obj");
		node[i] = s_smgr()->addAnimatedMeshSceneNode(mesh);
		ISceneNodeAnimator* anim=s_smgr()->createFlyCircleAnimator(vector3df(0,0,80),
			40,0.0005f,vector3df(0,0,1),(i+1)/6.0);
		node[i]->addAnimator(anim);
		node[i]->setRotation(vector3df(0,180,0));
		node[i]->getMaterial(0).BackfaceCulling=false;
		anim->drop();
		anim = 0;

	}

	cube = s_smgr()->addCubeSceneNode(10,0,-1,vector3df(0,0,80),vector3df(0,0,0),vector3df(50,40,50));
	cube->setMaterialTexture(0,s_driver()->getTexture("Ar360Res/UI/board.bmp"));
	cube->getMaterial(0).BackfaceCulling=false;
	//cube->setVisible(false);

	GetCurrentDirectoryW(260,director);
	modelBrowse->SetInitDir("Ar360Res/Model/");
	modelBrowse->BeginBrowse("*.obj",true);
	SetCurrentDirectoryW(director);

	//camera=s_smgr()->addCameraSceneNode(0, vector3df(0, 0, -20), vector3df(0, 0, 1));
	//	s_smgr()->addCameraSceneNodeFPS();
	camera=s_smgr()->addCameraSceneNodeMaya(0,-500,100,500,-1,90);
	camera->setTarget(vector3df(0,0,80));
	s_guienv()->addButton(rect<s32>(460, 440, 500, 460), 0, GUI_ID_BUTTON_PREVIOUS,
		L"Previous", L"");
	s_guienv()->addButton(rect<s32>(510, 440, 550, 460), 0, GUI_ID_BUTTON_NEXT,
		L"Next", L"");
	s_guienv()->addButton(rect<s32>(560, 440, 600, 460), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"");
}

void PageChest::onShow(){														
	if (s_device()->isWindowActive()){				
		s_driver()->beginScene(						
			true, true, SColor(0, 200, 200, 200));	
		s_smgr()->drawAll();				
		s_guienv()->drawAll();

		s_driver()->endScene();						
	}												
}