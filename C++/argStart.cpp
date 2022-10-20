#include "header.h"
using namespace std;

//управление через параметры консоли
void ArgStart(int argc, char* argv[])
{
	for (int i = 0; i < argc; i++)
	{
		if (argc < 2)//если при запуске приложения не были заданы параметры консоли
		{
			cout << "Не выбран режим работы используйте -h" << endl;
		}

		if (!strcmp(argv[i], "-h"))//справка по параметрам консоли
		{
			cout << "Доступные режимы: -ms, -c(сразу после него через пробел необходим a, b, c, i, p, m, v, f, t, in, im), -f, -e, -en, -d, -a, -p, -s" << endl;
		}

		if (!strcmp(argv[i], "-ms"))//собственный класс string
		{
			MyString();
		}

		if (!strcmp(argv[i], "-c"))//блок работ с классами
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

		if (!strcmp(argv[i], "-f"))//работа с файлами
		{
			FilesWR();
		}

		if (!strcmp(argv[i], "-e"))//работы с исключениями
		{
			Exceptions();
		}

		if (!strcmp(argv[i], "-en"))//работа с ENUM
		{
			Enum();
		}

		if (!strcmp(argv[i], "-d"))//работа с #DEFINE
		{
			IfDef();
		}

		if (!strcmp(argv[i], "-a"))//работа с массивами
		{
			Array();
		}

		if (!strcmp(argv[i], "-p"))//функции
		{
			Source();
		}

		if (!strcmp(argv[i], "-s"))//умные указатели
		{
			SmartPointers();
		}

		if (!strcmp(argv[i], "-sl"))//умные указатели
		{
			SinglyLinkedList();
		}

		if (!strcmp(argv[i], "-stl"))//библиотека stl
		{
			Stl();
		}

		if (!strcmp(argv[i], "-stll"))//библиотека stl 2
		{
			StlList();
		}

		if (!strcmp(argv[i], "-stls"))//библиотека stl 3
		{
			StlStack();
		}

		if (!strcmp(argv[i], "-stla"))//библиотека stl 4
		{
			StlAlg();
		}

		if (!strcmp(argv[i], "-t"))//работа с потоками
		{
			Thread();
		}

		if (!strcmp(argv[i], "-mu"))//работа с потоками
		{
			Mutex();
		}

		if (!strcmp(argv[i], "-u"))//работа с union
		{
			Union();
		}

		if (!strcmp(argv[i], "-fu"))//работа с std::function
		{
			Function();
		}

		if (!strcmp(argv[i], "-ti"))//время выполнения участка кода
		{
			Times();
		}
	}
	std::system("pause");
}