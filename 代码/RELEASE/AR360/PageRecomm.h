#pragma once
#include "page.h"

class PageRecomm :public IPage{	
	public:												
		virtual void onInit(void* pData = 0);			
		virtual void onShow();							
};