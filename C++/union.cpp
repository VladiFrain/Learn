#include "header.h"
using namespace std;
//������ � union(�������� ������ ������ � ����� �����)

union MyUnion
{
	short int a;
	int b;
	float c;
};

void Union()// ������� ������� : -u
{
	MyUnion myUn;
	//������ ��� ������ ����� ������������
	myUn.a = 5;
	myUn.b = 40000;
	myUn.c = 43.54;
}