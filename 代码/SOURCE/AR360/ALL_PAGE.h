#pragma once
#include "Page.h"

DeclPage(PageIndex)
DeclPage(PageDress)
DeclPage(PageBuy)
DeclPage(PageShare)
DeclPage(PageRecomm)
DeclPage(PageTest3D)

/*

这里我把所有页面类的声明放在一起了，
如果您想建立新的页面，请把页面用宏声明在此，
并遵循格式 Page+名称

原谅我这种写法，C++不支持java那杨的包内直接调用
想实现页面相互跳转，只能使用这种方式

*/