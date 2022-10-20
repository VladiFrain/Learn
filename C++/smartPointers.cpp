#include "header.h"
using namespace std;
//умные указатели
//пример smart pointer
template<typename T>
class SmartPointer
{
public:
	SmartPointer(T *ptr)
	{
		this->ptr = ptr;
		//cout << "Constructor" << endl;//для отслеживания работы
	}

	~SmartPointer()
	{
		delete ptr;
		//cout << "Destructor" << endl;//для отслеживания работы
	}
	//перегрузка оператора *
	T &operator * ()
	{
		return *ptr;
	}

	

private:
	T *ptr;
};

void SmartPointers()//команда консоли: -s
{
	//обычный указатель создаёт место в куче
	int *ptr1 = new int(5);
	int *ptr2 = new int(15);
	cout << *ptr1 << endl;
	//необходимо освобождать память
	delete ptr1;
	delete ptr2;
	cout << endl;
	//======================================
	
	//умный указатель - нет необходимости освобождать память
	SmartPointer<int> spointer = new int(5);
	*spointer = 12356;
	cout << *spointer << endl;
	cout << endl;
	//SmartPointer<int> sp = spointer; - будет exception

	//auto pointer - может владеть только один объект данными
	auto_ptr<int> ap1(new int(105));
	auto_ptr<int> ap2(ap1);//ap1 - потеряет данные
	//cout << *ap1 << endl; - exception
	cout << *ap2 << endl;
	cout << endl;

	//unique_ptr - может владеть только один объект данными
	unique_ptr<int> up1(new int(305));
	//unique_ptr<int> up2(up1); - нельзя передавать один ptr другому
	unique_ptr<int> up2 = move(up1);//up1 - потеряет данные
	//cout << *up1 << endl; - exception
	cout << *up2 << endl;
	up1.swap(up2);//up2 - потеряет данные
	cout << *up1 << endl;
	int *temp = up1.get();//получим указатель
	cout << *temp << endl;
	//unique_ptr<int> up3(ptr1); - exception
	//up3.reset();//затирает данные в ptr
	//unique_ptr<int> up4(ptr2); - exception
	//up4.release();//забывает указатель на данные
	cout << endl;

	//shared_ptr - могут между собой владеть одними и теми же данными
	shared_ptr<int> sp1(new int(3));
	shared_ptr<int> sp2(sp1);
	cout << sp1 << " " << sp2 << endl;
	cout << *sp1 << " " << *sp2 << endl;
	cout << endl;

	//работа умных указателей с динамическим массивом
	int size;
	cout << "Укажите сколько будет элементов в массиве: ";
	cin >> size;
	shared_ptr<int[]> ptr(new int[size]);//автоматически будет освобождена память
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 100;
		cout << ptr[i] << endl;
	}
}