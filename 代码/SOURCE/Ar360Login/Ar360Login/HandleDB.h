#pragma once
#include "sqlite3.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
class HandleDB
{
public:
	HandleDB(void);
	~HandleDB(void);
	// 用来检测输入的数字是否符合规范
	static int inputNumCheck(int min, int max);
	// 实现登陆
	void loginAR360(sqlite3 *db);
	string inputStringCheck(int length,string inputType);
	bool checkIDFromDB(string Id,sqlite3 *db,bool &isJudged,int checkType);
	// 实现注册
	void registerAR360(sqlite3 *db);
//	static int userResult(void * notUsed, int nCol, char ** azValues, char ** azColName);
private:
	// 存储当前登陆或者注册的账号
	string userID;
	// 存储对应当前账号的密码
	string userPwd;
	// 在数据库中是否找到输入的登陆账号
	bool isFound;	
	// 判断要注册的账号是否已经存在
	bool isExist;
};

