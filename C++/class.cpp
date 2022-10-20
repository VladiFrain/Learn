#include "header.h"
using namespace std;
//работа с классами

//Копирование класса
class MyClass
{
public:
	//конструктор копирования
	MyClass(const MyClass &other)
	{
		this->size = other.size;
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "Объект " << this << " Вызвался конструктор копирования" << endl;
	}

	MyClass(int size)
	{
		this->size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "Объект " << this << " Вызвался конструктор " << endl;
	}
	//перегрузка оператора =
	MyClass &operator = (const MyClass &other)
	{
		cout << "Вызвался оператор = " << this << endl;
		this->size = other.size;
		if (this->data != nullptr)
		{
			delete[] this->data;
		}
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		return *this;
	}

	~MyClass()
	{
		cout << "Объект " << this << " Вызвался деструктор" << endl;
		delete[] data;
	}

private:
	int* data;
	int size;
};

//перегрузка оператора индексирования
class TestClass
{
public:
	int &operator[](int index)
	{
		return arr[index];
	}

	void PrintMessage();

private:
	int arr[5] { 5, 44, 4, 987, 69 };
};

void TestClass::PrintMessage()
{
	cout << "Hello" << endl;
}

void Clases() //команда консоли: -c c
{
	//пример использования перегруженного оператора []
	TestClass a;
	cout << a[0] << endl;
	a[0] = 100;
	cout << a[0] << endl;
	a.PrintMessage();
	cout << endl;
}