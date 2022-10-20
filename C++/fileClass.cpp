#include "header.h"
using namespace std;
//������\������ ������� ������ � ����

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
	//��������� ������������� ������� ����� �� ���� ������� � ��������
	friend ostream& operator <<(ostream& os, const Point3D& point3D);
	friend istream& operator >>(istream& is, Point3D& point3D);
};
//�������������� �������� << ��� ������ ������ ������� � ����
ostream &operator <<(ostream &os, const Point3D &point3D)
{
	os << point3D.x << " " << point3D.y << " " << point3D.z;
 	return os;
}
//�������������� �������� >> ��� ������ ������ ������� �� �����
istream& operator >>(istream& is, Point3D& point3D)
{
	is >> point3D.x >> point3D.y >> point3D.z;
	return is;
}

void FilesClass()//���������� ������� : -c f
{
	string path = "myClassFile.txt";

	//������ ������� � ����

	Point3D point3D(222, 222, 222);
	ofstream fout;
	fout.open(path, ofstream::app);

	if (!fout.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		//�� �������� ������(��� ������ ���� �������� ����� � ���� char), ������ ���������� ����� ������
		fout.write((char*)&point3D, sizeof(Point3D));
		//�� �������� ������ ��� ������ ���������������� ��������� <<
		fout << point3D << "\n";
		cout << point3D << "\n";
	}
	fout.close();

	//������ ������� �� �����
	ifstream fin;
	fin.open(path);
	if (!fin.is_open())
	{
		cout << "������ �������� �����!" << endl;
	}
	else
	{
		cout << "���� ������!" << endl;
		//������ ��� ���������� ������
		Point3D pnt;
		//�� �������� ������(��� ������ ���� �������� ����� � ���� char), ������ ���������� ����� ������
		while (fin.read((char*)&pnt, sizeof(Point3D)))//����� ���������� true ���� ���� ��� ������
		{
			pnt.Print();
		}
		//�� �������� ������ ��� ������ ���������������� ��������� >>
		while (true)
		{
			fin >> pnt;
			//��� ���������� ����� ����� ������� true � ������ �� �����
			if (fin.eof())
			{
				break;
			}
			cout << pnt << endl;
		}
	}
	fin.close();
}