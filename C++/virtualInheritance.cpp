#include "header.h"
using namespace std;
//виртуальное наследование(ромбовидное)

//пример без виртуализации
class Component
{
public:
	string companyName;
	Component(string companyName)
	{
		cout << "Конструктор Component" << endl;
		this->companyName = companyName;
	}
};
//У данного класса будет свой дочерний класс Component
class GPU : public Component
{
public:
	GPU(string companyName) : Component(companyName)
	{
		cout << "Конструктор GPU" << endl;
	}
};
//У данного класса будет свой дочерний класс Component
class Memory : public Component
{
public:
	Memory(string companyName) : Component(companyName)
	{
		cout << "Конструктор Memory" << endl;
	}
};
//У данного класса в древе наследования будет два базовых класса Component
class GraphicCard : public GPU, public Memory
{
public:
	GraphicCard(string GPUCompanyName, string MemoryCompanyName) : GPU(GPUCompanyName), Memory(MemoryCompanyName)
	{
		cout << "Конструктор GraphicCard" << endl;
	}
};
//конец примера без виртуализации
//===============================
//пример виртуального наследования(ромбовидного)
class Character
{
public:
	//если нет виртуального наследования то у одного персонажа возникнет проблема,
	//что в нескольких местах будут храниться очки здоровья
	int HP;
	Character()
	{
		cout << "Конструктор Character" << endl;
	}
};
//наследуется от класса Character
class Orc : public virtual Character
{
public:
	Orc()
	{
		cout << "Конструктор Orc" << endl;
	}
};
//наследуется от тогоже экземпляра класса Character что и класс Orc
class Warrior : public virtual Character
{
public:
	Warrior()
	{
		cout << "Конструктор Warrior" << endl;
	}
};
//у данного класса в древе наследования только один базовый класс Character
class OrcWarrior : public Orc, public Warrior
{
public:
	OrcWarrior()
	{
		cout << "Конструктор OrcWarrior" << endl;
	}
};

void VirtualInheritance()//консольная команда: -c v
{
	//показывает как создаётся объект с множественным наследованием без виртуализации
	GraphicCard graphicCard("NVIDIA", "SAMSUNG");
	cout << endl;
	//показывает как создаётся объект с множественным наследованием с виртуализацией
	OrcWarrior orcWarrior;
}