#include "header.h"
#include <vector>
using namespace std;
//������ � ����������� ����������� �������� stl

void Stl()//������� �������: -stl
{
	//������ � vector
	cout << "������ � vector" << endl;
	vector<int> myVector1 = {0, 484, 88, 99};
	//������ ������ ������� 20 � ��������� ��� ������ ������ 34(���� �� ������� ����������� 0)
	vector<int> myVector2(20, 34);

	cout << myVector2.size() << endl;
	for (int i = 0; i < myVector2.size(); i++)
	{
		cout << myVector2[i] << " ";
	}
	cout << endl;
	//������ ������ vector
	myVector2.resize(25);
	cout << myVector2.size() << endl;
	//�������� �� ������ vector
	cout << myVector2.empty() << endl;
	myVector1.reserve(100);//��������� ������ ������ vector
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
		//������� at ����������� ����������(�������� ��������� [])
		cout << myVector1.at(4) << endl;
	}
	catch (const std::out_of_range& ex)
	{

		cout << ex.what() << endl;
	}
	cout << endl;
	//�������� ������ ������ vector
	cout << myVector1.capacity() << endl;
	//������� �� ������������ ������ vector
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
	//������������� � 14 ������� ����� 999 ����� ��������
	advance(it2,4);
	myVector3.insert(it2, 999);
	for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++)
	{
		cout << *i << " ";
	}
	//���������� erase
	vector<int>::iterator itErase = myVector3.begin();
	//������� 3 �������� � 0 �� 2 � ���������
	myVector3.erase(itErase, itErase+3);
	for (vector<int>::iterator i = myVector3.begin(); i != myVector3.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	cout << endl;
	//=====================================

	//������ � �����������
	cout << "������ � �����������" << endl;
	vector<int> myVector = { 1, 9, 44, 422, 676, 78 };
	//������ ��������
	vector<int>::iterator it;
	//���������� ������ vectora � ��������
	it = myVector.begin();
	cout << *it << endl;
	//������� �������� ������ �� 2 ��������
	it+=2;
	//�������� ������ �� ������ 2
	cout << *it << endl;
	it--;
	//������������ ������ � ������ 1
	*it = 1000;
	cout << *it << endl;
	cout << endl;
	//������� ������ ����� ���������� ��������, ����� ������ ���� ������ ������
	for (vector<int>::const_iterator i = myVector.cbegin(); i != myVector.cend(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
	//����� ������ � �����
	for (vector<int>::reverse_iterator i = myVector.rbegin(); i != myVector.rend(); i++)
	{

		cout << *i << " ";
	}
	cout << endl;
	//���� �������� �� ������������ ��������� *(it+3)
	advance(it, 3);
	cout << *it << endl;
}