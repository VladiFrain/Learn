#include "header.h"
#include <thread>
using namespace std;
//время выполнения участка кода(2 часть thread)

//отдельный класс для передачи его методов в отдельный поток
class MyTestThread
{
public:
	void DoWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << " ======================DoWork Test Start" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << " ======================DoWork Test Stop" << endl;
	}

	void DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << " ======================DoWork2 Test Start" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "DoWork2 param =\t" << a << endl;
		cout << "ID потока = " << this_thread::get_id() << " ======================DoWork2 Test Stop" << endl;
	}

	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID потока = " << this_thread::get_id() << " ======================Sum Test start" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID потока = " << this_thread::get_id() << " ======================Sum Test stop" << endl;
		return a + b;
	}
};

//отдельный класс для подсчёта времени работы кода
class SimpleTimer
{
public:
	SimpleTimer()
	{
		start = chrono::high_resolution_clock::now();
	}
	~SimpleTimer()
	{
		end = chrono::high_resolution_clock::now();
		std::chrono::duration<float> duration = end - start;
		cout << "DURATION = " << duration.count() << "s" << endl;
	}
private:
	std::chrono::time_point<std::chrono::steady_clock> start, end;
};

//эмуляция тяжёлой задачи с возвратом результата
int Sums(int a, int b)
{
	//используем класс для измерения времени функции
	SimpleTimer st;

	this_thread::sleep_for(chrono::milliseconds(2500));
	cout << "ID потока = " << this_thread::get_id() << " ======================Sum start" << endl;
	this_thread::sleep_for(chrono::milliseconds(5500));
	cout << "ID потока = " << this_thread::get_id() << " ======================Sum stop" << endl;
	return a + b;
}

void Times()// команда консоли : -ti
{
	//переменная со значением времени начала выполнения программы
	//auto start = chrono::high_resolution_clock::now();
	
	//используем класс для измерения времени
	SimpleTimer st;

	int resSumTest;
	MyTestThread mt;
	//передача в поток void метода класса
	thread tcd(&MyTestThread::DoWork, mt);

	//передача в поток void метода класса с параметрами
	thread tcd2(&MyTestThread::DoWork2, mt, 5);

	//передача в поток метода класса с возвращаемым значением
	thread tcs([&]()
		{
			resSumTest = mt.Sum(2, 5);
		});

	int result;
	thread t([&result]() { result = Sums(2, 5); });

	//эмуляция основной задачи
	for (size_t i = 0; i < 15; i++)
	{
		cout << "ID потока = " << this_thread::get_id() << " main " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	t.join();
	tcd.join();
	tcd2.join();
	tcs.join();
	cout << "Sum Result = " << result << endl;
	cout << "Sum Test Result = " << resSumTest << endl;

	/*переменная со значением времени конца выполнения программы
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Duration " << duration.count() << "s" << endl;*/
}