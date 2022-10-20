#include "header.h"
#include <thread>
using namespace std;
//����� ���������� ������� ����(2 ����� thread)

//��������� ����� ��� �������� ��� ������� � ��������� �����
class MyTestThread
{
public:
	void DoWork()
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID ������ = " << this_thread::get_id() << " ======================DoWork Test Start" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID ������ = " << this_thread::get_id() << " ======================DoWork Test Stop" << endl;
	}

	void DoWork2(int a)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID ������ = " << this_thread::get_id() << " ======================DoWork2 Test Start" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "DoWork2 param =\t" << a << endl;
		cout << "ID ������ = " << this_thread::get_id() << " ======================DoWork2 Test Stop" << endl;
	}

	int Sum(int a, int b)
	{
		this_thread::sleep_for(chrono::milliseconds(2000));
		cout << "ID ������ = " << this_thread::get_id() << " ======================Sum Test start" << endl;
		this_thread::sleep_for(chrono::milliseconds(5000));
		cout << "ID ������ = " << this_thread::get_id() << " ======================Sum Test stop" << endl;
		return a + b;
	}
};

//��������� ����� ��� �������� ������� ������ ����
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

//�������� ������ ������ � ��������� ����������
int Sums(int a, int b)
{
	//���������� ����� ��� ��������� ������� �������
	SimpleTimer st;

	this_thread::sleep_for(chrono::milliseconds(2500));
	cout << "ID ������ = " << this_thread::get_id() << " ======================Sum start" << endl;
	this_thread::sleep_for(chrono::milliseconds(5500));
	cout << "ID ������ = " << this_thread::get_id() << " ======================Sum stop" << endl;
	return a + b;
}

void Times()// ������� ������� : -ti
{
	//���������� �� ��������� ������� ������ ���������� ���������
	//auto start = chrono::high_resolution_clock::now();
	
	//���������� ����� ��� ��������� �������
	SimpleTimer st;

	int resSumTest;
	MyTestThread mt;
	//�������� � ����� void ������ ������
	thread tcd(&MyTestThread::DoWork, mt);

	//�������� � ����� void ������ ������ � �����������
	thread tcd2(&MyTestThread::DoWork2, mt, 5);

	//�������� � ����� ������ ������ � ������������ ���������
	thread tcs([&]()
		{
			resSumTest = mt.Sum(2, 5);
		});

	int result;
	thread t([&result]() { result = Sums(2, 5); });

	//�������� �������� ������
	for (size_t i = 0; i < 15; i++)
	{
		cout << "ID ������ = " << this_thread::get_id() << " main " << i << endl;
		this_thread::sleep_for(chrono::milliseconds(500));
	}
	t.join();
	tcd.join();
	tcd2.join();
	tcs.join();
	cout << "Sum Result = " << result << endl;
	cout << "Sum Test Result = " << resSumTest << endl;

	/*���������� �� ��������� ������� ����� ���������� ���������
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> duration = end - start;
	cout << "Duration " << duration.count() << "s" << endl;*/
}