#include <iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include "globalFile.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"

//登陆功能
void  LoginIn(string FileName, int type);//参数名1 要打开的文件 参数2 要登陆人员的身份类型
void managerMenu(Identity *&manage);	//进入管理员子菜单界面
void studentMenu(Identity*& stu);	//进入学生子菜单界面
void teacherMenu(Identity*& teach);	//进入老师子菜单界面
int main()
{
	int select = 0;//接受选择
	while (true)
	{
		cout << "======================  欢迎来到北京邮电大学校园导航系统  ====================="
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.学    生           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.老    师           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.管 理 员           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.退    出           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "输入您的选择: ";
		cin >> select;
		switch (select)
		{
		case 1://学生登陆
			LoginIn(STUDENT_FILE,1);
			break;
		case 2://老师登陆
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://管理员登陆
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://退出
			cout << "\n\n\n";
			cout << "\t\t\t欢迎下次使用！" << endl;
			cout << "\n\n\n";
			system("pause");
			exit(0);

			break;
		default:
			cout << "\n\n\n";
			cout << "\t\t\t输入有误，请重新输入！" << endl;
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
	Identity* person = NULL;//父类指针，指向子类对象
	
	//读文件
	ifstream ifs;
	ifs.open(FileName,ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接受用户信息

	string name;//用户名
	string password;//密码

	//判断身份
	if (type == 1)//学生
	{
		cout << "请输入学号: " << endl;
		cin >> name;
	}
	if (type == 2)//教师
	{
		cout << "请输入职工号: " << endl;
		cin >> name;
	}
	if (type == 3)//管理员
	{
		cout << "请输入管理员账号: " << endl;
		cin >> name;
	}
	//输入密码
	cout << "请输入密码： " << endl;
	cin >> password;

	//验证
	if (type == 1)//验证学生
	{
		string fName;//准备从文件读取用户名
		string fPassword;//准备从文件读取密码
		while (ifs >> fName && ifs >> fPassword)
		{
			//与用户输入的信息做对比
			if (fName == name && fPassword == password)//验证登陆成功
			{
				cout << " 登陆成功! " << endl;
				system("pause");
				system("cls");
				person = new student(name,password);
				studentMenu(person);
				return;
			}
		}
	}
	if (type == 2)//验证老师
	{
		string fName;//准备从文件读取用户名
		string fPassword;//准备从文件读取密码
		while (ifs >> fName && ifs >> fPassword)
		{
			//与用户输入的信息做对比
			if (fName == name && fPassword == password)//验证登陆成功
			{
				cout << " 登陆成功! " << endl;
				system("pause");
				system("cls");
				person = new teacher(name, password);
				teacherMenu(person);
				return;
			}
		}
	}
	if (type == 3)//验证管理员
	{
		string fName;//准备从文件读取用户名
		string fPassword;//准备从文件读取密码
		while (ifs >> fName && ifs >> fPassword)
		{
			//与用户输入的信息做对比
			if (fName == name && fPassword == password)//验证登陆成功
			{
				cout << " 登陆成功! " << endl;
				system("pause");
				system("cls");
				person = new manager(name, password);
				managerMenu(person);
				return;
			}
		}
	}
	//登陆失败
	cout << "\n\n\n";
	cout << "\t\t\t登陆失败!" << endl;
	cout << "\n\n\n";
	system("pause");
	system("cls");
	return;
}
void managerMenu(Identity*& manage)
{
	while (true)
	{
		//调用子菜单
		manage->openMenu();

		//强制类型转换 ，以方便自己调用自己的一些函数
		manager*Manager = (manager*)manage;
		cout << "请输入您的选项: " << endl;
		int select=0;
		cin >> select;
		switch (select)
		{
		case 0://退出系统
			cout << "成功退出登陆" << endl;
			system("pause");
			system("cls");
			return;
			break;
		case 1://查看所有人的信息
			Manager->showPerson();
			break;
		case 2://查看课表信息
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
		//调用子菜单
		stu->openMenu();

		//强制类型转换 ，以方便自己调用自己的一些函数
		student* Student = (student*)stu;
		cout << "请输入您的选项: " << endl;
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
		//调用子菜单
		teach->openMenu();

		//强制类型转换 ，以方便自己调用自己的一些函数
		teacher* Teacher = (teacher*)teach;
		cout << "请输入您的选项: " << endl;
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