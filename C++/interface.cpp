#include "header.h"
using namespace std;
//интерфейс - абстрактный класс у которого все методы чисто виртуальные

class IBicycle
{
public:
	void virtual TwistTheWheel() = 0;
	void virtual Ride() = 0;
};

class Rider
{
public:
	void RideOn(IBicycle &bicycle)
	{
		cout << "Крутим руль" << endl;
		bicycle.TwistTheWheel();
		cout << "Поехали" << endl;
		bicycle.Ride();
	}
};

class SimpleBicycle : public IBicycle //реализуем интерфейс
{
	void TwistTheWheel() override
	{
		cout << "Метод TwistTheWheel у SimpleBicycle" << endl;
	}

	void Ride() override
	{
		cout << "Метод Ride у SimpleBicycle" << endl;
	}

};

class SportBicycle : public IBicycle
{
	void TwistTheWheel() override
	{
		cout << "Метод TwistTheWheel у SportBicycle" << endl;
	}

	void Ride() override
	{
		cout << "Метод Ride у SportBicycle" << endl;
	}
};

void Interface()//консольная команда: -c in
{
	Rider rider;
	SimpleBicycle simpleBicycle;
	SportBicycle sportBycicle;
	rider.RideOn(simpleBicycle);
	cout << endl;
	rider.RideOn(sportBycicle);
}