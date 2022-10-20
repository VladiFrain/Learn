#include "header.h"
#include <Windows.h>//чтобы решить проблему с русской кодировкой(only windows)
using namespace std;
//работа с файлами(запись, чтение)

void FilesWR()//консольная команда : -f
{
	//пример записи файла ofstream
	//название файла для записи
	string pathOut = "myFile.txt";
	ofstream fout;//объект для записи файлов
	//открываем файл, если его нет он создаётся автоматически рядом с файлом программы(стандартный вывод строковый)
	fout.open(pathOut, ofstream::app);//если не указывать 2 параметр и файл был уже создан, то все данные будут удалены
	//проверяем смогли ли открыть файл(без обработки ошибок)
	if (!fout.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		cout << "Введите число: ";
		int dataRec;
		cin >> dataRec;
		//записываем число полученное с консоли в файл
		fout << dataRec << endl;
	}
	//необходимо по завершению работы с файлом его закрыть
	fout.close();
	
	//=============================
	//пример чтения файла ifstream
	//название файла для чтения
	string pathIn = "myFile.txt";
	ifstream fin;//объект для чтения файлов
	//включим возможность обработки exception
	fin.exceptions(ifstream::badbit | ifstream::failbit);

	//проверяем смогли ли открыть файл(с обработкой исключений)
	try
	{
		cout << "Попытка открыть файл!" << endl;
		fin.open(pathIn);
		cout << "Файл успешно открыт!" << endl;
		//посимвольное считывание данных
		char ch;
		while (fin.get(ch))//метод возвращает true или false при считывании
		{
			cout << ch;
		}
		//построчное считывание файла
		string fileStr;
		while (!fin.eof())//!(возвращает true когда настанет конец файла)
		{
			fileStr = "";
			//можно использовать оба варианта
			//fin >> fileStr;
			getline(fin, fileStr);
			cout << fileStr << endl;
		}
		fin.close();
	}
	//блок обработки исключений
	catch (const ifstream::failure &ex)
	{
		cout << "Ошибка открытия файла" << endl;
		cout << ex.what() << endl;
		cout << ex.code() << endl;
	}
	
	//===================================
	//пример чтения\записи файла fstream
	string path = "myFstreamFile.txt";
	fstream fs;
	//2 параметр отвечает за режим работы(in - для чтения, out - для записи, app - что бы не затирались старые данные)
	//через битовое или задаём работу обоих параметров
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (!fs.is_open())
	{
		cout << "Ошибка открытия файла" << endl;
	}
	else
	{
		string msg;
		int value;
		cout << "Файл открыт" << endl;
		cout << "Введите 1 для записи сообщения в файл." << endl;
		cout << "Введите 2 для считывания всех сообщений из файла." << endl;
		cin >> value;
		if (value == 1)
		{
			cout << "Введите ваше сообщение: ";
			//чтобы мможно было вводить с консоли русские буквы
			SetConsoleCP(1251);
			cin >> msg;
			fs << msg << "\n";
			//вернуть кодировку чтобы можно было выводить другие данные
			SetConsoleCP(866);//866 - стандартная кодировка
		}
		if (value == 2)
		{
			cout << "Чтение данных из файла!" << endl;
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