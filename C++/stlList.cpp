#include "header.h"
#include <list>
#include <forward_list>
#include <array>
#include <deque>
#include <set>
#include <map>
using namespace std;
//������ � ����������� ����������� �������� stl
template<typename T>
void PrintList(const list<T>& list)
{
	for (const auto& i : list)
	{
		cout << i << " ";
	}
	cout << endl;
}

void StlList()//������� �������: -stll
{
	//������ � list(���������� ������)
	list<int> myList = {13, 15, 35, 144, 13, 13, 13};
	myList.push_back(13);
	myList.push_front(113);
	PrintList(myList);
	//��������� ����
	myList.sort();
	PrintList(myList);
	//������� ���������� ����������������
	myList.unique();
	PrintList(myList);
	//������������� ����
	myList.reverse();
	PrintList(myList);
	//������ ��������
	auto it = myList.begin();
	//����������� ��������� �� ������� 2
	advance(it, 3);
	myList.insert(it, 245);
	PrintList(myList);
	it++;
	//������� �������
	myList.erase(it);
	PrintList(myList);
	//������� ���������� �������� �� �����
	myList.remove(144);
	PrintList(myList);
	//������������ ���� ����������� ���������
	myList.assign(3, 154322);
	PrintList(myList);
	list<int> myList2 = { 19, 66,2342, 23,234 };
	//�������� �������� �� ������ ����� � ������
	myList.assign(myList2.begin(), myList2.end());
	PrintList(myList);
	PrintList(myList2);
	cout << endl;
	cout << endl;
	//=========================================
	//������ � forward list(����������� ������)
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
	itf++;//����� ������������ ������ � ���� �������
	fl.erase_after(itf);
	for (auto& i : fl)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;
	//===========================================
	//������ � array
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
	//������ � deque(������������ �������)
	deque<int> dq = { 1, 9, 94 };
	//������ ��� �� ��� � � ������� ������������ stl

	//===========================================
	//������ � set � multiset(�������� ������)
	set<int> mySet = { 2, 45, 87, 9};
	mySet.insert(5);
	mySet.insert(1);
	mySet.insert(12);
	mySet.insert(4);
	mySet.insert(-1);
	mySet.insert(-1);
	mySet.insert(-1);
	mySet.insert(-1);
	//���������� �������� � ������� ��������
	mySet.insert(-1); 

	for (auto& i : mySet)
	{
		cout << i << " ";
	}
	cout << endl;
	//����� ��������� � ������ ���������
	auto its = mySet.find(4);
	//�������� ������������ ��������(���������� ������� ��������)
	mySet.erase(-1);
	for (auto& i : mySet)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;
	//����� ������� ���������� ��������
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
	//����� ������ ��������
	auto itm1 = myMultiset.lower_bound(5);
	//����� ������� ����� ����������
	auto itm2 = myMultiset.upper_bound(5);
	//���������� ��������
	auto a = myMultiset.equal_range(5);
	cout << endl;

	//===========================================
	//������ � map � multimap(�������� ������, ����-��������)
	pair<int, string> p(1, "�������");//���� ��������
	//������ ������ ���������� �����
	map<int, string> myMap;
	//���������� ��������
	myMap.emplace(3, "�������");
	myMap.insert(p);
	myMap.insert(make_pair(2, "�������"));
	myMap.emplace(22, "����������");
	myMap.emplace(22, "�� ����� ���������");
	for (auto& i : myMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	//����� ��������
	auto itm = myMap.find(22);
	cout << itm->second << endl;
	cout << myMap[3] << endl;
	myMap[3] = "�������";
	myMap[4] = "�������";
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
	//����� ������� ���������� �����
	multimap<int, string> myMultiMap;
	myMultiMap.emplace(1, "�������");
	myMultiMap.emplace(1, "�����");
	myMultiMap.emplace(1, "�������");
	for (auto& i : myMultiMap)
	{
		cout << i.first << " " << i.second << endl;
	}
	cout << endl;
}