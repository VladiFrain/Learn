#include "header.h"
#include <thread>
#include <chrono>
using namespace std;
//������ � ��������

//�������� ������ ������
void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID ������ = " << this_thread::get_id() << " DoWork " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

//�������� ������ ������ � ��������� ����������
void DoWorker(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "============" << "DoWorker Start" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "============" << "DoWorker End" << endl;
}

//�������� ������ ������ � ��������� �������� �� ������
void DoWorkerer(int &a)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID ������ = " << this_thread::get_id() << "============" << "DoWorkerer Start" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 2;
	cout << "============" << "DoWorkerer End" << endl;
}

//�������� ������ ������ � ��������� ����������
int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "ID ������ = " << this_thread::get_id() << " ======================Sum start" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "ID ������ = " << this_thread::get_id() << " ======================Sum stop" << endl;
	return a + b;
}

void Thread()// ������� ������� : -t
{
	//������������� ������ ���������
	int result;
	thread t([&result]()
		{
			result = Sum(2, 5); 
		});

	//�������� ��������� �� ������ � �����
	int q = 5;
	thread th(DoWorkerer, std::ref(q));

	//�������� ���������� ������� � ��������� ����� � �����������
	thread th1(DoWorker, 5, 6);

	//�������� ���������� ������� � ��������� �����
	thread th2(DoWork);

	//���������� � ��������� ����������(�������)
	//th.detach();
	
	//�������� �������� ������
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID ������ = " << this_thread::get_id() << " main " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	//��� ����� �������� ��������(�������)
	t.join();
	cout << "Sum result = " << result << endl;
	th.join();
	cout << q << endl;
	th1.join();
	th2.join();
}