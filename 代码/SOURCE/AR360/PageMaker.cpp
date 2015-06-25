#include "ALL_PAGE.h"
#include <windows.h>
#include <stdio.h>

IRR_NAMESPACE
//////////////////////////////////////////////////////

#define MODEL_TYPE_SHIRT 0
#define MODEL_TYPE_BLOUSE 1

IGUIComboBox *selectModel;
IGUIEditBox *clothName;
IGUIImage* userBmp=NULL;
ITexture* clothTemplate=NULL;
IAnimatedMeshSceneNode* node;
bool drawUVImg=true;
//////////////////////////////////////////////////////

enum{
	GUI_ID_BUTTON_BACK_TO_INDEX,
	GUI_ID_BUTTON_SELECT_FILE,
	GUI_ID_BUTTON_SAVE
};

enum{
	GUI_ID_COMBOBOX_SELECT_MODEL
};

class PageMakerEventReceiver : public IEventReceiver{
public:
	GreateSingletonGet(PageMakerEventReceiver)

	PageMakerEventReceiver()
	{
		modelType=MODEL_TYPE_SHIRT;
		destObjPath=NULL;
	}

	bool onGUIEvent(const SEvent& event){
		wchar_t tmpStr[256];

		switch (event.GUIEvent.EventType){

		case EGET_BUTTON_CLICKED:
			switch (event.GUIEvent.Caller->getID()){
			case GUI_ID_BUTTON_BACK_TO_INDEX:
				JumpPage(PageIndex);
				return true;
			case GUI_ID_BUTTON_SELECT_FILE:
				drawUVImg=false;
				for (s32 i=0; i<irr::gui::EGDC_COUNT ; ++i)
				{
					video::SColor col = s_guienv()->getSkin()->getColor((EGUI_DEFAULT_COLOR)i);
					col.setAlpha(255);
					s_guienv()->getSkin()->setColor((EGUI_DEFAULT_COLOR)i, col);
				}
				userBmp->setVisible(false);
				node->setMaterialTexture(0,NULL);
				s_guienv()->addFileOpenDialog(L"Please choose a bmp file.", true, 0, -1, true);
				return true;
			case GUI_ID_BUTTON_SAVE:
				lstrcpyW(tmpStr,clothName->getText());
				copyModel(tmpStr);
				return true;
			default:
				return false;
			}
			break;
		case EGET_FILE_SELECTED:
			{
				IGUIFileOpenDialog* dialog =
					(IGUIFileOpenDialog*)event.GUIEvent.Caller;

				lstrcpyW(bmpFileName,dialog->getFileName());
				node->setMaterialTexture(0,s_driver()->getTexture(bmpFileName));
				userBmp->setImage(s_driver()->getTexture(bmpFileName));
				userBmp->setVisible(true);
				drawUVImg=true;
			}
			break;
		case EGET_FILE_CHOOSE_DIALOG_CANCELLED:
			drawUVImg=true;

			break;
		case EGET_COMBO_BOX_CHANGED:
			lstrcpyW(tmpStr,selectModel->getText());
			userBmp->setVisible(false);
			changeModelType(tmpStr);
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

private:
	int modelType;
	wchar_t bmpFileName[256];
	wchar_t *destObjPath;

	void changeModelType(wchar_t *modelName)
	{
		if(lstrcmpW(modelName,L"shirt")==0)
		{
			modelType=MODEL_TYPE_SHIRT;

				clothTemplate=s_driver()->getTexture("Ar360Res/UI/white_shirt_template.bmp");
				s_driver()->makeColorKeyTexture(clothTemplate, core::position2d<s32>(0,0));
				node->setMesh(s_smgr()->getMesh("Ar360Res/Model/shirt.obj"));
				node->setMaterialTexture(0,NULL);
				node->getMaterial(0).BackfaceCulling=false;
		}
		else if(lstrcmpW(modelName,L"blouse")==0)
		{
			modelType=MODEL_TYPE_BLOUSE;
		
				clothTemplate=s_driver()->getTexture("Ar360Res/UI/white_blouse_template.bmp");
				s_driver()->makeColorKeyTexture(clothTemplate, core::position2d<s32>(0,0));
				node->setMesh(s_smgr()->getMesh("Ar360Res/Model/blouse.obj"));
				node->setMaterialTexture(0,NULL);
				node->getMaterial(0).BackfaceCulling=false;
		}
	}

	void copyModel(wchar_t *dirName)
	{
		FILE * sourcefile;  
		FILE * desfile;  
		wchar_t copyPath[256];
		wchar_t sourceMtlPath[256];
		wchar_t sourceObjPath[256];
		wchar_t destMtlPath[256];
		wchar_t destBmpPath[256];
		char c[1];

		if(destObjPath!=NULL)
			delete destObjPath;
		destObjPath=new wchar_t[256];

		lstrcpyW(copyPath,L"Ar360Res/Model/");
		switch(modelType)
		{
		case MODEL_TYPE_SHIRT:
			lstrcatW(copyPath,L"shirt/");
			lstrcatW(copyPath,dirName);
			_wmkdir(copyPath);
			lstrcpyW(sourceMtlPath,L"Ar360Res/Model/shirt.mtl");
			lstrcpyW(sourceObjPath,L"Ar360Res/Model/shirt.obj");
			lstrcatW(copyPath,L"/");
			lstrcpyW(destMtlPath,copyPath);
			lstrcatW(destMtlPath,L"shirt.mtl");
			lstrcpyW(destObjPath,copyPath);
			lstrcatW(destObjPath,L"shirt.obj");

			lstrcpyW(destBmpPath,copyPath);
			lstrcatW(destBmpPath,L"shirt.bmp");
			break;
		case MODEL_TYPE_BLOUSE:
			lstrcatW(copyPath,L"blouse/");
			lstrcatW(copyPath,dirName);
			_wmkdir(copyPath);
			lstrcpyW(sourceMtlPath,L"Ar360Res/Model/blouse.mtl");
			lstrcpyW(sourceObjPath,L"Ar360Res/Model/blouse.obj");
			lstrcatW(copyPath,L"/");
			lstrcpyW(destMtlPath,copyPath);
			lstrcatW(destMtlPath,L"blouse.mtl");
			lstrcpyW(destObjPath,copyPath);
			lstrcatW(destObjPath,L"blouse.obj");

			lstrcpyW(destBmpPath,copyPath);
			lstrcatW(destBmpPath,L"blouse.bmp");
			break;
		}
		
		sourcefile =_wfopen(sourceMtlPath,L"rb");
		desfile =_wfopen(destMtlPath,L"wb"); 
		while(1)   
		{   
			if(fread(c, 1 ,1,sourcefile )!=1)
				if(feof(sourcefile))
					break ;
			fwrite(c,1 ,1 ,desfile );

		}
		fclose(sourcefile);  
		fclose(desfile); 

		sourcefile =_wfopen(sourceObjPath,L"rb");
		desfile =_wfopen(destObjPath,L"wb"); 
		while(1)   
		{   
			if(fread(c, 1 ,1,sourcefile )!=1)
				if(feof(sourcefile))
					break ;
			fwrite(c,1 ,1 ,desfile );

		}
		fclose(sourcefile);  
		fclose(desfile); 

		sourcefile =_wfopen(bmpFileName,L"rb");
		desfile =_wfopen(destBmpPath,L"wb"); 
		while(1)   
		{   
			if(fread(c, 1 ,1,sourcefile )!=1)
				if(feof(sourcefile))
					break ;
			fwrite(c,1 ,1 ,desfile );

		}
		fclose(sourcefile);  
		fclose(desfile); 
	}
};

void PageMaker::onInit(void* pData){

	s_device()->setEventReceiver(PageMakerEventReceiver::Get());

	s_device()->setWindowCaption(L"Ar360");

	clothTemplate = s_driver()->getTexture("Ar360Res/UI/white_shirt_template.bmp");
	s_driver()->makeColorKeyTexture(clothTemplate, core::position2d<s32>(0,0));
//-------------------------------------------------------------------------------------------------
	s_smgr()->setAmbientLight(SColor(255, 160, 160, 160));
	s_smgr()->addLightSceneNode(0, core::vector3df(0, 0, -100),
		video::SColorf(1.0f, 1.0f, 1.0f, 1.0f), 1500.0f);

	IAnimatedMesh* mesh = s_smgr()->getMesh("Ar360Res/Model/shirt.obj");
	node = s_smgr()->addAnimatedMeshSceneNode(mesh);
	ISceneNodeAnimator* anim =s_smgr()->createRotationAnimator(core::vector3df(0.0f, 1.0f, 0.0f));
	node->setMaterialTexture(0,NULL);
	node->getMaterial(0).BackfaceCulling=false;
	node->setMaterialFlag(EMF_LIGHTING, true);
	node->addAnimator(anim);
	anim->drop();
	anim = 0;
	node->setPosition(vector3df(65.0f, 40.0f, 70.0f));

	s_smgr()->addCameraSceneNode(0, vector3df(0, 0, -20), vector3df(0, 0, 1));
//-------------------------------------------------------------------------------------------------
	selectModel=s_guienv()->addComboBox(rect<s32>(500, 160, 620, 180),0,GUI_ID_COMBOBOX_SELECT_MODEL);
	selectModel->addItem(L"shirt");
	selectModel->addItem(L"blouse");

	s_guienv()->addButton(rect<s32>(500, 200, 620, 220), 0, GUI_ID_BUTTON_SELECT_FILE,
		L"File", L"");
	s_guienv()->addButton(rect<s32>(560, 440, 600, 460), 0, GUI_ID_BUTTON_BACK_TO_INDEX,
		L"Back", L"");
	s_guienv()->addButton(rect<s32>(500, 290, 620, 310), 0, GUI_ID_BUTTON_SAVE,
		L"SAVE", L"");
	userBmp=s_guienv()->addImage(rect<s32>(0,0,480,480),0);
	userBmp->setScaleImage(true);
	userBmp->setVisible(false);
	s_guienv()->addStaticText(L"Cloth Name:",rect<s32>(500, 230, 620, 240));
	clothName=s_guienv()->addEditBox(L"",rect<s32>(500, 250, 620, 270),true);
}

void PageMaker::onShow(){														
	if (s_device()->isWindowActive()){				
		s_driver()->beginScene(						
			true, true, SColor(0, 200, 200, 200));	
		s_smgr()->drawAll();						
		s_guienv()->drawAll();

		if(drawUVImg)
		{
			s_driver()->draw2DImage(clothTemplate, core::position2d<s32>(0,0),
				core::rect<s32>(0,0,480,480), 0,
				video::SColor(255,255,255,255), true);
		}
		s_driver()->endScene();						
	}												
}

