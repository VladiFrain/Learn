#include "header.h"
using namespace std;
//��������� - ����������� ����� � �������� ��� ������ ����� �����������

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
		cout << "������ ����" << endl;
		bicycle.TwistTheWheel();
		cout << "�������" << endl;
		bicycle.Ride();
	}
};

class SimpleBicycle : public IBicycle //��������� ���������
{
	void TwistTheWheel() override
	{
		cout << "����� TwistTheWheel � SimpleBicycle" << endl;
	}

	void Ride() override
	{
		cout << "����� Ride � SimpleBicycle" << endl;
	}

};

class SportBicycle : public IBicycle
{
	void TwistTheWheel() override
	{
		cout << "����� TwistTheWheel � SportBicycle" << endl;
	}

	void Ride() override
	{
		cout << "����� Ride � SportBicycle" << endl;
	}
};

void Interface()//���������� �������: -c in
{
	Rider rider;
	SimpleBicycle simpleBicycle;
	SportBicycle sportBycicle;
	rider.RideOn(simpleBicycle);
	cout << endl;
	rider.RideOn(sportBycicle);
}