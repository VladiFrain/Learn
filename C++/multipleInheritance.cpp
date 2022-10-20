#include "header.h"
using namespace std;
//множественное наследование

class Car
{
public:
	Car()
	{
		cout << "Вызван конструктор Car" << endl;
	}
	~Car()
	{
		cout << "Вызван деструктор Car" << endl;
	}
	string str = "Поле класса машина";
	int maxSpeed = 100;
	void Drive()
	{
		cout << "Я еду!" << endl;
	}
};

class Airplain
{
public:
	Airplain()
	{
		cout << "Вызван конструктор Airplain" << endl;
	}
	~Airplain()
	{
		cout << "Вызван деструктор Airplain" << endl;
	}
	string str = "Поле класса самолет";
	void Flu()
	{
		cout << "Я лечу!" << endl;
	}
};
//базовые конструкторы вызываются слева направо, деструкторы вызываются в обратном порядке начиная с собственного деструктора
class FlyingCar : public Car, public Airplain 
{
public:
	FlyingCar()
	{
		cout << "Вызван конструктор FlyingCar" << endl;
	}
	~FlyingCar()
	{
		cout << "Вызван деструктор FlyingCar" << endl;
	}
};

void MultiInheritance()//консольная команда: -c m
{
	Car car;
	car.Drive();

	cout << endl;

	Airplain airplain;
	airplain.Flu();

	cout << endl;
	//можно использовать все методы унаследованные от базовых классов
	FlyingCar flyingCar;

	cout << endl;

	flyingCar.Drive();
	flyingCar.Flu();
	//так же можно использовать поля базовых классов
	flyingCar.maxSpeed;
	//но если они называются одинаково необходимо указывать поле какого класса надо использовать
	cout << flyingCar.::Car::str << endl;
	//или приводить к типу
	cout << ((Airplain)flyingCar).str << endl;
	//так же можно обратиться по ссылке базового класса
	Car* tempCar = &flyingCar;
	tempCar->str;

	cout << endl;
}