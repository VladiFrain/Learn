#include "header.h"
using namespace std;
//������������� ������������

class Car
{
public:
	Car()
	{
		cout << "������ ����������� Car" << endl;
	}
	~Car()
	{
		cout << "������ ���������� Car" << endl;
	}
	string str = "���� ������ ������";
	int maxSpeed = 100;
	void Drive()
	{
		cout << "� ���!" << endl;
	}
};

class Airplain
{
public:
	Airplain()
	{
		cout << "������ ����������� Airplain" << endl;
	}
	~Airplain()
	{
		cout << "������ ���������� Airplain" << endl;
	}
	string str = "���� ������ �������";
	void Flu()
	{
		cout << "� ����!" << endl;
	}
};
//������� ������������ ���������� ����� �������, ����������� ���������� � �������� ������� ������� � ������������ �����������
class FlyingCar : public Car, public Airplain 
{
public:
	FlyingCar()
	{
		cout << "������ ����������� FlyingCar" << endl;
	}
	~FlyingCar()
	{
		cout << "������ ���������� FlyingCar" << endl;
	}
};

void MultiInheritance()//���������� �������: -c m
{
	Car car;
	car.Drive();

	cout << endl;

	Airplain airplain;
	airplain.Flu();

	cout << endl;
	//����� ������������ ��� ������ �������������� �� ������� �������
	FlyingCar flyingCar;

	cout << endl;

	flyingCar.Drive();
	flyingCar.Flu();
	//��� �� ����� ������������ ���� ������� �������
	flyingCar.maxSpeed;
	//�� ���� ��� ���������� ��������� ���������� ��������� ���� ������ ������ ���� ������������
	cout << flyingCar.::Car::str << endl;
	//��� ��������� � ����
	cout << ((Airplain)flyingCar).str << endl;
	//��� �� ����� ���������� �� ������ �������� ������
	Car* tempCar = &flyingCar;
	tempCar->str;

	cout << endl;
}