#include "header.h"
using namespace std;
//������� ������� � �������

//������� ������� ������ ������� �������� 2-� ���������� � ������� ������
template <typename T>
void Swap(T &aRef, T &bRef)
{
	T temp = aRef;
	aRef = bRef;
	bRef = temp;
}
//��� �������� ���������� ������
class Temp
{
	int a = 0;
	int b = 0;
	int c = 0;
};
//��������� �����
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
//��������� ���������� ������
template<class T>
class TypeInfo : public TypeSize<T>
{
public:
	TypeInfo(T value) : TypeSize<T>(value)
	{

	}
	void ShowTypeName()
	{
		cout << "�������� ���� " << typeid(this->value).name() << endl;;
	}
};
//����� ��� ������������� �������
template<typename T>
class Printer
{
public:
	void Print(T value)
	{
		cout << value << endl;
	}
};
//������������� ��� string
template<>
class Printer<string>
{
public:
	void Print(string value)
	{
		cout << "_____" << value << "_____" << endl;
	}
};

void Template()//���������� �������: -c t
{
	//������ ������ �������
	int ar = 1;
	int br = 2;
	cout << ar << " " << br << endl;
	Swap(ar, br);
	cout << ar << " " << br << endl;
	cout << endl;

	//������ ������ ���������� ���������� ������
	Temp a;
	TypeInfo<Temp> c(a);
	c.ShowTypeName();
	c.DataTypeSize();
	cout << endl;

	Printer<string> printer;
	printer.Print("Hello World");
}