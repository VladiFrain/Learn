#include "header.h"
#include <stack>
#include <list>
#include <queue>
using namespace std;
//работа с библиотекой стандартных шаблонов stl(адаптеры)
void StlStack()//команда консоли: -stls
{
	//работа со stack
	stack<int> st;
	st.push(2);
	st.push(34);
	//работает быстрее
	st.emplace(9);
	//внутри по умолчению deque
	auto a = st._Get_container();
	cout << a[2] << endl;
	while (!st.empty())
	{
		//получаем значение без удаления
		cout << st.top() << endl;
		//достаёт элемент
		st.pop();
	}
	//в основе определили list
	stack<int, list<int>> stList;
	//расширение функционала до исходного контейнера
	auto b = stList._Get_container();
	//=================================
	
	//работа с queue(очередь)
	queue<int> que;
	que.push(4);
	que.emplace(3);
	que.emplace(5);
	que.emplace(23);
	que.emplace(3);
	que.emplace(4);
	que.emplace(6);
	que.emplace(7);
	cout << que.back() << endl;
	cout << que.front() << endl;
	que.pop();
	cout << que.front() << endl;
	cout << endl;
	//сортирует очередь от большего к меньшему
	priority_queue<int> pque;
	pque.push(1);
	pque.push(23);
	pque.push(223);
	pque.push(231);
	pque.push(233);
	pque.push(234);
	cout << pque.top() << endl;
	cout << pque.top() << endl;

}