#include "header.h"

using namespace std;
//необходимо сообщить компил€тору о существовании классов до их использовании в методах класса Human
//пример дружественного метода(нарушение инкапсул€ции)
class Apple;
//пример дружественного класса(нарушение инкапсул€ции)
class Pear;
//пример агрегации(можно создавать экземпл€ры класса в разных классах)
class Cap
{
public:
	string GetColor()
	{
		return color;
	}
private:
	string color = "red";
};

class Human
{
public:
	Human()
	{
		//используем статическую переменную
		Count++;
		id = Count;
	}
	string name;
	//дружественный метод - имеет доступа к пол€м класса Apple(объ€вление вне класса)
	void TakeApple(Apple& apple);
	//обычный метод - не имеет доступа к пол€м класса Apple
	void EatApple(Apple& apple)
	{

	}
	//так как класс дружественен имеют доступ к приватным пол€м класса Pear оба метода
	void TakePear(Pear& pear);
	void EatPear(Pear& pear)
	{

	}
	//получаем приватную переменную количества объектов класса
	static int GetCount()
	{
		return Count;
	}

	int GetId()
	{
		return id;
	}
	//»спользование метода из класса Cap
	void InspectTheCap()
	{
		cout << "ћо€ кепка " << cap.GetColor() << " цвета." << endl;
	}
private:
	int id;
	//создаЄм приватную статическую переменную дл€ подсчЄта количества объектов класса
	static int Count;
	//создание объекта Cap
	Cap cap;
};
//инициализируем статическую переменную(можно только вне класса)
int Human::Count = 0;

class Apple
{
public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
	//объ€вление статического метода
	static void ChangeColor(Apple &apple, string color)
	{
		apple.color = color;
	}
	//объ€вление не статического метода
	void ChangeColorNoStatic( string color)
	{
		this->color = color;
	}
	//объ€вление дружественности метода
	friend void Human::TakeApple(Apple &apple);

private:
	int weight;
	string color;
};

//дружественный метод(объ€влен вне класса, так как необходимо знать о переменных Apple)
void Human::TakeApple(Apple &apple)
{
	cout << "TakeApple " << apple.weight << " " << apple.color << endl;
}

class Pear
{
public:
	Pear(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}

private:
	int weight;
	string color;
	//объ€вление дружественности класса
	friend Human;
};

//метод дружественного класса
void Human::TakePear(Pear& pear)
{
	cout << "TakeApple " << pear.weight << " " << pear.color << endl;
}

void Friends() //команда консоли: -c b
{
	Apple apple(150, "Red");
	Pear pear(90, "Green");
	Human human;

	//использование дружественных методов
	human.TakeApple(apple);
	human.TakePear(pear);
	//создание объектов дл€ проверки Count
	Human human2;
	Human human3;
	Human human4;
	Human human5;
	Human human6;
	Human human7;
	Human human8;
	Human human9;
	//посмотрим сколько объектов через объект класса
	cout << human.GetCount() << endl;
	//посмотрим сколько объектов без экземпл€ра объекта класса
	cout << Human::GetCount() << endl; 
	//использование статического метода
	Apple::ChangeColor(apple, "green");
	//использование не статического метода
	apple.ChangeColorNoStatic("Red");
	//пример агрегации
	human.InspectTheCap();
}