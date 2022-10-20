#include "header.h"

using namespace std;
//сеттеры и геттеры, перегрузка операторов(без динамической памяти), дружественная функция
class Point
{
public:
	Point()
	{
		x = 0;
		y = 0;
		cout << this << " constructor" << endl;
	}

	Point(int x, int y)
	{
		SetX(x);
		SetY(y);
		cout << this << " constructor" << endl;

	}

	int GetX()
	{
		return x;
	}
	void SetX(int value)
	{
		if (value > 0)
		{
			x = value;
		}
		else
		{
			cout << "Не верное значение Х, должно быть больше 0" << endl;
		}
	}

	int GetY()
	{
		return y;
	}
	void SetY(int value)
	{
		y = value;
	}

	void Print()
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}

	bool operator == (const Point& other)
	{
		return this->x == other.x && this->y == other.y;
	}

	bool operator != (const Point& other)
	{
		return !(this->x == other.x && this->y == other.y);
	}

	Point operator + (const Point &other)
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}

	Point operator - (const Point& other)
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}

	Point operator * (const Point &other)
	{
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;
		return temp;
	}

	Point operator / (const Point &other)
	{
		Point temp;
		temp.x = this->x / other.x;
		temp.y = this->y / other.y;
		return temp;
	}
	
	Point &operator ++()
	{
		this->x++;
		this->y++;
		return *this;
	}
	//постфиксная форма
	Point &operator ++(int value)
	{
		Point temp(*this);
		this->x++;
		this->y++;
		return temp;
	}

	Point& operator --()
	{
		this->x--;
		this->y--;
		return *this;
	}
	//постфиксная форма
	Point& operator --(int value)
	{
		Point temp(*this);
		this->x--;
		this->y--;
		return temp;
	}
	//определение дружественной функции
	friend void ChangeX(Point &value);

private:
	int x;
	int y;
};
//дружественная функция
void ChangeX(Point &value)
{
	value.x = -1;
}

void Pointer() //команда консоли: -c a
{
	cout << "Работа класса Point" << endl;
	Point pa(5, 1);
	Point pb(77, 12);
	Point presult = pa / pb;
	presult.Print();
	Point pc = pa++;
	pa.Print();
	pc.Print();
	ChangeX(pc);
	pc.Print();
}