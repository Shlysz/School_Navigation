#include"Manager.h"
#include <fstream>
#include"globalFile.h"
manager::manager()
{

}
manager::manager(string name,string password)
{
	this->m_Name = name;
	this->m_Password = password;
}
//管理员功能菜单界面
void manager::openMenu()
{
	cout << "欢迎管理员" <<this->m_Name<<"登陆"<< endl;
	cout << "\t\t ----------------------------------------\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          1.查看人员信息	|\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          2.查看课程信息       |\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          3.           |\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          0.退    出           |\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t ----------------------------------------\t\n";
}
void manager::showPerson()
{

	cout << "请选择查看的内容: " << endl;
	cout << "1.查看学生信息" << endl;
	cout << "2.查看老师信息" << endl;

	string fileName;
	ifstream ifs;
	string name;
	string password;
	int select = 0;//接受用户选择
	cin >> select;



	if (select == 1)//查看学生
	{
		fileName = STUDENT_FILE;
		cout << "所有学生信息如下： " << endl;
		ifs.open(fileName, ios::in);
		
	}
	if (select == 2)
	{
		fileName = ADMIN_FILE;
		cout << "所有教师信息如下: " << endl;
		ifs.open(fileName, ios::in);
	}
	while (ifs >> name && ifs >> password)
	{
		cout << "用户名: " << name<<" "<< "密码："<<password<<endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
void manager::showCourse()
{
	cout << "您是要查看什么课程信息？" << endl;
	cout << "1.所有课程的信息" << endl;
	cout << "2.特定学生的信息" << endl;
	cout << "3.特定教师的信息" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{	
		ifstream ifs;
		ifs.open(COURSE_FILE, ios::in);//打开文件总表
		char buf[100];
		char c;
		int k = 0;
		string name;
		while (k == 0)
		{

			int i = 0;
			while ((c = ifs.get()) != '\n')
			{
				if (!ifs.eof())
				{

					buf[i] = c;
					i++;
				}
				else
				{
					k = 1;
					break;
				}

			}
			if (k == 0)
			{
				name.clear();
				name.append(buf, 0, 2);
				name += ".txt";
				PrintCourse(name);
			}
		}
		ifs.close();
	}
	else if (select == 2)
	{
		cout << "您想查看哪个学生的课表，请输入她/他的学号" << endl;
		string name;
		cin >> name;
		name += ".txt";
		ifstream ifs;
		ifs.open(name,ios::in);
		if (!ifs.is_open())
		{
			cout << "并没有此学生的课表或并没有学生" << endl;
		}

		ifs.close();
	}
	else if (select == 3)
	{
		cout << "您想查看哪位教师的课表，请输入她/他的职工号" << endl;
		string name;
		cin >> name;
		name += ".txt";
		ifstream ifs;
		ifs.open(name, ios::in);
		if (!ifs.is_open())
		{
			cout << "并没有此教师的课表" << endl;
			return;
		}
		ifs.close();
	
	}
	else
	{
		cout << "无效的输入" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}
void manager::PrintCourse(string fname)
{
	ifstream ifs(fname, ios::in);
	string cName;//保存课程名称
	string cTeacher;//保存课程教师
	string cStart_week;//保存课程开始周
	string cEnd_week;//保存课程结束周
	ifs >> cName;
	ifs >> cTeacher;
	ifs >> cStart_week;
	ifs >> cEnd_week;
	cout << cName << " " << "授课教师：" << cTeacher << " "
		<< cStart_week << "到" << cEnd_week << "周"
		<< endl;
	char lines;
	ifs >> lines;
	string Day;//记录周几上课
	string beginTime;
	string endTime;//记录开始和结束时间
	string Place;
	for (int i = 0; i<lines - 48 && ifs >> Day && ifs >> beginTime && ifs >> endTime && ifs >> Place; i++)
	{
		cout << "周" << Day << " " << "第" << beginTime 
			<< "节" << "到第" << endTime << "节 "
			<< Place << endl;
	}
	ifs.close();//关闭文件
}
