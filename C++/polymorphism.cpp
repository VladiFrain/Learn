#include "header.h"
using namespace std;
//полиморфизм
//создаём абстрактный класс
class Weapon abstract
{
public:
	//создаём виртуальный метод
	virtual void Shoot() = 0;//=0 - указываем что метод чисто виртуальный
	//можно определять обычные методы(будет у всех наследников)
	void Test()
	{
		cout << "Test" << endl;
	}
	virtual ~Weapon() = 0;//чисто виртуальный деструктор
};

Weapon::~Weapon() {};//необходимо пустое внешнее определение чисто виртуального деструктора

class Gun : public Weapon
{
public:
	//переопределяем виртуальный метод
	void Shoot() override
	{
		cout << "BANG!" << endl;
	}
};

class TestGun : public Gun
{
	void Shoot() override
	{
		::Gun::Shoot();//если нам не надо переопределять базовый метод или он нам нужен в классе наследнике
	}
};

class SubmachineGun : public Gun
{
public:
	//переопределяем виртуальный метод
	void Shoot() override
	{
		cout << "BANG! BANG! BANG!" << endl;
	}
};

class Bazooka : public Weapon
{
public:
	//переопределяем виртуальный метод
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
	void Shoot(Weapon *weapon) //используем указатель на базовый класс
	{
		weapon->Shoot();
	}
};

void Polymorphism()//консольная команда: -c p
{
	Player player;
	Gun gun;
	SubmachineGun machinegun;
	Bazooka bazooka;
	Knife knife;
	knife.Test();//можно использовать обычный метод определенный в абстрактном классе
	TestGun tGun;
	//можно использовать ссылку на любой объект классов наследников и будут использованы их переопределённые методы
	player.Shoot(&gun);
	player.Shoot(&machinegun);
	player.Shoot(&bazooka);
	player.Shoot(&knife);
	player.Shoot(&tGun);
}