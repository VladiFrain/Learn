#include "header.h"
using namespace std;
//��������� ���������� try catch

class MyException : public exception
{
public:
	MyException(const char *msg, int dataState) : exception(msg)
	{
		this->dataState = dataState;
	}
	int GetDataState()
	{
		return dataState;
	}
private:
	int dataState;
};
//����� � ������� ������� ����������
void TestExceptions(int value)
{
	if (value < 0)
	{
		throw value;//������� ������ � ����� int
	}
	if (value == 0)
	{
		throw "����� ����� 0!!!";//������� ������ � ����� char
	}
	if (value > 1000)
	{
		throw exception("����� ������ 1000!");//������� ������ ��������� ����� exception
	}
	if (value == 50)
	{
		throw 82.2;//������� ���������������� ����������
	}
	if (value == 1)
	{
		throw MyException("����� = 1", value);//������� ������ ��������� ���� ����� exception
	}

	cout << "���������� = " << value << endl;
}

void Exceptions()//���������� �������: -e
{
	try
	{
		
		//����� ������� ������ ������ ����������
		TestExceptions(1);
		//�� ��� ���� �� ����� ����� try ����������� �� �����
		TestExceptions(-50);
		TestExceptions(0);
		TestExceptions(1050);
		TestExceptions(50);
	}
	//������������ ������ � ����� int
	catch (const int ex)
	{
		cout << "���� 1 " << "�� ������� " << ex << endl;
	}
	//������������ ������ � ����� char
	catch (const char *ex)
	{
		cout << "���� 2 " << ex << endl;
	}
	//������������ ������ ��������� ���� ����� exception
	catch (const MyException &ex)
	{
		cout << "���� 3 " << ex.what() << endl;
	}
	//������������ ������ ��������� ����� exception
	catch (const exception &ex)
	{
		cout << "���� 4 " << ex.what() << endl;
	}
	//����� ��� ��������� ����������
	//��������� ����� ���������, ����� ����� ����������� ��� ����������
	catch (...)
	{
		cout << "���� 5 " << "���-�� ����� �� ���!" << endl;
	}
}