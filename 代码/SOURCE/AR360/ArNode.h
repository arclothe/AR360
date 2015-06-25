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

	typedef scene::ISceneNode* pFriendNode;
	pFriendNode		m_friendpNodes[MK3_Marker_Total_Num];

	static ArNode*	s_CurrentRenderNode;
	static void NodeArFunc(int obj_id, double gl_para[16]){

		// 获取被识别的Marker对应的pFriendNode
		scene::ISceneNode* pNode = ArNode::s_CurrentRenderNode->getFriendNodeByID(obj_id);

		// 如果未被设置，说明这个Marker并不驱动哪个结点，函数直接返回
		if (!pNode){
			printf("ecf：Node of %d is not inited %s %d\n", obj_id,__FILE__,__LINE__);
			return;
		}

		// 现在开始重置pFriendNode的位置


		float m[16];//  3D引擎需要float数组参数，Ar解析的是double，需要转换
		for (int i = 0; i < 16; ++i)
			m[i] = gl_para[i];

		core::matrix4 mat;
		mat.setM(m);

		// 抽取三分量
		vector3df p = mat.getTranslation();
		vector3df r = mat.getRotationDegrees();
		vector3df s = mat.getScale();

		// 进行校正
		r.X = -r.X;
		r.Z = -r.Z;
		//r.Y = -r.Y;

		/*r.Z += 180;
		r.Y += 180;
		*/

		p.Y = -p.Y;
		float dp = 2.5;
		p.X *= dp;
		p.Y *= dp;
		//p.Z *= dp;

		//p.Y += 100;

		s *= 20;

		p.Y -= 30;
		p.Z += 50;
		// 校正完成

		// 设置pFriendNode的三分量
		pNode->setPosition(p);
		pNode->setRotation(r);
		pNode->setScale(s);

	}

public:
	// 构造函数，把所有 pFriendNode 置为NULL
	ArNode(scene::ISceneNode* parent, scene::ISceneManager* mgr, s32 id)
		: scene::ISceneNode(parent, mgr, id){
			memset(m_friendpNodes, 0, MK3_Marker_Total_Num*sizeof(pFriendNode));
		}

	// 根据ID，获取pFriendNode，ID可以是 MK3_Marker_Front_Up 之类的
	scene::ISceneNode* getFriendNodeByID(int id){
		return m_friendpNodes[id];
	}

	// 设置pFriendNode使其和一个Marker对应，其空间位置会随Marker移动而改变
	void addFriendNode(int index,scene::ISceneNode* p){
		m_friendpNodes[index] = p;
	}

	// 渲染AR，并更改所有pFriendNode的位置
	virtual void render(){
		s_CurrentRenderNode = this;
			Mk3TexSingleton::set_arFunc(ArNode::NodeArFunc);
			Mk3TexSingleton::update();
		s_CurrentRenderNode = NULL;
	}

	// 不用管，不重要，我也不清楚
	virtual void OnRegisterSceneNode(){
		if (IsVisible)
			SceneManager->registerNodeForRendering(this);

		ISceneNode::OnRegisterSceneNode();
	}

	// 不用管，不重要，我也不清楚
	virtual const core::aabbox3d<f32>& getBoundingBox() const{
		core::aabbox3d<f32> Box;
		return Box;
	}

	// 不用管，不重要，我也不清楚
	virtual u32 getMaterialCount() const{
		return 1;
	}

	// 不用管，不重要，我也不清楚
	virtual video::SMaterial& getMaterial(u32 i){
		video::SMaterial Material;
		return Material;
	}
};
