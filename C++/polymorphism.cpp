#include "header.h"
using namespace std;
//�����������
//������ ����������� �����
class Weapon abstract
{
public:
	//������ ����������� �����
	virtual void Shoot() = 0;//=0 - ��������� ��� ����� ����� �����������
	//����� ���������� ������� ������(����� � ���� �����������)
	void Test()
	{
		cout << "Test" << endl;
	}
	virtual ~Weapon() = 0;//����� ����������� ����������
};

Weapon::~Weapon() {};//���������� ������ ������� ����������� ����� ������������ �����������

class Gun : public Weapon
{
public:
	//�������������� ����������� �����
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};

class TestGun : public Gun
{
	void Shoot() override
	{
		::Gun::Shoot();//���� ��� �� ���� �������������� ������� ����� ��� �� ��� ����� � ������ ����������
	}
};

class SubmachineGun : public Gun
{
public:
	//�������������� ����������� �����
	void Shoot() override
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class Bazooka : public Weapon
{
public:
	//�������������� ����������� �����
	void Shoot() override
	{
		cout << "BADABUM" << endl;
	}
};

class Knife : public Weapon
{
public:
	void Shoot() override
	{
		cout << "VJUH" << endl;
	}
};

class Player
{
public:
	void Shoot(Weapon *weapon) //���������� ��������� �� ������� �����
	{
		weapon->Shoot();
	}
};

void Polymorphism()//���������� �������: -c p
{
	Player player;
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazooka;
	Knife knife;
	knife.Test();//����� ������������ ������� ����� ������������ � ����������� ������
	TestGun tGun;
	//����� ������������ ������ �� ����� ������ ������� ����������� � ����� ������������ �� ��������������� ������
	player.Shoot(&gun);
	player.Shoot(&machinegun);
	player.Shoot(&bazooka);
	player.Shoot(&knife);
	player.Shoot(&tGun);
}