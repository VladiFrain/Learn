#include "header.h"
#include <thread>
#include <mutex>
using namespace std;
//работа с потоками часть 3 - синхронизация потоков

//блокировщик потока
mutex mtx;

void Print(char ch)
{
	//эмуляция сложного вычисления без необходимости защиты потоков
	this_thread::sleep_for(chrono::milliseconds(2000));

	//блокируем участок кода для доступа другим потокам
	//mtx.lock(); - вариант защиты данных

	{//разграничение доступа кода(нежелательно использовать)
		//создание объекта для автоматической блокировки и разблокировки кода от других потоков в функции
		lock_guard<mutex> guard(mtx); //- должна быть отдельная функция в которую помещена задача требующая защиты потоков

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
	}//разграничение доступа кода(нежелательно использовать)

	//разблокируем участок кода для доступа другим потокам
	//mtx.unlock(); - вариант защиты данных

	//эмуляция сложного вычисления без необходимости защиты потоков
	this_thread::sleep_for(chrono::milliseconds(2000));
}

//================================
//DeadBlock - взаимная блокировка
mutex mtx1;
mutex mtx2;
//необходимо соблюдать порядок захвата mutex, иначе программа не будет выполняться
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
//recursive_mutex - несколько раз позволяет захватить mutex(помнит сколько раз его заблокировали)
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

void Mutex()// команда консоли : - mu
{
	thread t1(Print, '*');
	thread t2(Print, '#');

	t1.join();
	t2.join();

	cout << endl;

	//================================
	//DeadBlock - взаимная блокировка
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
//написал снизу чтобы далеко не листать
void Prints(char ch)
{
	//есть доп опции в отличии от lock_guard	
	unique_lock<mutex> ul(mtx, defer_lock); //defer_lock - в момент создания не будет выполнен lock

	//эмуляция сложного вычисления без необходимости защиты потоков
	this_thread::sleep_for(chrono::milliseconds(2000));

	//заблокируем доступ при помощи unique_lock
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

	//разблокируем доступ при помощи unique_lock
	ul.unlock();

	//эмуляция сложного вычисления без необходимости защиты потоков
	this_thread::sleep_for(chrono::milliseconds(2000));
}