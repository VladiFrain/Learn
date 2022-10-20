#include "header.h"
using namespace std;
//множественное наследование

class Car
{
public:
	Car()
	{
		cout << "¬ызван конструктор Car" << endl;
	}
	~Car()
	{
		cout << "¬ызван деструктор Car" << endl;
	}
	string str = "ѕоле класса машина";
	int maxSpeed = 100;
	void Drive()
	{
		cout << "я еду!" << endl;
	}
};

class Airplain
{
public:
	Airplain()
	{
		cout << "¬ызван конструктор Airplain" << endl;
	}
	~Airplain()
	{
		cout << "¬ызван деструктор Airplain" << endl;
	}
	string str = "ѕоле класса самолет";
	void Flu()
	{
		cout << "я лечу!" << endl;
	}
};
//базовые конструкторы вызываютс€ слева направо, деструкторы вызываютс€ в обратном пор€дке начина€ с собственного деструктора
class FlyingCar : public Car, public Airplain 
{
public:
	FlyingCar()
	{
		cout << "¬ызван конструктор FlyingCar" << endl;
	}
	~FlyingCar()
	{
		cout << "¬ызван деструктор FlyingCar" << endl;
	}
};

void MultiInheritance()//консольна€ команда: -c m
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
	//так же можно использовать пол€ базовых классов
	flyingCar.maxSpeed;
	//но если они называютс€ одинаково необходимо указывать поле какого класса надо использовать
	cout << flyingCar.::Car::str << endl;
	//или приводить к типу
	cout << ((Airplain)flyingCar).str << endl;
	//так же можно обратитьс€ по ссылке базового класса
	Car* tempCar = &flyingCar;
	tempCar->str;

	cout << endl;
}