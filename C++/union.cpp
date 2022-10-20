#include "header.h"
using namespace std;
//работа с union(хранение разных данных в одном месте)

union MyUnion
{
	short int a;
	int b;
	float c;
};

void Union()// команда консоли : -u
{
	MyUnion myUn;
	//каждый раз данные будут перезаписаны
	myUn.a = 5;
	myUn.b = 40000;
	myUn.c = 43.54;
}