#include "header.h"
using namespace std;

//���������� ����� ��������� �������
void ArgStart(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		if (argc < 2)//���� ��� ������� ���������� �� ���� ������ ��������� �������
		{
			cout << "�� ������ ����� ������ ����������� -h" << endl;
		}

		if (!strcmp(argv[i], "-h"))//������� �� ���������� �������
		{
			cout << "��������� ������: -ms, -c(����� ����� ���� ����� ������ ��������� a, b, c, i, p, m, v, f, t, in, im), -f, -e, -en, -d, -a, -p, -s" << endl;
		}

		if (!strcmp(argv[i], "-ms"))//����������� ����� string
		{
			MyString();
		}

		if (!strcmp(argv[i], "-c"))//���� ����� � ��������
		{
			if (!strcmp(argv[i + 1], "a"))
			{
				Pointer();
			}
			else if (!strcmp(argv[i + 1], "b"))
			{
				Friends();
			}
			else if (!strcmp(argv[i + 1], "c"))
			{
				Clases();
			}
			else if (!strcmp(argv[i + 1], "i"))
			{
				Inheritance();
			}
			else if (!strcmp(argv[i + 1], "p"))
			{
				Polymorphism();
			}
			else if (!strcmp(argv[i + 1], "m"))
			{
				MultiInheritance();
			}
			else if (!strcmp(argv[i + 1], "v"))
			{
				VirtualInheritance();
			}
			else if (!strcmp(argv[i + 1], "f"))
			{
				FilesClass();
			}
			else if (!strcmp(argv[i + 1], "t"))
			{
				Template();
			}
			else if (!strcmp(argv[i + 1], "in"))
			{
				Interface();
			}
			else if (!strcmp(argv[i + 1], "im"))
			{
				Images();
			}
		}

		if (!strcmp(argv[i], "-f"))//������ � �������
		{
			FilesWR();
		}

		if (!strcmp(argv[i], "-e"))//������ � ������������
		{
			Exceptions();
		}

		if (!strcmp(argv[i], "-en"))//������ � ENUM
		{
			Enum();
		}

		if (!strcmp(argv[i], "-d"))//������ � #DEFINE
		{
			IfDef();
		}

		if (!strcmp(argv[i], "-a"))//������ � ���������
		{
			Array();
		}

		if (!strcmp(argv[i], "-p"))//�������
		{
			Source();
		}

		if (!strcmp(argv[i], "-s"))//����� ���������
		{
			SmartPointers();
		}

		if (!strcmp(argv[i], "-sl"))//����� ���������
		{
			SinglyLinkedList();
		}

		if (!strcmp(argv[i], "-stl"))//���������� stl
		{
			Stl();
		}

		if (!strcmp(argv[i], "-stll"))//���������� stl 2
		{
			StlList();
		}

		if (!strcmp(argv[i], "-stls"))//���������� stl 3
		{
			StlStack();
		}

		if (!strcmp(argv[i], "-stla"))//���������� stl 4
		{
			StlAlg();
		}

		if (!strcmp(argv[i], "-t"))//������ � ��������
		{
			Thread();
		}

		if (!strcmp(argv[i], "-mu"))//������ � ��������
		{
			Mutex();
		}

		if (!strcmp(argv[i], "-u"))//������ � union
		{
			Union();
		}

		if (!strcmp(argv[i], "-fu"))//������ � std::function
		{
			Function();
		}

		if (!strcmp(argv[i], "-ti"))//����� ���������� ������� ����
		{
			Times();
		}
	}
	std::system("pause");
}