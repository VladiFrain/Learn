#include "header.h"
using namespace std;
//пример наследования(динамический деструктор)
//структуры struct - отличие от class все поля и методы по умолчанию public

class Person
{
public:
	//оставлен чтобы не усложнять логику наследования
	Person()
	{
		this->name = "NoName";
		this->age = 0;
		this->weight = 0;
	}
	//делегирующие конструкторы
	Person(string name)
	{
		this->name = name;
		this->age = 0;
		this->weight = 0;
	}

	Person(string name, int age) : Person(name)//передает name в конструктор с одним параметром
	{
		this->age = age;
	}

	Person(string name, int age, int weight) : Person(name, age)//передает name и age в конструктор с двумя параметрами
	{
		this->weight = weight;
	}

	void SetName(string name)
	{
		this->name = name;
	}

private:
	string name;
	int age;
	int weight;
};

class Student : public Person
{
public:
	string group;
	void Learn()
	{
		cout << "Я учусь!" << endl;
	}
};

class ExtramuralStudent : public Student
{
public:
	//скрывает метод базового класса
	void Learn()
	{
		cout << "Я бываю в университете реже обычного студента!" << endl;
	}
};

class Professor : public Person
{
public:
	string subject;
};

//пример работы public private protected при наследовании
class A
{
public:
	A()
	{
		cout << "Вызвался конструктор класса А" << endl;
		cout << "Выделена динамическая память объекта класса А" << endl;//для примера как работает виртуальный деструктор
	}
	A(string msg)
	{
		this->msgTwo = msg;
		cout << "Вызвался конструктор класса А с сообщением: " << this->msgTwo << endl;
		cout << "Выделена динамическая память объекта класса А" << endl;//для примера как работает виртуальный деструктор
	}
	virtual ~A()//чтобы в любом случае были вызваны все деструкторы классов наследников
	{
		cout << "Вызвался деструктор класса А" << endl;
		cout << "Освобождена динамическая память объекта класса А" << endl;//для примера как работает виртуальный деструктор
	}

	void PrintMsgTwo()
	{
		cout << msgTwo << endl;
	}

	string msgOne = "One";
private:
	string msgTwo = "Two";
protected://может использоваться в классах наследниках
	string msgThree = "Three";
};

class B : public A //доступ к полям и методам не меняется, при private все поля и методы становяться private, protected превращает public в protected
{
public:
	//вызывает конструктор базового класса с 1 параметром
	B() : A("новое сообщение")
	{
		cout << "Вызвался конструктор класса B" << endl;
		cout << "Выделена динамическая память объекта класса B" << endl;//для примера как работает виртуальный деструктор
	}
	~B() override//необходимо переопределять деструктор чтобы избежать утечек памяти
	{
		cout << "Вызвался деструктор класса B" << endl;
		cout << "Освобождена динамическая память объекта класса B" << endl;//для примера как работает виртуальный деструктор
	}
	void PrintMsg()
	{
		cout << msgOne << endl;
		//cout << msgTwo << endl; - нельзя так как поле private
		cout << msgThree << endl;
	}
};

class C : public B
{
public:
	//вызывает конструктор по умолчанию базового класса
	C()
	{
		cout << "Вызвался конструктор класса C" << endl;
		cout << "Выделена динамическая память объекта класса C" << endl;//для примера как работает виртуальный деструктор
	}
	~C() override//необходимо переопределять деструктор чтобы избежать утечек памяти
	{
		cout << "Вызвался деструктор класса C" << endl;
		cout << "Освобождена динамическая память объекта класса C" << endl;//для примера как работает виртуальный деструктор
	}
};

void Inheritance() //консольная команда: -c i
{
	Student st;
	st.SetName("Сти");
	st.Learn();
	ExtramuralStudent extraSt;
	extraSt.Learn();
	Professor pr;

	cout << endl;

	A aa;
	cout << endl;
	A ab("Сообщение");
	cout << endl;
	B bb;
	cout << endl;
	C cc;

	cout << endl;

	A *bptr = new B;//компилятор будет думать что указатель на объект класса А содержит объект класса А и
	delete bptr;//без переопределения деструктора будет вызван только деструктор базового класса

	cout << endl;

	bb.msgOne;//остальные поля недоступны вне класса
	bb.PrintMsg();

	Person pes("Пёс", 12, 120);//используются все делегирующие конструкторы
}