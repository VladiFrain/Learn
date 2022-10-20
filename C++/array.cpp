#include "header.h"

using namespace std;

//���������� �������
void FillArray(int* const arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}
//����� �������
void ShowArray(const int* const arr, const int size) {
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << "\t";
	}
}
//���������� �������� � ����� �������
void PushArrayBack(int*& arr, int& size, const int value) {
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	newArray[size++] = value; //������� ���������� ������� ��� ������� size, � ��� �����: �������� size ����������� �� �������
	delete[] arr;
	arr = newArray;
}
//���������� �������� � ������ �������
void PushArrayFirst(int*& arr, int& size, const int value) {
	int* newArray = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newArray[i + 1] = arr[i];
	}
	newArray[0] = value;
	size++;
	delete[] arr;
	arr = newArray;
}
//�������� ������� �������� �������
void PopArrayFirst(int*& arr, int& size) {
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i + 1];
	}
	delete[] arr;
	arr = newArray;
}
//�������� ���������� �������� �������
void PopArrayBack(int*& arr, int& size) {
	size--;
	int* newArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		newArray[i] = arr[i];
	}
	delete[] arr;
	arr = newArray;
}

void Array()//���������� �������: -a
{
	cout << "������ � array" << endl;
	int size = 5;
	int* firstArray = new int[size];
	int* secondArray = new int[size];
	FillArray(firstArray, size);
	FillArray(secondArray, size);
	cout << "FirstArray -\t";
	ShowArray(firstArray, size);
	cout << endl;
	cout << "SecondArray -\t";
	ShowArray(secondArray, size);

	delete[] firstArray;
	firstArray = new int[size];
	for (int i = 0; i < size; i++)
	{
		firstArray[i] = secondArray[i];
	}
	cout << endl;
	cout << endl;
	cout << "FirstArray -\t";
	ShowArray(firstArray, size);
	cout << endl;
	cout << "SecondArray -\t";
	ShowArray(secondArray, size);
	PushArrayBack(secondArray, size, 12);
	cout << endl;
	cout << "SecondArray -\t";
	ShowArray(secondArray, size);
	PopArrayBack(secondArray, size);
	cout << endl;
	cout << "SecondArray -\t";
	ShowArray(secondArray, size);
	PushArrayFirst(secondArray, size, 124);
	cout << endl;
	cout << "SecondArray -\t";
	ShowArray(secondArray, size);
	PopArrayFirst(secondArray, size);
	cout << endl;
	cout << "SecondArray -\t";
	ShowArray(secondArray, size);

	delete[] secondArray;
	delete[] firstArray;
}