#include "header.h"
using namespace std;
//������� ������ �������

//���� ���������
int factorial(int n) {
	if (n == 0) return 1;
	return n * factorial(n - 1);
}

//��������� ������ �� ������
void Foo(int &aRef) {
	aRef++;
}

//������ ��� ��� ����
string GetDataFromBD() {
	return "BD";
}

//������ ��� ��� ����
string GetDataFromWebServer() {
	return "Web";
}

//�������� ������� ����� ���������
void ShowInfo(string(*GetData)()) {
	cout << GetData() << endl;
}

void Source()//��������� ���������: -p
{
	//���� ��������� 6
	factorial(6);

	//�������� ������ �� ������
	int t = 5;
	Foo(t);
	cout << t << endl;

	//���������� �������� ������� ����� ���������
	ShowInfo(GetDataFromBD);

	//������ � ������ for each
	int arr[] = { 5, 11,94,99,44 };
	for (auto& i : arr)
	{
		cout << i << " ";
	}
	cout << endl;
}