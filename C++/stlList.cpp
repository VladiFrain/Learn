#include "header.h"
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
using namespace std;
//работа с библиотекой стандартных шаблонов stl
template<typename T>
void PrintList(const list<T>& list)
{
	for (const auto& i : list)
	{
		cout << i << " ";
	}
	cout << endl;
}

void StlList()//команда консоли: -stll
{
	//работа с list(двусвязный список)
	list<int> myList = {13, 15, 35, 144, 13, 13, 13};
	myList.push_back(13);
	myList.push_front(113);
	PrintList(myList);
	//сортируем лист
	myList.sort();
	PrintList(myList);
	//удаляет одинаковые последовательные
	myList.unique();
	PrintList(myList);
	//разворачивает лист
	myList.reverse();
	PrintList(myList);
	//создаём итератор
	auto it = myList.begin();
	//переключаем интератор на позицию 2
	advance(it, 3);
	myList.insert(it, 245);
	PrintList(myList);
	it++;
	//удаляем элемент
	myList.erase(it);
	PrintList(myList);
	//удаляет конкретное значение из листа
	myList.remove(144);
	PrintList(myList);
	//переписывает лист определённым значением
	myList.assign(3, 154322);
	PrintList(myList);
	list<int> myList2 = { 19, 66,2342, 23,234 };
	//копируем значения из одного листа в другой
	myList.assign(myList2.begin(), myList2.end());
	PrintList(myList);
	PrintList(myList2);
	cout << endl;
	cout << endl;
	//=========================================
	//работа с forward list(односвязный список)
	forward_list<int> fl = { 131, 94, 494 };
	fl.push_front(1);
	fl.push_front(4);
	for (auto& i : fl)
	{
		cout << i << " ";
	}
	cout << endl;
	forward_list<int>::iterator itf = fl.before_begin();
	fl.insert_after(itf, 123);
	for (auto& i : fl)
	{
		cout << i << " ";
	}
	cout << endl;
	itf++;//можно перемещаться только в одну сторону
	fl.erase_after(itf);
	for (auto& i : fl)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;
	//===========================================
	//работа с array
	array<int, 4> arr = { 1, 94, 77, 4 };
	array<int, 4> arr2 = { 1, 94, 77, 9 };
	bool result = arr < arr2;
	cout << result << endl;
	cout << arr.front() << " " << arr.back() << endl;
	arr.fill(2);
	for (int i = 0; i < arr.size(); i++)
	{
		cout << arr.at(i) << " ";
	}
	cout << endl;
	cout << endl;
	//===========================================
	//работа с deque(двусторонняя очередь)
	deque<int> dq = { 1, 9, 94 };
	//работа так же как и с другими контейнерами stl

	//===========================================
	//работа с set и multiset(бинарное дерево)
	set<int> mySet = { 2, 45, 87, 9};
	mySet.insert(5);
	mySet.insert(1);
	mySet.insert(12);
	mySet.insert(4);
	mySet.insert(-1);
	mySet.insert(-1);
	mySet.insert(-1);
	mySet.insert(-1);
	//возвращает итератор и белевое значение
	mySet.insert(-1); 

	for (auto& i : mySet)
	{
		cout << i << " ";
	}
	cout << endl;
	//поиск итератора с нужным значением
	auto its = mySet.find(4);
	//удаление определённого элемента(возвращает булевое значение)
	mySet.erase(-1);
	for (auto& i : mySet)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;
	//может хранить одинаковые значения
	multiset<int> myMultiset = { 1, 66, 16, 48, 99 };
	myMultiset.insert(5);
	myMultiset.insert(5);
	myMultiset.insert(5);
	myMultiset.insert(5);
	for (auto& i : myMultiset)
	{
		cout << i << " ";
	}
	cout << endl;
	//вернёт первый найдённый
	auto itm1 = myMultiset.lower_bound(5);
	//вернёт элемент после найденного
	auto itm2 = myMultiset.upper_bound(5);
	//возвращает диапазон
	auto a = myMultiset.equal_range(5);
	cout << endl;

	//===========================================
	//работа с map и multimap(бинарное дерево, ключ-значение)
	pair<int, string> p(1, "телефон");//пара значений
	//хранит только уникальные ключи
	map<int, string> myMap;
	//добавление значений
	myMap.emplace(3, "монитор");
	myMap.insert(p);
	myMap.insert(make_pair(2, "ноутбук"));
	myMap.emplace(22, "клавиатура");
	myMap.emplace(22, "не будет добавлено");
	for (auto& i : myMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	//поиск значения
	auto itm = myMap.find(22);
	cout << itm->second << endl;
	cout << myMap[3] << endl;
	myMap[3] = "принтер";
	myMap[4] = "монитор";
	for (auto& i : myMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	myMap.erase(2);
	for (auto& i : myMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
	//может хранить одинаковые ключи
	multimap<int, string> myMultiMap;
	myMultiMap.emplace(1, "Ноутбук");
	myMultiMap.emplace(1, "Мышка");
	myMultiMap.emplace(1, "Колонка");
	for (auto& i : myMultiMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
}