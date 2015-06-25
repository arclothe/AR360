#include   "stdlib.h"   
#include   "direct.h"   
#include   "string.h"   
#include   "io.h"   
#include   "browsedir.h" 
#include "ALL_PAGE.h"

IRR_NAMESPACE

extern IAnimatedMeshSceneNode *node[6];

CBrowseDir::CBrowseDir()   
{    
	getcwd(m_szInitDir,_MAX_PATH);   

	pageCount=0;
	fileNum=0;
	totalModelCount=1;

	int   len=strlen(m_szInitDir);   
	if   (m_szInitDir[len-1]   !=   '\\')   
		strcat(m_szInitDir,"\\");   
}   

bool   CBrowseDir::SetInitDir(const   char   *dir)   
{   
	if   (_fullpath(m_szInitDir,dir,_MAX_PATH)   ==   NULL)   
		return   false;   
  
	if   (_chdir(m_szInitDir)   !=   0)   
		return   false;   

	int   len=strlen(m_szInitDir);   
	if   (m_szInitDir[len-1]   !=   '\\')   
		strcat(m_szInitDir,"\\");   

	return   true;   
}   

bool   CBrowseDir::BeginBrowse(const char *filespec,bool up_or_down)   
{   
	if(up_or_down)
	{
		if((pageCount*6)<totalModelCount)
			pageCount++;
		else
			return 1;
	}
	else
	{
		if(pageCount-1>0)
			pageCount--;
		else 
			return 1;
	}
	totalModelCount=0;
	ProcessDir(m_szInitDir,NULL);   
	BrowseDir(m_szInitDir,filespec); 
	for(int i=fileNum-((pageCount-1)*6);i<6;i++)
	{
		node[i]->setVisible(false);
	}
	fileNum=0;
	return 1;
}   

bool   CBrowseDir::BrowseDir   
	(const   char   *dir,const   char   *filespec)   
{   
	_chdir(dir);   

	long   hFile;   
	_finddata_t   fileinfo;   
	if   ((hFile=_findfirst(filespec,&fileinfo))   !=   -1)   
	{   
		do   
		{   
			if   (!(fileinfo.attrib   &   _A_SUBDIR))   
			{   
				char   filename[_MAX_PATH];   
				strcpy(filename,dir);   
				strcat(filename,fileinfo.name);   
				if   (!ProcessFile(filename))   
					return   false;   
			}   
		}   while   (_findnext(hFile,&fileinfo)   ==   0);   
		_findclose(hFile);   
	}   

	_chdir(dir);   
	if   ((hFile=_findfirst("*.*",&fileinfo))   !=   -1)   
	{   
		do   
		{   
			if   ((fileinfo.attrib   &   _A_SUBDIR))   
			{   
				if   (strcmp(fileinfo.name,".")   !=   0   &&   strcmp   
					(fileinfo.name,"..")   !=   0)   
				{   
					char   subdir[_MAX_PATH];   
					strcpy(subdir,dir);   
					strcat(subdir,fileinfo.name);   
					strcat(subdir,"\\");   
					ProcessDir(subdir,dir);   
					if   (!BrowseDir(subdir,filespec))   
						return   false;   
				}   
			}   
		}   while   (_findnext(hFile,&fileinfo)   ==   0);   
		_findclose(hFile);   
	}   
	return true;   
}   

bool CBrowseDir::ProcessFile(char *filename)
{   
	int lenth;
	fileNum++;
	if(fileNum>((pageCount-1)*6)&&fileNum<=(pageCount*6))
	{
		node[fileNum-1-((pageCount-1)*6)]->setMesh(s_smgr()->getMesh(filename));
		lenth=strnlen_s(filename,_MAX_PATH);
		filename[lenth-1]='p';
		filename[lenth-2]='m';
		filename[lenth-3]='b';
		node[fileNum-1-((pageCount-1)*6)]->setMaterialTexture(0,s_driver()->getTexture(filename));
		node[fileNum-1-((pageCount-1)*6)]->setVisible(true);
	}
	totalModelCount++;
	return true;   
}   

void   CBrowseDir::ProcessDir(const char* currentdir,const char* parentdir)   
{   
} 

