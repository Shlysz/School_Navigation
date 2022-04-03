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
//����Ա���ܲ˵�����
void manager::openMenu()
{
	cout << "��ӭ����Ա" <<this->m_Name<<"��½"<< endl;
	cout << "\t\t ----------------------------------------\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          1.�鿴��Ա��Ϣ	|\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          2.�鿴�γ���Ϣ       |\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          3.           |\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t|          0.��    ��           |\t\n";
	cout << "\t\t|                               |\t\n";
	cout << "\t\t ----------------------------------------\t\n";
}
void manager::showPerson()
{

	cout << "��ѡ��鿴������: " << endl;
	cout << "1.�鿴ѧ����Ϣ" << endl;
	cout << "2.�鿴��ʦ��Ϣ" << endl;

	string fileName;
	ifstream ifs;
	string name;
	string password;
	int select = 0;//�����û�ѡ��
	cin >> select;



	if (select == 1)//�鿴ѧ��
	{
		fileName = STUDENT_FILE;
		cout << "����ѧ����Ϣ���£� " << endl;
		ifs.open(fileName, ios::in);
		
	}
	if (select == 2)
	{
		fileName = ADMIN_FILE;
		cout << "���н�ʦ��Ϣ����: " << endl;
		ifs.open(fileName, ios::in);
	}
	while (ifs >> name && ifs >> password)
	{
		cout << "�û���: " << name<<" "<< "���룺"<<password<<endl;
	}
	ifs.close();
	system("pause");
	system("cls");
}
void manager::showCourse()
{
	cout << "����Ҫ�鿴ʲô�γ���Ϣ��" << endl;
	cout << "1.���пγ̵���Ϣ" << endl;
	cout << "2.�ض�ѧ������Ϣ" << endl;
	cout << "3.�ض���ʦ����Ϣ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{	
		ifstream ifs;
		ifs.open(COURSE_FILE, ios::in);//���ļ��ܱ�
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
		cout << "����鿴�ĸ�ѧ���Ŀα���������/����ѧ��" << endl;
		string name;
		cin >> name;
		name += ".txt";
		ifstream ifs;
		ifs.open(name,ios::in);
		if (!ifs.is_open())
		{
			cout << "��û�д�ѧ���Ŀα��û��ѧ��" << endl;
		}

		ifs.close();
	}
	else if (select == 3)
	{
		cout << "����鿴��λ��ʦ�Ŀα���������/����ְ����" << endl;
		string name;
		cin >> name;
		name += ".txt";
		ifstream ifs;
		ifs.open(name, ios::in);
		if (!ifs.is_open())
		{
			cout << "��û�д˽�ʦ�Ŀα�" << endl;
			return;
		}
		ifs.close();
	
	}
	else
	{
		cout << "��Ч������" << endl;
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
	string cName;//����γ�����
	string cTeacher;//����γ̽�ʦ
	string cStart_week;//����γ̿�ʼ��
	string cEnd_week;//����γ̽�����
	ifs >> cName;
	ifs >> cTeacher;
	ifs >> cStart_week;
	ifs >> cEnd_week;
	cout << cName << " " << "�ڿν�ʦ��" << cTeacher << " "
		<< cStart_week << "��" << cEnd_week << "��"
		<< endl;
	char lines;
	ifs >> lines;
	string Day;//��¼�ܼ��Ͽ�
	string beginTime;
	string endTime;//��¼��ʼ�ͽ���ʱ��
	string Place;
	for (int i = 0; i<lines - 48 && ifs >> Day && ifs >> beginTime && ifs >> endTime && ifs >> Place; i++)
	{
		cout << "��" << Day << " " << "��" << beginTime 
			<< "��" << "����" << endTime << "�� "
			<< Place << endl;
	}
	ifs.close();//�ر��ļ�
}
