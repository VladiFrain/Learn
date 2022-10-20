#include "header.h"
using namespace std;
//����������� ������������(�����������)

//������ ��� �������������
class Component
{
public:
	string companyName;
	Component(string companyName)
	{
		cout << "����������� Component" << endl;
		this->companyName = companyName;
	}
};
//� ������� ������ ����� ���� �������� ����� Component
class GPU : public Component
{
public:
	GPU(string companyName) : Component(companyName)
	{
		cout << "����������� GPU" << endl;
	}
};
//� ������� ������ ����� ���� �������� ����� Component
class Memory : public Component
{
public:
	Memory(string companyName) : Component(companyName)
	{
		cout << "����������� Memory" << endl;
	}
};
//� ������� ������ � ����� ������������ ����� ��� ������� ������ Component
class GraphicCard : public GPU, public Memory
{
public:
	GraphicCard(string GPUCompanyName, string MemoryCompanyName) : GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << "����������� GraphicCard" << endl;
	}
};
//����� ������� ��� �������������
//===============================
//������ ������������ ������������(������������)
class Character
{
public:
	//���� ��� ������������ ������������ �� � ������ ��������� ��������� ��������,
	//��� � ���������� ������ ����� ��������� ���� ��������
	int HP;
	Character()
	{
		cout << "����������� Character" << endl;
	}
};
//����������� �� ������ Character
class Orc : public virtual Character
{
public:
	Orc()
	{
		cout << "����������� Orc" << endl;
	}
};
//����������� �� ������ ���������� ������ Character ��� � ����� Orc
class Warrior : public virtual Character
{
public:
	Warrior()
	{
		cout << "����������� Warrior" << endl;
	}
};
//� ������� ������ � ����� ������������ ������ ���� ������� ����� Character
class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "����������� OrcWarrior" << endl;
	}
};

void VirtualInheritance()//���������� �������: -c v
{
	//���������� ��� �������� ������ � ������������� ������������� ��� �������������
	GraphicCard graphicCard("NVIDIA", "SAMSUNG");
	cout << endl;
	//���������� ��� �������� ������ � ������������� ������������� � ��������������
	OrcWarrior orcWarrior;
}