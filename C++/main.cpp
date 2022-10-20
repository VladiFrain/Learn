#include "header.h"
using namespace std;
//Некоторые функции или классы повторяются в разных файлах для наглядности(в реальном коде не должен нарушаться принцип DRY)

int main(int argc, char* argv[])
{
	//подключаем русскую локализацию
	setlocale(LC_ALL, "ru");
	//включаем рандомные числа
	srand(time(0));
	//вызываем метод выбора функций программы
	ArgStart(argc, argv);
	return 0;
}