#include"Student.h"
student::student()
{

}
student::student(string name, string password)
{
	this->m_Name = name;
	this->m_Password = password;

}
//学生的功能菜单
void student::openMenu()
{

	cout << "这是学生的菜单" << endl;

}