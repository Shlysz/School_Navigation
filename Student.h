#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class student :public Identity//学生类
{
public:
	student();//默认构造
	student(string name,string password);//有参构造
	 void openMenu();

	//**************************剩下函数自己封装*************************************************
		//封装在.cpp文件中！！！！！！！！！！！！！！！！！！！！！！！



	~student();//析构函数
};