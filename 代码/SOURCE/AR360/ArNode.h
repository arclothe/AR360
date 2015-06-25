#include <irrlicht.h>
#include "driverChoice.h"
#include "windows.h"
#include "gl/GL.h"
#include "Mk3Tex.h"
#include "vector"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

class ArNode : public scene::ISceneNode{

	
	std::vector<scene::ISceneNode*> m_friendpNodes;

	static ArNode*	s_CurrentRenderNode;
	static void NodeArFunc(int obj_id, double gl_para[16]){



		scene::ISceneNode* pNode = ArNode::s_CurrentRenderNode->getFriendNodeByID(obj_id);


		float m[16];
		for (int i = 0; i < 16; ++i)
			m[i] = gl_para[i];

		core::matrix4 mat;
		mat.setM(m);


		vector3df p = mat.getTranslation();
		vector3df r = mat.getRotationDegrees();
		vector3df s = mat.getScale();

		p.Y = -p.Y;
		r.X = -r.X;
		r.Z = -r.Z;
		r.Y = -r.Y;

		r.Z += 180;
		r.Y += 180;

		float dp = 2;
		p.X *= dp;
		p.Y *= dp;
		//p.Z *= dp;


		//s *= 5;

		pNode->setPosition(p);
		pNode->setRotation(r);
		pNode->setScale(s);

	}

public:

	ArNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id)
		: scene::ISceneNode(parent, mgr, id){}



	scene::ISceneNode* getFriendNodeByID(int id){
		return m_friendpNodes[id];
	}
	void addFriendNode(scene::ISceneNode* p){
		m_friendpNodes.push_back(p);
	}

	virtual void render(){
		s_CurrentRenderNode = this;
			Mk3TexSingleton::set_arFunc(ArNode::NodeArFunc);
			Mk3TexSingleton::update();
		s_CurrentRenderNode = NULL;
	}

	virtual void OnRegisterSceneNode(){
		if (IsVisible)
			SceneManager->registerNodeForRendering(this);

		ISceneNode::OnRegisterSceneNode();
	}

	virtual const core::aabbox3d<f32>& getBoundingBox() const{
		core::aabbox3d<f32> Box;
		return Box;
	}

	virtual u32 getMaterialCount() const{
		return 1;
	}

	virtual video::SMaterial& getMaterial(u32 i){
		video::SMaterial Material;
		return Material;
	}
};
