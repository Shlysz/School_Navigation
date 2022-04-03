#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class manager:public Identity//管理员类
{
public:
	manager();//默认构造
	manager(string name, string password);//有参构造
	virtual  void openMenu();//展示界面
	void showPerson();
	void showCourse();
	void PrintCourse(string fname);
	
	~manager();//析构函数
};