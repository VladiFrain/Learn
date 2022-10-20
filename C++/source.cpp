#include "header.h"
using namespace std;
//примеры разных функций

//ищем факториал
int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

//изменение данных по ссылке
void Foo(int &aRef) {
	aRef++;
}

//пример для шоу инфо
string GetDataFromBD() {
	return "BD";
}

//пример для шоу инфо
string GetDataFromWebServer() {
	return "Web";
}

//передача функции через указатель
void ShowInfo(string(*GetData)()) {
	cout << GetData() << endl;
}

void Source()//консольна программа: -p
{
	//ищем факториал 6
	factorial(6);

	//изменяем данные по ссылке
	int t = 5;
	Foo(t);
	cout << t << endl;

	//реализация передачи функции через указатель
	ShowInfo(GetDataFromBD);

	//работа с циклом for each
	int arr[] = { 5, 11,94,99,44 };
	for (auto& i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}