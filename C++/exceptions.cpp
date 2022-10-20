#include "header.h"
using namespace std;
//обработка исключений try catch

class MyException : public exception
{
public:
	MyException(const char *msg, int dataState) : exception(msg)
	{
		this->dataState = dataState;
	}
	int GetDataState()
	{
		return dataState;
	}
private:
	int dataState;
};
//метод в котором бросаем исключения
void TestExceptions(int value)
{
	if (value < 0)
	{
		throw value;//бросаем ошибку с типом int
	}
	if (value == 0)
	{
		throw "Число равно 0!!!";//бросаем ошибку с типом char
	}
	if (value > 1000)
	{
		throw exception("Число больше 1000!");//бросаем ошибку используя класс exception
	}
	if (value == 50)
	{
		throw 82.2;//бросаем необрабатываемое исключение
	}
	if (value == 1)
	{
		throw MyException("Число = 1", value);//бросаем ошибку используя свой класс exception
	}

	cout << "Переменная = " << value << endl;
}

void Exceptions()//консольная команда: -e
{
	try
	{
		
		//будет поймано только первое исключение
		TestExceptions(1);
		//всё что ниже до конца блока try выполняться не будет
		TestExceptions(-50);
		TestExceptions(0);
		TestExceptions(1050);
		TestExceptions(50);
	}
	//обрабатываем ошибки с типом int
	catch (const int ex)
	{
		cout << "Блок 1 " << "Мы поймали " << ex << endl;
	}
	//обрабатываем ошибки с типом char
	catch (const char *ex)
	{
		cout << "Блок 2 " << ex << endl;
	}
	//обрабатываем ошибки используя свой класс exception
	catch (const MyException &ex)
	{
		cout << "Блок 3 " << ex.what() << endl;
	}
	//обрабатываем ошибки используя класс exception
	catch (const exception &ex)
	{
		cout << "Блок 4 " << ex.what() << endl;
	}
	//ловим все возможные исключения
	//ставиться самым последним, иначе будет отлавливать все исключения
	catch (...)
	{
		cout << "Блок 5 " << "Что-то пошло не так!" << endl;
	}
}