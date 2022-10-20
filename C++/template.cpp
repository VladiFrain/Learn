#include "header.h"
using namespace std;
//шаблоны классов и функций

//функция которая меняет местами значения 2-х переменных с помощью ссылок
template <typename T>
void Swap(T &aRef, T &bRef)
{
	T temp = aRef;
	aRef = bRef;
	bRef = temp;
}
//для проверки шаблонного класса
class Temp
{
	int a = 0;
	int b = 0;
	int c = 0;
};
//шаблонный класс
template<class T>
class TypeSize
{
public:
	TypeSize(T value)
	{
		this->value = value;
	}
	void DataTypeSize()
	{
		cout << "Value " << sizeof(value) << endl;
	}

protected:
	T value;
};
//наследник шаблонного класса
template<class T>
class TypeInfo : public TypeSize<T>
{
public:
	TypeInfo(T value) : TypeSize<T>(value)
	{

	}
	void ShowTypeName()
	{
		cout << "Название типа " << typeid(this->value).name() << endl;;
	}
};
//класс для специализации шаблона
template<typename T>
class Printer
{
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};
//специализация под string
template<>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "_____" << value << "_____" << endl;
	}
};

void Template()//консольная команда: -c t
{
	//пример работы функции
	int ar = 1;
	int br = 2;
	cout << ar << " " << br << endl;
	Swap(ar, br);
	cout << ar << " " << br << endl;
	cout << endl;

	//пример работы наследника шаблонного класса
	Temp a;
	TypeInfo<Temp> c(a);
	c.ShowTypeName();
	c.DataTypeSize();
	cout << endl;

	Printer<string> printer;
	printer.Print("Hello World");
}