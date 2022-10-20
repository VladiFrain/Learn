#include "header.h"

using namespace std;
//���������� �������� ����������� � ������������� ������� �� �� ������������� � ������� ������ Human
//������ �������������� ������(��������� ������������)
class Apple;
//������ �������������� ������(��������� ������������)
class Pear;
//������ ���������(����� ��������� ���������� ������ � ������ �������)
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
		//���������� ����������� ����������
		Count++;
		id = Count;
	}
	string name;
	//������������� ����� - ����� ������� � ����� ������ Apple(���������� ��� ������)
	void TakeApple(Apple& apple);
	//������� ����� - �� ����� ������� � ����� ������ Apple
	void EatApple(Apple& apple)
	{

	}
	//��� ��� ����� ������������ ����� ������ � ��������� ����� ������ Pear ��� ������
	void TakePear(Pear& pear);
	void EatPear(Pear& pear)
	{

	}
	//�������� ��������� ���������� ���������� �������� ������
	static int GetCount()
	{
		return Count;
	}

	int GetId()
	{
		return id;
	}
	//������������� ������ �� ������ Cap
	void InspectTheCap()
	{
		cout << "��� ����� " << cap.GetColor() << " �����." << endl;
	}
private:
	int id;
	//������ ��������� ����������� ���������� ��� �������� ���������� �������� ������
	static int Count;
	//�������� ������� Cap
	Cap cap;
};
//�������������� ����������� ����������(����� ������ ��� ������)
int Human::Count = 0;

class Apple
{
public:
	Apple(int weight, string color)
	{
		this->weight = weight;
		this->color = color;
	}
	//���������� ������������ ������
	static void ChangeColor(Apple &apple, string color)
	{
		apple.color = color;
	}
	//���������� �� ������������ ������
	void ChangeColorNoStatic( string color)
	{
		this->color = color;
	}
	//���������� ��������������� ������
	friend void Human::TakeApple(Apple &apple);

private:
	int weight;
	string color;
};

//������������� �����(�������� ��� ������, ��� ��� ���������� ����� � ���������� Apple)
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
	//���������� ��������������� ������
	friend Human;
};

//����� �������������� ������
void Human::TakePear(Pear& pear)
{
	cout << "TakeApple " << pear.weight << " " << pear.color << endl;
}

void Friends() //������� �������: -c b
{
	Apple apple(150, "Red");
	Pear pear(90, "Green");
	Human human;

	//������������� ������������� �������
	human.TakeApple(apple);
	human.TakePear(pear);
	//�������� �������� ��� �������� Count
	Human human2;
	Human human3;
	Human human4;
	Human human5;
	Human human6;
	Human human7;
	Human human8;
	Human human9;
	//��������� ������� �������� ����� ������ ������
	cout << human.GetCount() << endl;
	//��������� ������� �������� ��� ���������� ������� ������
	cout << Human::GetCount() << endl; 
	//������������� ������������ ������
	Apple::ChangeColor(apple, "green");
	//������������� �� ������������ ������
	apple.ChangeColorNoStatic("Red");
	//������ ���������
	human.InspectTheCap();
}