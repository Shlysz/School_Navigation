#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class student :public Identity//ѧ����
{
public:
	student();//Ĭ�Ϲ���
	student(string name,string password);//�вι���
	 void openMenu();

	//**************************ʣ�º����Լ���װ*************************************************
		//��װ��.cpp�ļ��У���������������������������������������������



	~student();//��������
};