#pragma once
#include   "stdlib.h"  
#include <windows.h>

class   CBrowseDir   
{
private:
	int pageCount;
	int fileNum;
	int totalModelCount;
	TCHAR director[260];
protected:
	char   m_szInitDir[_MAX_PATH];   
public:   
	CBrowseDir();   
	bool   SetInitDir(const   char   *dir);   
	bool   BeginBrowse(const   char   *filespec,bool up_or_down);   

protected:   
	bool   BrowseDir(const   char   *dir,const   char   *filespec);     
	virtual   bool   ProcessFile(char   *filename);   
	virtual   void   ProcessDir(const   char     
		*currentdir,const   char   *parentdir);   
};   