#pragma once
#include<iostream>
using namespace std;
#include "identity.h"

class teacher :public Identity//��ʦ��
{
public:
	teacher();//Ĭ�Ϲ���
	teacher(string name, string password);//�вι���
	void openMenu() ;//չʾ����

	//**************************ʣ�º����Լ���װ*************************************************
		//��װ��.cpp�ļ��У���������������������������������������������



	~teacher();//��������
};