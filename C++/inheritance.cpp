#include "header.h"
using namespace std;
//������ ������������(������������ ����������)
//��������� struct - ������� �� class ��� ���� � ������ �� ��������� public

class Person
{
public:
	//�������� ����� �� ��������� ������ ������������
	Person()
	{
		this->name = "NoName";
		this->age = 0;
		this->weight = 0;
	}
	//������������ ������������
	Person(string name)
	{
		this->name = name;
		this->age = 0;
		this->weight = 0;
	}

	Person(string name, int age) : Person(name)//�������� name � ����������� � ����� ����������
	{
		this->age = age;
	}

	Person(string name, int age, int weight) : Person(name, age)//�������� name � age � ����������� � ����� �����������
	{
		this->weight = weight;
	}

	void SetName(string name)
	{
		this->name = name;
	}

private:
	string name;
	int age;
	int weight;
};

class Student : public Person
{
public:
	string group;
	void Learn()
	{
		cout << "� �����!" << endl;
	}
};

class ExtramuralStudent : public Student
{
public:
	//�������� ����� �������� ������
	void Learn()
	{
		cout << "� ����� � ������������ ���� �������� ��������!" << endl;
	}
};

class Professor : public Person
{
public:
	string subject;
};

//������ ������ public private protected ��� ������������
class A
{
public:
	A()
	{
		cout << "�������� ����������� ������ �" << endl;
		cout << "�������� ������������ ������ ������� ������ �" << endl;//��� ������� ��� �������� ����������� ����������
	}
	A(string msg)
	{
		this->msgTwo = msg;
		cout << "�������� ����������� ������ � � ����������: " << this->msgTwo << endl;
		cout << "�������� ������������ ������ ������� ������ �" << endl;//��� ������� ��� �������� ����������� ����������
	}
	virtual ~A()//����� � ����� ������ ���� ������� ��� ����������� ������� �����������
	{
		cout << "�������� ���������� ������ �" << endl;
		cout << "����������� ������������ ������ ������� ������ �" << endl;//��� ������� ��� �������� ����������� ����������
	}

	void PrintMsgTwo()
	{
		cout << msgTwo << endl;
	}

	string msgOne = "One";
private:
	string msgTwo = "Two";
protected://����� �������������� � ������� �����������
	string msgThree = "Three";
};

class B : public A //������ � ����� � ������� �� ��������, ��� private ��� ���� � ������ ����������� private, protected ���������� public � protected
{
public:
	//�������� ����������� �������� ������ � 1 ����������
	B() : A("����� ���������")
	{
		cout << "�������� ����������� ������ B" << endl;
		cout << "�������� ������������ ������ ������� ������ B" << endl;//��� ������� ��� �������� ����������� ����������
	}
	~B() override//���������� �������������� ���������� ����� �������� ������ ������
	{
		cout << "�������� ���������� ������ B" << endl;
		cout << "����������� ������������ ������ ������� ������ B" << endl;//��� ������� ��� �������� ����������� ����������
	}
	void PrintMsg()
	{
		cout << msgOne << endl;
		//cout << msgTwo << endl; - ������ ��� ��� ���� private
		cout << msgThree << endl;
	}
};

class C : public B
{
public:
	//�������� ����������� �� ��������� �������� ������
	C()
	{
		cout << "�������� ����������� ������ C" << endl;
		cout << "�������� ������������ ������ ������� ������ C" << endl;//��� ������� ��� �������� ����������� ����������
	}
	~C() override//���������� �������������� ���������� ����� �������� ������ ������
	{
		cout << "�������� ���������� ������ C" << endl;
		cout << "����������� ������������ ������ ������� ������ C" << endl;//��� ������� ��� �������� ����������� ����������
	}
};

void Inheritance() //���������� �������: -c i
{
	Student st;
	st.SetName("���");
	st.Learn();
	ExtramuralStudent extraSt;
	extraSt.Learn();
	Professor pr;

	cout << endl;

	A aa;
	cout << endl;
	A ab("���������");
	cout << endl;
	B bb;
	cout << endl;
	C cc;

	cout << endl;

	A *bptr = new B;//���������� ����� ������ ��� ��������� �� ������ ������ � �������� ������ ������ � �
	delete bptr;//��� ��������������� ����������� ����� ������ ������ ���������� �������� ������

	cout << endl;

	bb.msgOne;//��������� ���� ���������� ��� ������
	bb.PrintMsg();

	Person pes("ϸ�", 12, 120);//������������ ��� ������������ ������������
}