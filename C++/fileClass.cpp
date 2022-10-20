#include "header.h"
using namespace std;
//чтение\запись объекта класса в файл

class Point3D
{
public:
	Point3D()
	{
		x = y = z = 0;
	}

	Point3D(int x, int y, int z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void Print()
	{
		cout << "X: " << x << "\tY: " << y << "\t Z: " << z << endl;
	}

private:
	int x;
	int y;
	int z;
	//определим дружественные функции чтобы не было проблем с доступом
	friend ostream& operator <<(ostream& os, const Point3D& point3D);
	friend istream& operator >>(istream& is, Point3D& point3D);
};
//переопределяем оператор << для вывода нашего объекта в файл
ostream &operator <<(ostream &os, const Point3D &point3D)
{
	os << point3D.x << " " << point3D.y << " " << point3D.z;
 	return os;
}
//переопределяем оператор >> для вывода нашего объекта из файла
istream& operator >>(istream& is, Point3D& point3D)
{
	is >> point3D.x >> point3D.y >> point3D.z;
	return is;
}

void FilesClass()//консольная команда : -c f
{
	string path = "myClassFile.txt";

	//запись объекта в файл

	Point3D point3D(222, 222, 222);
	ofstream fout;
	fout.open(path, ofstream::app);

	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		//по байтовая запись(для записи надо привести класс к типу char), вторым параметром нужен размер
		fout.write((char*)&point3D, sizeof(Point3D));
		//по строчная запись при помощи переопределённого оператора <<
		fout << point3D << "\n";
		cout << point3D << "\n";
	}
	fout.close();

	//чтение объекта из файла
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "Ошибка открытия файла!" << endl;
	}
	else
	{
		cout << "Файл открыт!" << endl;
		//объект для считывания данных
		Point3D pnt;
		//по байтовое чтение(для записи надо привести класс к типу char), вторым параметром нужен размер
		while (fin.read((char*)&pnt, sizeof(Point3D)))//метод возвращает true пока есть что читать
		{
			pnt.Print();
		}
		//по строчное чтение при помощи переопределённого оператора >>
		while (true)
		{
			fin >> pnt;
			//при достижении конца файла получим true и выйдем из цикла
			if (fin.eof())
			{
				break;
			}
			cout << pnt << endl;
		}
	}
	fin.close();
}