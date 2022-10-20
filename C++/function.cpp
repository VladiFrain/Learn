#include "header.h"
#include <functional>
#include <vector>

using namespace std;
//������ � std::function

void Fun(int a)
{
	if (a > 10 && a < 40)
	{
		cout << "Fun " << a << endl;
	}
}

void Tra(int a)
{
	if (a % 2 == 0)
	{
		cout << "Tra " << a << endl;
	}
}
//��� std::function
void DoWo(vector<int>& vc, vector<function<void(int a)>> funcVector)
{
	for (auto el : vc)
	{
		for (auto& fel : funcVector)
		{
			fel(el);
		}
	}
}
//��� ������-�������
void DoWor(vector<int>& vc, function<void(int a)> funcVector)
{
	for (auto el : vc)
	{
		funcVector(el);
	}
}

//����� ��� ������������� ������-�������
class MyClass
{
public:
	int a = 11;
	void Msg()
	{
		cout << "msg" << endl;
	}
	
	void Lampda()
	{
		auto f = [this]()//������� ����� � �������� ������-�������
		{
			this->Msg();
		};
		f();
	}
};

void Function()// ������� ������� : -fu
{
	//����� ��������� ������ ������� � ����������� ��� � ������� �������
	function<void(int a)> func;
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };
	vector< function<void(int a)>> fVector;
	fVector.emplace_back(Fun);
	fVector.emplace_back(Tra);
	DoWo(vc, fVector);
	cout << endl;
	//==================================

	//������-�������

	int p = 0;
	//����� ���������� ����� ���������� ������� ����������
	//��� ������������� �������� ������������ �� return
	auto f = [&p]()//��������� �������
	{
		p = 5;
	};
	f();
	cout << endl;

	//������������� Tra ��� ������ ��������� �������
	DoWor(vc, [](int a)//��������� �������
		{
			if (a % 2 == 0)
			{
				cout << "Tra-������ " << a << endl;
			}
		});
	cout << endl;

	int b = 12;
	//�������� ��������� �� ��������(��� ������)
	//�������� ��������� �� ������
	auto a = [p, &b]()
	{
		cout << p << endl;
		b = 123;
	};
	a();
	cout << endl;

	//= - �������� ��� ���������� �� ��������(��� ������)
	auto al = [=]()mutable//������ ��������� ��� � ��������� �� ��������(�� �������� � �������)
	{
		cout << p << " " << b << endl;
		p = 12;
		b = 1;
	};
	al();
	cout << endl;

	//& - �������� ��� ���������� �� ������(��� ���������)
	auto all = [&]()
	{
		cout << p << " " << b << endl;
		p = 12;
		b = 1;
	};
	all();
	cout << endl;

	//������������� ������ ������� ������ ������
	MyClass m;
	m.Lampda();

	auto t = []()->int//��������� ��� ������������� ��������
	{
		return 1;
	};
}