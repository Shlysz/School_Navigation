#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class manager:public Identity//����Ա��
{
public:
	manager();//Ĭ�Ϲ���
	manager(string name, string password);//�вι���
	virtual  void openMenu();//չʾ����
	void showPerson();
	void showCourse();
	void PrintCourse(string fname);
	
	~manager();//��������
};