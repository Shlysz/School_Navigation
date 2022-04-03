#include <iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include "globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"

//��½����
void  LoginIn(string FileName, int type);//������1 Ҫ�򿪵��ļ� ����2 Ҫ��½��Ա���������
void managerMenu(Identity *&manage);	//�������Ա�Ӳ˵�����
void studentMenu(Identity*& stu);	//����ѧ���Ӳ˵�����
void teacherMenu(Identity*& teach);	//������ʦ�Ӳ˵�����
int main()
{
	int select = 0;//����ѡ��
	while (true)
	{
		cout << "======================  ��ӭ���������ʵ��ѧУ԰����ϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;
		switch (select)
		{
		case 1://ѧ����½
			LoginIn(STUDENT_FILE,1);
			break;
		case 2://��ʦ��½
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://����Ա��½
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://�˳�
			cout << "\n\n\n";
			cout << "\t\t\t��ӭ�´�ʹ�ã�" << endl;
			cout << "\n\n\n";
			system("pause");
			exit(0);

			break;
		default:
			cout << "\n\n\n";
			cout << "\t\t\t�����������������룡" << endl;
			cout << "\n\n\n";
			system("pause");
			system("cls");
			break;

		}
	}
	system("pause");
	return 0;
}

void  LoginIn(string FileName, int type)
{
	Identity* person = NULL;//����ָ�룬ָ���������
	
	//���ļ�
	ifstream ifs;
	ifs.open(FileName,ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}

	//׼�������û���Ϣ

	string name;//�û���
	string password;//����

	//�ж����
	if (type == 1)//ѧ��
	{
		cout << "������ѧ��: " << endl;
		cin >> name;
	}
	if (type == 2)//��ʦ
	{
		cout << "������ְ����: " << endl;
		cin >> name;
	}
	if (type == 3)//����Ա
	{
		cout << "���������Ա�˺�: " << endl;
		cin >> name;
	}
	//��������
	cout << "���������룺 " << endl;
	cin >> password;

	//��֤
	if (type == 1)//��֤ѧ��
	{
		string fName;//׼�����ļ���ȡ�û���
		string fPassword;//׼�����ļ���ȡ����
		while (ifs >> fName && ifs >> fPassword)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPassword == password)//��֤��½�ɹ�
			{
				cout << " ��½�ɹ�! " << endl;
				system("pause");
				system("cls");
				person = new student(name,password);
				studentMenu(person);
				return;
			}
		}
	}
	if (type == 2)//��֤��ʦ
	{
		string fName;//׼�����ļ���ȡ�û���
		string fPassword;//׼�����ļ���ȡ����
		while (ifs >> fName && ifs >> fPassword)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPassword == password)//��֤��½�ɹ�
			{
				cout << " ��½�ɹ�! " << endl;
				system("pause");
				system("cls");
				person = new teacher(name, password);
				teacherMenu(person);
				return;
			}
		}
	}
	if (type == 3)//��֤����Ա
	{
		string fName;//׼�����ļ���ȡ�û���
		string fPassword;//׼�����ļ���ȡ����
		while (ifs >> fName && ifs >> fPassword)
		{
			//���û��������Ϣ���Ա�
			if (fName == name && fPassword == password)//��֤��½�ɹ�
			{
				cout << " ��½�ɹ�! " << endl;
				system("pause");
				system("cls");
				person = new manager(name, password);
				managerMenu(person);
				return;
			}
		}
	}
	//��½ʧ��
	cout << "\n\n\n";
	cout << "\t\t\t��½ʧ��!" << endl;
	cout << "\n\n\n";
	system("pause");
	system("cls");
	return;
}
void managerMenu(Identity*& manage)
{
	while (true)
	{
		//�����Ӳ˵�
		manage->openMenu();

		//ǿ������ת�� ���Է����Լ������Լ���һЩ����
		manager*Manager = (manager*)manage;
		cout << "����������ѡ��: " << endl;
		int select=0;
		cin >> select;
		switch (select)
		{
		case 0://�˳�ϵͳ
			cout << "�ɹ��˳���½" << endl;
			system("pause");
			system("cls");
			return;
			break;
		case 1://�鿴�����˵���Ϣ
			Manager->showPerson();
			break;
		case 2://�鿴�α���Ϣ
			Manager->showCourse();
			break;
		default:
				break;
		}
	}
}
void studentMenu(Identity*& stu)
{
	while (true)
	{
		//�����Ӳ˵�
		stu->openMenu();

		//ǿ������ת�� ���Է����Լ������Լ���һЩ����
		student* Student = (student*)stu;
		cout << "����������ѡ��: " << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 0:
			
			break;
		case 1:

			break;
		default:
			break;
		}
	}
}
void teacherMenu(Identity*& teach)
{
	while (true)
	{
		//�����Ӳ˵�
		teach->openMenu();

		//ǿ������ת�� ���Է����Լ������Լ���һЩ����
		teacher* Teacher = (teacher*)teach;
		cout << "����������ѡ��: " << endl;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 0:
			break;
		case 1:
			break;
		default:
			break;
		}
	}
}