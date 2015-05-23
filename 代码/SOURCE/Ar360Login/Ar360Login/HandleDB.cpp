#include "HandleDB.h"


HandleDB::HandleDB(void)
	: isFound(false)
	, isExist(true)
{
}

HandleDB::~HandleDB(void)
{
}

// 用来检测输入的数字是否符合规范
int HandleDB::inputNumCheck(int min, int max)
{
	int num;

	while (true)
	{
		cout << "请输入（数字）：";
		cin >> num;

		if (cin.fail()||cin.bad())
		{
			cout << "您输入的不是数字，请检查后重新输入" << endl;
			cin.clear();
			char ch;
			cin>>ch;
			cin.ignore(256, '\n');
			continue;
		}
		if (num >= min && num <= max)
			break;
		cout << "输入超出范围，请重新输入" << endl;
		cout << "请在" << min << "-" << max << "的范围内输入数字" << endl;
	}

	cin.ignore(256, '\n');

	return num;
}

string HandleDB::inputStringCheck(int length,string inputType)
{

	string temp = "";

	while (true)
	{
		cout << inputType << ":" << endl;
		cin >> temp;

		if (temp.length() > length)
		{
			cout << "您输入的" << inputType << "过长" << endl;
			cout << inputType << "长度应小于" << length << endl;
			continue;
		}
		else if (temp.empty())
		{
			cout << "输入不能为空" << endl;
		}
		else{
			break;
		}

	}

	return temp;
}

bool HandleDB::checkIDFromDB(string Id,sqlite3 *db,bool &isJudged,int checkType)
{
	string strSQL = "";
	strSQL += "select * from UserLogin where ID ='";
	strSQL += Id;
	strSQL += "';";


	char **azResult;
	int	nCol,nRow;
	int res = sqlite3_get_table(db,strSQL.c_str(),&azResult,&nRow,&nCol,0);

	if (res == SQLITE_OK)
	{
		switch (checkType)
		{
		case 1:
			if (nRow == 0)
			{
				cout << "未找到此账户,请重新输入" << endl;
				isJudged = false;
			}
			else if (nRow == 1)
			{
				userPwd = azResult[3];
				isJudged = true;		
			}
			else
			{
				cout << "数据库错误...有两个相同账户" << endl;
				isJudged = false;
			}
			break;

		case 2:
			if (nRow == 0)
			{
				isJudged = false;
			}
			else if (nRow == 1)
			{
				cout << "已存在此账户,请重新输入" << endl;
				isJudged = true;
			}
			else
			{
				cout << "数据库错误...有两个相同账户" << endl;
				isJudged = true;
			}
			break;
		}
		sqlite3_free_table(azResult);

		return true;
	}else {
		return false;
	}
}

// 实现登陆
void HandleDB::loginAR360(sqlite3 *db)
{
	string ID;
	string password;

	while (!isFound)
	{

		ID = inputStringCheck(10,"账号");
		userID = ID;
		if (checkIDFromDB(ID,db,isFound,1))
		{
			if (isFound == false)
			{
				cout << "是否重新输入账号？" << endl;
				cout << "1.是" << endl;
				cout << "2.否，将返回主界面" << endl;
				int numCheck = inputNumCheck(1,2);
				if (numCheck == 1)
				{
					continue;
				}else{
					break;
				}
			}
		}else{
			cout << "数据库打开失败" << endl;
		}
	}

	while(isFound){

		password = inputStringCheck(20,"密码");

		if (password == userPwd)
		{
			cout << "登陆成功！" << endl;
			exit(0);
		}
		else{
			cout << "是否重新输入密码？" << endl;
			cout << "1.是" << endl;
			cout << "2.否，将返回主界面" << endl;
			int numCheck = inputNumCheck(1,2);
			if (numCheck == 1)
			{
				continue;
			}else{
				isFound = false;
				break;
			}
		}
	}
	                        

	return;
}

void HandleDB::registerAR360(sqlite3 *db)
{
	string ID;
	string password;

	while (isExist)
	{

		ID = inputStringCheck(10,"账号");
		userID = ID;
		if (checkIDFromDB(ID,db,isExist,2))
		{
			if (isExist == true)
			{
				cout << "是否重新输入账号？" << endl;
				cout << "1.是" << endl;
				cout << "2.否，将返回主界面" << endl;
				int numCheck = inputNumCheck(1,2);
				if (numCheck == 1)
				{
					continue;
				}else{
					break;
				}
			}
		}else{
			cout << "数据库打开失败" << endl;
		}
	}

	if (!isExist)
	{
		password = inputStringCheck(20,"密码");

		string strSQL;
		strSQL += "insert into UserLogin(ID,password)values('";
		strSQL += ID;
		strSQL += "','";
		strSQL += password;
		strSQL += "');";

		char* cErrMsg;  
		int nRes = sqlite3_exec(db,strSQL.c_str(),0,0,&cErrMsg);
		if (nRes != SQLITE_OK)    
		{  
			cout<< "注册失败：" << cErrMsg << endl;
			userID = "";
		}  
		else  
		{  
			cout<< "账号" << ID << "注册成功" << endl; 
			userPwd = password;
		}  
	}
}
