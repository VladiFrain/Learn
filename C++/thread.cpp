#include "header.h"
#include <thread>
#include <chrono>
using namespace std;
//работа с потоками

//эмул€ци€ т€жЄлой задачи
void DoWork()
{
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << " DoWork " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(1000));
	}
}

//эмул€ци€ т€жЄлой задачи с передачей параметров
void DoWorker(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "============" << "DoWorker Start" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "a + b = " << a + b << endl;
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "============" << "DoWorker End" << endl;
}

//эмул€ци€ т€жЄлой задачи с возвратом значени€ по ссылке
void DoWorkerer(int &a)
{
	this_thread::sleep_for(chrono::milliseconds(3000));
	cout << "ID потока = " << this_thread::get_id() << "============" << "DoWorkerer Start" << endl;

	this_thread::sleep_for(chrono::milliseconds(5000));
	a *= 2;
	cout << "============" << "DoWorkerer End" << endl;
}

//эмул€ци€ т€жЄлой задачи с возвратом результата
int Sum(int a, int b)
{
	this_thread::sleep_for(chrono::milliseconds(2000));
	cout << "ID потока = " << this_thread::get_id() << " ======================Sum start" << endl;
	this_thread::sleep_for(chrono::milliseconds(5000));
	cout << "ID потока = " << this_thread::get_id() << " ======================Sum stop" << endl;
	return a + b;
}

void Thread()// команда консоли : -t
{
	//использование л€мбда выражени€
	int result;
	thread t([&result]()
		{
			result = Sum(2, 5); 
		});

	//передача параметра по ссылке в поток
	int q = 5;
	thread th(DoWorkerer, std::ref(q));

	//передача выполнени€ функции в отдельный поток с параметрами
	thread th1(DoWorker, 5, 6);

	//передача выполнени€ функции в отдельный поток
	thread th2(DoWork);

	//отправл€ем в свободное выполнение(вариант)
	//th.detach();
	
	//эмул€ци€ основной задачи
	for (size_t i = 0; i < 10; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << " main " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}

	//ждЄм когда закончит работать(вариант)
	t.join();
	cout << "Sum result = " << result << endl;
	th.join();
	cout << q << endl;
	th1.join();
	th2.join();
}