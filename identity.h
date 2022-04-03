#pragma once
#include <iostream>
using namespace std;

//身份的抽象的基类
class Identity
{
public:

	//操作菜单
	virtual void openMenu() = 0;//纯虚函数,子类必须重写

	//用户名
	string m_Name;
	//密码
	string m_Password;


};
