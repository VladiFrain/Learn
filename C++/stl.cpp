#include "header.h"
#include <vector>
using namespace std;
//работа с библиотекой стандартных шаблонов stl

void Stl()//команда консоли: -stl
{
	//работа с vector
	cout << "работа с vector" << endl;
	vector<int> myVector1 = {0, 484, 88, 99};
	//создаём вектор длинной 20 и заполняем все ячейки числом 34(если не указать заполниться 0)
	vector<int> myVector2(20, 34);

	cout << myVector2.size() << endl;
	for (int i = 0; i < myVector2.size(); i++)
	{
		cout << myVector2[i] << " ";
	}
	cout << endl;
	//меняем длинну vector
	myVector2.resize(25);
	cout << myVector2.size() << endl;
	//проверка на пустой vector
	cout << myVector2.empty() << endl;
	myVector1.reserve(100);//указываем полную длинну vector
	myVector1.push_back(2);
	myVector1.push_back(44);
	myVector1.push_back(77);
	myVector1[0] = 1000;
	for (int i = 0; i < myVector1.size(); i++)
	{
		cout << myVector1[i] << endl;
	}
	cout << endl;
	try
	{
		//функция at выбрасывает исключение(работает медленнее [])
		cout << myVector1.at(4) << endl;
	}
	catch (const std::out_of_range& ex)
	{

		cout << ex.what() << endl;
	}
	cout << endl;
	//проверка полной длинны vector
	cout << myVector1.capacity() << endl;
	//удаляет не используемые ячейки vector
	myVector1.shrink_to_fit();
	cout << myVector1.capacity() << endl;
	cout << myVector1.size() << endl;
	myVector1.pop_back();
	cout << myVector1.size() << endl;
	myVector1.clear();
	cout << myVector1.size() << endl;
	cout << endl;
	vector<int> myVector3= { 1, 9, 44, 422, 676, 78 };
	vector<int>::iterator it2 = myVector3.begin();
	//устанавливаем в 14 элемент число 999 через итератор
	advance(it2,4);
	myVector3.insert(it2, 999);
	for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++)
	{
		cout << *i << " ";
	}
	//используем erase
	vector<int>::iterator itErase = myVector3.begin();
	//удаляем 3 элемента с 0 по 2 в коллекции
	myVector3.erase(itErase, itErase+3);
	for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << endl;
	//=====================================

	//работа с итераторами
	cout << "работа с итераторами" << endl;
	vector<int> myVector = { 1, 9, 44, 422, 676, 78 };
	//создаём итератор
	vector<int>::iterator it;
	//записываем начало vectora в итератор
	it = myVector.begin();
	cout << *it << endl;
	//смещаем итератор вправо на 2 элемента
	it+=2;
	//получаем данные из ячейки 2
	cout << *it << endl;
	it--;
	//переписываем данные в ячейке 1
	*it = 1000;
	cout << *it << endl;
	cout << endl;
	//выводим данные через констатный итератор, чтобы нельзя было менять данные
	for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	//вывод данных с конца
	for (vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++)
	{

		cout << *i << " ";
	}
	cout << endl;
	//если итератор не поддерживает синтаксис *(it+3)
	advance(it, 3);
	cout << *it << endl;
}