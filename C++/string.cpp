#include "header.h"

using namespace std;

//длина строки
int strLength(const char* str) {
	int counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return counter;
}

class MyStr
{
public:
	//конструктор без параметров
	MyStr()
	{
		str = nullptr;
		length = 0;
	}
	//конструктор для записи переданой строки
	MyStr(const char *str)
	{
		length = strLength(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}
	//деструктор
	~MyStr()
	{
		delete[] this->str;
	}
	//конструктор копирования
	MyStr(const MyStr &other)
	{
		length = strLength(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}
	//конструктор переноса
	MyStr(MyStr &&other)
	{
		this->length = other.length;
		this->str = other.str;
		other.str = nullptr;
	}
	//перегруженный оператор присваивания
	MyStr &operator = (const MyStr &other)
	{
		if (this->str != nullptr)
		{
			delete[] this->str;
		}

		length = strLength(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}
	//перегруженный оператор сложения
	MyStr operator + (const MyStr &other)
	{
		MyStr newStr;
		int thisLength = strLength(this->str);
		int otherLength = strLength(other.str);
		newStr.length = thisLength + otherLength;
		newStr.str = new char[thisLength + otherLength + 1];

		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++, i++)
		{
			newStr.str[i] = other.str[j];
		}
		newStr.str[newStr.length] = '\0';

		return newStr;
	}
	//вывод строки на консоль
	void Print()
	{
		cout << str << endl;
	}
	//длина строки
	int Length()
	{
		return length;
	}
	//перегрузка оператора равенства
	bool operator ==(const MyStr &other)
	{
		if (this->length != other.length)
		{
			return false;
		}
		for (int i = 0; i < length; i++)//без разницы какой length использовать(мы находимся в классе)
		{
			if (this->str[i] != other.str[i])
			{
				return false;
			}
		}
		return true;
	}
	//перегрузка оператора неравенства
	bool operator !=(const MyStr &other)
	{
		return !(this->operator==(other));
	}
	//перегрузка оператора[]
	char &operator [](int index)
	{
		return this->str[index];
	}

private:
	//указатель на масив char, хранит символы которые мы передали в наш объект
	char *str;
	//длинна строки
	int length;
};
//для передачи в метод main через argStart
void MyString() //команда консоли: -ms
{
	cout << "Проверка самодельного String" << endl;
	MyStr str;
	str = "Hello";

	MyStr str2("World");

	MyStr str3;
	str3 = str + str2;

	str3.Print();

	cout << str.Length() << endl;
	cout << str2.Length() << endl;
	cout << str3.Length() << endl;
	
	bool equal = str != str2;
	cout << equal << endl;

	cout << str[1] << endl;
	str[0] = 'Q';
	str.Print();
}