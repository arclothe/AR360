#include "ArNode.h"

// C++里面的静态变量，需要再定义一下

ArNode*					ArNode::s_CurrentRenderNode	= NULL;
mk3::var_texture*		Mk3TexSingleton::s_pTex		= NULL;