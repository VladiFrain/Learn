#include "header.h"
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
using namespace std;
//консольная команда: -stla
//работа с алгоритмами стандартной библиотеки stl

//функторы(функциональный объект)
class MyFunctor
{
public:
	//перегрузка оператора ()
	int operator () (int a, int b)
	{
		cout << "Я функтор " << count << endl;
		count++;
		return a + b;
	}

private:
	int count = 0;
};

class EvenFunctor
{
public:

	void operator () (int value)
	{
		if (value % 2 == 0)
		{
			evenSum += value;
			evenCount++;
		}
	}

	void ShowEvenSum()
	{
		cout << "Сумма чётных чисел = " << evenSum << endl;
	}

	void ShowEvenCount()
	{
		cout << "Количество чётных чисел = " << evenCount << endl;
	}

private:
	int evenSum = 0;
	int evenCount = 0;
};

//предикаты
bool GreaterThanZero(int a)
{
	return a > 0;
}

class Person
{
public:
	Person(string name, double score)
	{
		this->name = name;
		this->score = score;
	}
	//функтор - предикат
	bool operator()(const Person& p)
	{
		return p.score > 180;
	}

	string name;
	double score;
};

class Points
{
public:
	Points(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int x, y;
};

void StlAlg()//консольная команда: -stla
{
	//пример использования функторов
	MyFunctor f;
	int result = f(5, 2);
	cout << endl;

	EvenFunctor ef;
	int arr[] = { 1,2,55,99,44,3,6 };
	for (auto i : arr)
	{
		ef(i);
	}
	ef.ShowEvenCount();
	ef.ShowEvenSum();
	cout << endl;

	//=================================
	//пример использования предикатов
	cout << GreaterThanZero(-10) << endl;
	cout << endl;

	vector<int> v = { 1,-2,-55,9,-3,8 };
	//записывает количество элементов удовлетворительно оценённых предикатом
	auto res = count_if(v.begin(), v.end(), GreaterThanZero);
	cout << res << endl;
	cout << endl;

	vector<Person> people
	{
		Person("Вася",181),
		Person("Петя",30),
		Person("Маша",179),
		Person("Даша",200),
		Person("Катя",198),
		Person("Андрей",181),
		Person("Сергей",50),
		Person("Иван",150)
	};

	//сортируем без перегрузки операторов сравнения
	sort(people.begin(), people.end(), [](const Person& p1, const Person& p2)
		{
			return p1.name < p2.name;
		});

	//вывод на консоль значений vector people
	for (auto i : people)
	{
		cout << "Имя " << i.name << "\tбаллы " << i.score << endl;
	}
	cout << endl;

	//запись количества значений vector people на основе проверки его предиката
	auto results = count_if(people.begin(), people.end(), people.front());
	cout << results << endl;
	cout << endl;

	vector<int> vec = { 9,4,94,6,9,3,7 };
	//использование лямбда-предиката предикатом для сортировки от большего к меньшему
	sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;

	//============================================
	//find find_if find_if_not - поиск первого совпадения
	//поиск значения(необходима перегрузка операторов сравнения)
	auto fRes = find(vec.begin(), vec.end(), 94);
	if (fRes != vec.end())
	{
		cout << "+" << endl;
	}

	//поиск чётного числа
	auto fifRes = find_if(vec.begin(), vec.end(), [](int a)
		{
			return a % 2 == 0;
		});

	if (fifRes != vec.end())
	{
		cout << "+" << endl;
	}
	cout << endl;

	//поиск имени в people
	auto fifResPeople = find_if(people.begin(), people.end(), [](const Person& person)
		{
			return person.name == "Маша" && person.score == 120;
		});

	if (fifResPeople != people.end())
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}
	cout << endl;

	//инвертированный вывод команды
	auto fifnRes = find_if_not(vec.begin(), vec.end(), [](int a)
		{
			return a % 2 == 0;
		});
	cout << endl;

	//====================================
	//работа лямбда предиката с массивом
	const int SIZE = 7;
	int array[SIZE] = { 9,4,94,6,9,3,7 };
	sort(array, array + SIZE, [](int a, int b) { return a > b; });
	for (auto i : array)
	{
		cout << i << " ";
	}
	cout << endl;

	//==========================================
	//copy copy_if
	vector<Person> resultPerson;
	//копируем всю коллекцию коллекцию
	copy(people.begin(), people.end(), back_inserter(resultPerson));

	vector<Person> resPerson;
	//копируем только то что подходит в предикат
	copy_if(people.begin(), people.end(), back_inserter(resPerson), [](const Person& person)
		{
			return person.name == "Маша";
		});

	//===========================================
	//remove remove_if
	//скидывает не нужные элементы в конец и возвращает итератор на первый ненужный элемент
	auto remRes = remove(vec.begin(), vec.end(), 9);
	//удаление не нужных элементов
	vec.erase(remRes, vec.end());

	//можно не использовать переменную
	resultPerson.erase(remove_if(resultPerson.begin(), resultPerson.end(), [](const Person& person)
		{
			return person.name == "Маша";
		}));

	//пример со строкой
	string str = "Текст с несколькими   пробелами";
	cout << str << endl;
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str << endl;
	cout << endl;

	//=============================================
	//поиск максимального элемента
	list<int> lst = { 4,7,77,-3,44,74 };

	auto itxv = max_element(vec.begin(), vec.end());
	cout << *itxv << endl;

	auto itxl = max_element(lst.begin(), lst.end());
	cout << *itxl << endl;

	auto itxa = max_element(array, array + SIZE);
	cout << *itxa << endl;
	cout << endl;

	//=============================================
	//поиск минимального элемента
	auto itmv = min_element(vec.begin(), vec.end());
	cout << *itmv << endl;
	cout << endl;

	//=============================================
	//поиск минимального и максимального элемента
	auto itmxv = minmax_element(vec.begin(), vec.end());
	cout << *itmxv.first << " " << *itmxv.second << endl;
	cout << endl;

	//=============================================
	//нахождение суммы элементов коллекции
	auto resAc = accumulate(begin(vec), end(vec), 0);
	cout << resAc << endl;
	//вариант передачи итератора
	auto resAcAr = accumulate(begin(array), end(array), 0);
	cout << resAcAr << endl;
	cout << endl;

	//произведение
	auto resAcCom = accumulate(begin(vec), end(vec), 1, [](int a, int b)
		{
			return a * b;//определение функции вручную
		});
	cout << resAcCom << endl;
	cout << endl;

	//сумма четных элементов
	auto rAcVec = accumulate(begin(vec), end(vec), 0, [](int a, int b)
		{
			if (b % 2 == 0)
			{
				return a + b;
			}
			else
			{
				return a;
			}
		});
	cout << rAcVec << endl;
	cout << endl;

	//конвертация массива в строку
	auto strRes = accumulate(next(begin(array)), end(array), to_string(v[0]), [](string a, int b)
		{
			return a + "-" + to_string(b);
		});
	cout << strRes << endl;
	cout << endl;

	//=================================
	//сравнить две последовательности
	int newArr[] = { 10,3,4,5,7,11 };
	int newArr2[] = { 11,7,5,4,3,10 };
	//mismatch - возвращает первую пару не совпавших элементов
	auto resMis = mismatch(begin(newArr), end(newArr), begin(newArr2), end(newArr2));
	if (resMis.first == end(newArr) && resMis.second == end(newArr2))
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}

	//equal - возвращает булевое значение
	//без сортировки последовательности различны и у equal и mismatch
	sort(begin(newArr), end(newArr));
	sort(begin(newArr2), end(newArr2));
	//можно сравнивать разные коллекции одного типа
	bool resArr = equal(begin(newArr), end(newArr), begin(vec), end(vec));
	cout << resArr << endl;
	cout << endl;

	//equal с предикатом
	vector<Points> arrP
	{
		Points(1,3),
		Points(4,5),
		Points(5,7),
	};
	vector<Points> arrP2
	{
		Points(1,3),
		Points(4,5),
		Points(5,7),
	};
	bool resArrP = equal(begin(arrP), end(arrP), begin(arrP2), end(arrP2), [](Points& p1, Points& p2)
		{
			return p1.x == p2.x && p1.y == p2.y;
		});
	cout << resArrP << endl;
	cout << endl;

	//===============================
	//for_each - перебор коллекции по предикату(либо функции)
	for_each(begin(array), end(array), [](int a)
		{
			cout << a << " ";
		});
	cout << endl;

	//===============================
	//unique
	int arrD[] = { 1,2,2,2,5,4,4 };
	//в конец скидывает повторающиеся элементы
	auto resArrD = unique(begin(arrD), end(arrD));
	//выведем только оригинальные элементы
	for_each(begin(arrD), resArrD, [](int a)
		{
			cout << a << " ";
		});
	cout << endl;

	//unique_copy
	int arrD2[] = { 1,2,2,2,5,4,4 };
	vector<int> vecD;
	unique_copy(begin(arrD2), end(arrD2), back_inserter(vecD));
	for_each(begin(vecD), end(vecD), [](int a)
		{
			cout << a << " ";
		});
	cout << endl;

	//=================================
	//random_shuffle - рандомизирует коллекцию требует srand
	int arrRS[] = { 1,2,3,4,5 };
	random_shuffle(begin(arrRS), end(arrRS));
	for (auto& i : arrRS)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;

	//создал тут чтобы не бегать по коду
	class IAction
	{
	public:
		virtual void Action() = 0;
	};
	class CatAction : public IAction
	{
		virtual void Action() override
		{
			cout << "Гладим кота" << endl;
		}
	};
	class TeaAction : public IAction
	{
		virtual void Action() override
		{
			cout << "Пьём чай" << endl;
		}
	};
	class DogAction : public IAction
	{
		virtual void Action() override
		{
			cout << "Гладим собаку" << endl;
		}
	};
	class SleepAction : public IAction
	{
		virtual void Action() override
		{
			cout << "Спим" << endl;
		}
	};

	IAction* arrIA[] = { 
		new CatAction(),
		new TeaAction(),
		new DogAction(),
		new SleepAction()
	};

	random_shuffle(begin(arrIA), end(arrIA));
	for (auto& el : arrIA)
	{
		el->Action();
	}
	cout << endl;

	for (size_t i = 0; i < sizeof(arrIA)/sizeof(IAction); i++)
	{
		delete arrIA[i];
	}
}