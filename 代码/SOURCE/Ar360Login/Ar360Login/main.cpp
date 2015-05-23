#include "sqlite3.h"
#include "HandleDB.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void main(){

	sqlite3 *db = NULL;
	HandleDB handle;
	int temp;

	int result = sqlite3_open("Ar360Login.db", &db);

	if (SQLITE_OK != result)
	{
		cout << "failed to open db" << endl;
		return;
	} 
	else
	{
		cout << "open db succeed" << endl;
		system("pause");
		system("CLS");

		while (true)
		{
			cout << "请选择要进行的操作" << endl;
			cout << "1.登陆" << endl;
			cout << "2.注册" << endl;
			cout << "3.退出" << endl;
			temp = handle.inputNumCheck(1,3);

			if (temp == 1)
			{
				handle.loginAR360(db);
			}else if (temp == 2)
			{
				handle.registerAR360(db);
			}else{
				break;
			}
		}
	}

	sqlite3_close(db);

	return;
}