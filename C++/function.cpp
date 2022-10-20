#include "header.h"
#include <functional>
#include <vector>

using namespace std;
//работа с std::function

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
//для std::function
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
//для лямбда-функций
void DoWor(vector<int>& vc, function<void(int a)> funcVector)
{
	for (auto el : vc)
	{
		funcVector(el);
	}
}

//класс для использования лямбда-функций
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
		auto f = [this]()//передаём класс в контекст лямбда-функции
		{
			this->Msg();
		};
		f();
	}
};

void Function()// команда консоли : -fu
{
	//может принимать только функцию с параметрами как в угловых скобках
	function<void(int a)> func;
	vector<int> vc = { 1,51,4,10,44,98,8,12,22,29,49 };
	vector< function<void(int a)>> fVector;
	fVector.emplace_back(Fun);
	fVector.emplace_back(Tra);
	DoWo(vc, fVector);
	cout << endl;
	//==================================

	//лямбда-функции

	int p = 0;
	//через квадратные скоби передаются внешние переменные
	//тип возвращаемого значения определяется по return
	auto f = [&p]()//анонимная функция
	{
		p = 5;
	};
	f();
	cout << endl;

	//использование Tra при помощи анонимной функции
	DoWor(vc, [](int a)//анонимная функция
		{
			if (a % 2 == 0)
			{
				cout << "Tra-лямбда " << a << endl;
			}
		});
	cout << endl;

	int b = 12;
	//передача параметра по значению(для чтения)
	//передача параметра по ссылке
	auto a = [p, &b]()
	{
		cout << p << endl;
		b = 123;
	};
	a();
	cout << endl;

	//= - получаем все переменные по значению(для чтения)
	auto al = [=]()mutable//создаёт поведение как у параметра по значению(не работает с сылками)
	{
		cout << p << " " << b << endl;
		p = 12;
		b = 1;
	};
	al();
	cout << endl;

	//& - получаем все переменные по ссылке(для изменения)
	auto all = [&]()
	{
		cout << p << " " << b << endl;
		p = 12;
		b = 1;
	};
	all();
	cout << endl;

	//использование лямбда функции внутри класса
	MyClass m;
	m.Lampda();

	auto t = []()->int//указываем тип возвращаемого значения
	{
		return 1;
	};
}