#include "header.h"
#include <thread>
#include <mutex>
using namespace std;
//������ � �������� ����� 3 - ������������� �������

//����������� ������
mutex mtx;

void Print(char ch)
{
	//�������� �������� ���������� ��� ������������� ������ �������
	this_thread::sleep_for(chrono::milliseconds(2000));

	//��������� ������� ���� ��� ������� ������ �������
	//mtx.lock(); - ������� ������ ������

	{//������������� ������� ����(������������ ������������)
		//�������� ������� ��� �������������� ���������� � ������������� ���� �� ������ ������� � �������
		lock_guard<mutex> guard(mtx); //- ������ ���� ��������� ������� � ������� �������� ������ ��������� ������ �������

		for (size_t i = 0; i < 5; i++)
		{
			for (size_t i = 0; i < 10; i++)
			{
				cout << ch;
				this_thread::sleep_for(chrono::milliseconds(20));
			}
			cout << endl;
		}
		cout << endl;
	}//������������� ������� ����(������������ ������������)

	//������������ ������� ���� ��� ������� ������ �������
	//mtx.unlock(); - ������� ������ ������

	//�������� �������� ���������� ��� ������������� ������ �������
	this_thread::sleep_for(chrono::milliseconds(2000));
}

//================================
//DeadBlock - �������� ����������
mutex mtx1;
mutex mtx2;
//���������� ��������� ������� ������� mutex, ����� ��������� �� ����� �����������
void Print1()
{
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(1));
	mtx2.lock();

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << '*'; this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	mtx1.unlock();
	mtx2.unlock();
}

void Print2()
{
	mtx1.lock();
	this_thread::sleep_for(chrono::milliseconds(1));
	mtx2.lock();

	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << '#'; this_thread::sleep_for(chrono::milliseconds(10));
		}
		cout << endl;
	}
	cout << endl;
	mtx1.unlock();
	mtx2.unlock();
}

//========================================
//recursive_mutex - ��������� ��� ��������� ��������� mutex(������ ������� ��� ��� �������������)
recursive_mutex rm;
void Te(int a)
{
	rm.lock();
	cout << a << " ";
	this_thread::sleep_for(chrono::milliseconds(500));
	if (a <= 1)
	{
		cout << endl;
		rm.unlock();
		return;
	}
	a--;
	Te(a);
	rm.unlock();
}

void Mutex()// ������� ������� : - mu
{
	thread t1(Print, '*');
	thread t2(Print, '#');

	t1.join();
	t2.join();

	cout << endl;

	//================================
	//DeadBlock - �������� ����������
	cout << "DeadBlock" << endl;

	thread tdb1(Print1);
	thread tdb2(Print2);

	tdb1.join();
	tdb2.join();

	cout << endl;

	//========================================
	//recursive_mutex
	thread trm1(Te, 10);
	thread trm2(Te, 10);

	trm1.join();
	trm2.join();

	cout << endl;

	//===================================
	//unique_lock
	void Prints(char ch);
	thread tul1(Prints, '@');
	thread tul2(Prints, '%');

	tul1.join();
	tul2.join();
}
//������� ����� ����� ������ �� �������
void Prints(char ch)
{
	//���� ��� ����� � ������� �� lock_guard	
	unique_lock<mutex> ul(mtx, defer_lock); //defer_lock - � ������ �������� �� ����� �������� lock

	//�������� �������� ���������� ��� ������������� ������ �������
	this_thread::sleep_for(chrono::milliseconds(2000));

	//����������� ������ ��� ������ unique_lock
	ul.lock();
	for (size_t i = 0; i < 5; i++)
	{
		for (size_t i = 0; i < 10; i++)
		{
			cout << ch;
			this_thread::sleep_for(chrono::milliseconds(20));
		}
		cout << endl;
	}
	cout << endl;

	//������������ ������ ��� ������ unique_lock
	ul.unlock();

	//�������� �������� ���������� ��� ������������� ������ �������
	this_thread::sleep_for(chrono::milliseconds(2000));
}