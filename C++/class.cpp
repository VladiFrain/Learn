#include "header.h"
using namespace std;
//������ � ��������

//����������� ������
class MyClass
{
public:
	//����������� �����������
	MyClass(const MyClass &other)
	{
		this->size = other.size;
		this->data = new int[other.size];
		for (int i = 0; i < other.size; i++)
		{
			this->data[i] = other.data[i];
		}
		cout << "������ " << this << " �������� ����������� �����������" << endl;
	}

	MyClass(int size)
	{
		this->size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = i;
		}
		cout << "������ " << this << " �������� ����������� " << endl;
	}
	//���������� ��������� =
	MyClass &operator = (const MyClass &other)
	{
		cout << "�������� �������� = " << this << endl;
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
		cout << "������ " << this << " �������� ����������" << endl;
		delete[] data;
	}

private:
	int* data;
	int size;
};

//���������� ��������� ��������������
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

void Clases() //������� �������: -c c
{
	//������ ������������� �������������� ��������� []
	TestClass a;
	cout << a[0] << endl;
	a[0] = 100;
	cout << a[0] << endl;
	a.PrintMessage();
	cout << endl;
}