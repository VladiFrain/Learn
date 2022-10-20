#include "header.h"
#include <stack>
#include <list>
#include <queue>
using namespace std;
//������ � ����������� ����������� �������� stl(��������)
void StlStack()//������� �������: -stls
{
	//������ �� stack
	stack<int> st;
	st.push(2);
	st.push(34);
	//�������� �������
	st.emplace(9);
	//������ �� ��������� deque
	auto a = st._Get_container();
	cout << a[2] << endl;
	while (!st.empty())
	{
		//�������� �������� ��� ��������
		cout << st.top() << endl;
		//������ �������
		st.pop();
	}
	//� ������ ���������� list
	stack<int, list<int>> stList;
	//���������� ����������� �� ��������� ����������
	auto b = stList._Get_container();
	//=================================
	
	//������ � queue(�������)
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
	//��������� ������� �� �������� � ��������
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