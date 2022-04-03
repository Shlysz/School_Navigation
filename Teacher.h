#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class teacher :public Identity//教师类
{
public:
	teacher();//默认构造
	teacher(string name, string password);//有参构造
	void openMenu() ;//展示界面

	//**************************剩下函数自己封装*************************************************
		//封装在.cpp文件中！！！！！！！！！！！！！！！！！！！！！！！



	~teacher();//析构函数
};