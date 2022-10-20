#include "header.h"
#include <Windows.h>//����� ������ �������� � ������� ����������(only windows)
using namespace std;
//������ � �������(������, ������)

void FilesWR()//���������� ������� : -f
{
	//������ ������ ����� ofstream
	//�������� ����� ��� ������
	string pathOut = "myFile.txt";
	ofstream fout;//������ ��� ������ ������
	//��������� ����, ���� ��� ��� �� �������� ������������� ����� � ������ ���������(����������� ����� ���������)
	fout.open(pathOut, ofstream::app);//���� �� ��������� 2 �������� � ���� ��� ��� ������, �� ��� ������ ����� �������
	//��������� ������ �� ������� ����(��� ��������� ������)
	if (!fout.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		cout << "������� �����: ";
		int dataRec;
		cin >> dataRec;
		//���������� ����� ���������� � ������� � ����
		fout << dataRec << endl;
	}
	//���������� �� ���������� ������ � ������ ��� �������
	fout.close();
	
	//=============================
	//������ ������ ����� ifstream
	//�������� ����� ��� ������
	string pathIn = "myFile.txt";
	ifstream fin;//������ ��� ������ ������
	//������� ����������� ��������� exception
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	//��������� ������ �� ������� ����(� ���������� ����������)
	try
	{
		cout << "������� ������� ����!" << endl;
		fin.open(pathIn);
		cout << "���� ������� ������!" << endl;
		//������������ ���������� ������
		char ch;
		while (fin.get(ch))//����� ���������� true ��� false ��� ����������
		{
			cout << ch;
		}
		//���������� ���������� �����
		string fileStr;
		while (!fin.eof())//!(���������� true ����� �������� ����� �����)
		{
			fileStr = "";
			//����� ������������ ��� ��������
			//fin >> fileStr;
			getline(fin, fileStr);
			cout << fileStr << endl;
		}
		fin.close();
	}
	//���� ��������� ����������
	catch (const ifstream::failure &ex)
	{
		cout << "������ �������� �����" << endl;
		cout << ex.what() << endl;
		cout << ex.code() << endl;
	}
	
	//===================================
	//������ ������\������ ����� fstream
	string path = "myFstreamFile.txt";
	fstream fs;
	//2 �������� �������� �� ����� ������(in - ��� ������, out - ��� ������, app - ��� �� �� ���������� ������ ������)
	//����� ������� ��� ����� ������ ����� ����������
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "������ �������� �����" << endl;
	}
	else
	{
		string msg;
		int value;
		cout << "���� ������" << endl;
		cout << "������� 1 ��� ������ ��������� � ����." << endl;
		cout << "������� 2 ��� ���������� ���� ��������� �� �����." << endl;
		cin >> value;
		if (value == 1)
		{
			cout << "������� ���� ���������: ";
			//����� ������ ���� ������� � ������� ������� �����
			SetConsoleCP(1251);
			cin >> msg;
			fs << msg << "\n";
			//������� ��������� ����� ����� ���� �������� ������ ������
			SetConsoleCP(866);//866 - ����������� ���������
		}
		if (value == 2)
		{
			cout << "������ ������ �� �����!" << endl;
			while (!fs.eof())
			{
				msg = "";
				fs >> msg;
				cout << msg << endl;
			}
		}
	}
	fs.close();
	
}