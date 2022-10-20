#include "header.h"
#include <algorithm>
#include <vector>
#include <list>
#include <numeric>
using namespace std;
//���������� �������: -stla
//������ � ����������� ����������� ���������� stl

//��������(�������������� ������)
class MyFunctor
{
public:
	//���������� ��������� ()
	int operator () (int a, int b)
	{
		cout << "� ������� " << count << endl;
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
		cout << "����� ������ ����� = " << evenSum << endl;
	}

	void ShowEvenCount()
	{
		cout << "���������� ������ ����� = " << evenCount << endl;
	}

private:
	int evenSum = 0;
	int evenCount = 0;
};

//���������
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
	//������� - ��������
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

void StlAlg()//���������� �������: -stla
{
	//������ ������������� ���������
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
	//������ ������������� ����������
	cout << GreaterThanZero(-10) << endl;
	cout << endl;

	vector<int> v = { 1,-2,-55,9,-3,8 };
	//���������� ���������� ��������� ����������������� �������� ����������
	auto res = count_if(v.begin(), v.end(), GreaterThanZero);
	cout << res << endl;
	cout << endl;

	vector<Person> people
	{
		Person("����",181),
		Person("����",30),
		Person("����",179),
		Person("����",200),
		Person("����",198),
		Person("������",181),
		Person("������",50),
		Person("����",150)
	};

	//��������� ��� ���������� ���������� ���������
	sort(people.begin(), people.end(), [](const Person& p1, const Person& p2)
		{
			return p1.name < p2.name;
		});

	//����� �� ������� �������� vector people
	for (auto i : people)
	{
		cout << "��� " << i.name << "\t����� " << i.score << endl;
	}
	cout << endl;

	//������ ���������� �������� vector people �� ������ �������� ��� ���������
	auto results = count_if(people.begin(), people.end(), people.front());
	cout << results << endl;
	cout << endl;

	vector<int> vec = { 9,4,94,6,9,3,7 };
	//������������� ������-��������� ���������� ��� ���������� �� �������� � ��������
	sort(vec.begin(), vec.end(), [](int a, int b) { return a > b; });
	for (auto i : vec)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;

	//============================================
	//find find_if find_if_not - ����� ������� ����������
	//����� ��������(���������� ���������� ���������� ���������)
	auto fRes = find(vec.begin(), vec.end(), 94);
	if (fRes != vec.end())
	{
		cout << "+" << endl;
	}

	//����� ������� �����
	auto fifRes = find_if(vec.begin(), vec.end(), [](int a)
		{
			return a % 2 == 0;
		});

	if (fifRes != vec.end())
	{
		cout << "+" << endl;
	}
	cout << endl;

	//����� ����� � people
	auto fifResPeople = find_if(people.begin(), people.end(), [](const Person& person)
		{
			return person.name == "����" && person.score == 120;
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

	//��������������� ����� �������
	auto fifnRes = find_if_not(vec.begin(), vec.end(), [](int a)
		{
			return a % 2 == 0;
		});
	cout << endl;

	//====================================
	//������ ������ ��������� � ��������
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
	//�������� ��� ��������� ���������
	copy(people.begin(), people.end(), back_inserter(resultPerson));

	vector<Person> resPerson;
	//�������� ������ �� ��� �������� � ��������
	copy_if(people.begin(), people.end(), back_inserter(resPerson), [](const Person& person)
		{
			return person.name == "����";
		});

	//===========================================
	//remove remove_if
	//��������� �� ������ �������� � ����� � ���������� �������� �� ������ �������� �������
	auto remRes = remove(vec.begin(), vec.end(), 9);
	//�������� �� ������ ���������
	vec.erase(remRes, vec.end());

	//����� �� ������������ ����������
	resultPerson.erase(remove_if(resultPerson.begin(), resultPerson.end(), [](const Person& person)
		{
			return person.name == "����";
		}));

	//������ �� �������
	string str = "����� � �����������   ���������";
	cout << str << endl;
	str.erase(remove(str.begin(), str.end(), ' '), str.end());
	cout << str << endl;
	cout << endl;

	//=============================================
	//����� ������������� ��������
	list<int> lst = { 4,7,77,-3,44,74 };

	auto itxv = max_element(vec.begin(), vec.end());
	cout << *itxv << endl;

	auto itxl = max_element(lst.begin(), lst.end());
	cout << *itxl << endl;

	auto itxa = max_element(array, array + SIZE);
	cout << *itxa << endl;
	cout << endl;

	//=============================================
	//����� ������������ ��������
	auto itmv = min_element(vec.begin(), vec.end());
	cout << *itmv << endl;
	cout << endl;

	//=============================================
	//����� ������������ � ������������� ��������
	auto itmxv = minmax_element(vec.begin(), vec.end());
	cout << *itmxv.first << " " << *itmxv.second << endl;
	cout << endl;

	//=============================================
	//���������� ����� ��������� ���������
	auto resAc = accumulate(begin(vec), end(vec), 0);
	cout << resAc << endl;
	//������� �������� ���������
	auto resAcAr = accumulate(begin(array), end(array), 0);
	cout << resAcAr << endl;
	cout << endl;

	//������������
	auto resAcCom = accumulate(begin(vec), end(vec), 1, [](int a, int b)
		{
			return a * b;//����������� ������� �������
		});
	cout << resAcCom << endl;
	cout << endl;

	//����� ������ ���������
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

	//����������� ������� � ������
	auto strRes = accumulate(next(begin(array)), end(array), to_string(v[0]), [](string a, int b)
		{
			return a + "-" + to_string(b);
		});
	cout << strRes << endl;
	cout << endl;

	//=================================
	//�������� ��� ������������������
	int newArr[] = { 10,3,4,5,7,11 };
	int newArr2[] = { 11,7,5,4,3,10 };
	//mismatch - ���������� ������ ���� �� ��������� ���������
	auto resMis = mismatch(begin(newArr), end(newArr), begin(newArr2), end(newArr2));
	if (resMis.first == end(newArr) && resMis.second == end(newArr2))
	{
		cout << "+" << endl;
	}
	else
	{
		cout << "-" << endl;
	}

	//equal - ���������� ������� ��������
	//��� ���������� ������������������ �������� � � equal � mismatch
	sort(begin(newArr), end(newArr));
	sort(begin(newArr2), end(newArr2));
	//����� ���������� ������ ��������� ������ ����
	bool resArr = equal(begin(newArr), end(newArr), begin(vec), end(vec));
	cout << resArr << endl;
	cout << endl;

	//equal � ����������
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
	//for_each - ������� ��������� �� ���������(���� �������)
	for_each(begin(array), end(array), [](int a)
		{
			cout << a << " ";
		});
	cout << endl;

	//===============================
	//unique
	int arrD[] = { 1,2,2,2,5,4,4 };
	//� ����� ��������� ������������� ��������
	auto resArrD = unique(begin(arrD), end(arrD));
	//������� ������ ������������ ��������
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
	//random_shuffle - ������������� ��������� ������� srand
	int arrRS[] = { 1,2,3,4,5 };
	random_shuffle(begin(arrRS), end(arrRS));
	for (auto& i : arrRS)
	{
		cout << i << " ";
	}
	cout << endl;
	cout << endl;

	//������ ��� ����� �� ������ �� ����
	class IAction
	{
	public:
		virtual void Action() = 0;
	};
	class CatAction : public IAction
	{
		virtual void Action() override
		{
			cout << "������ ����" << endl;
		}
	};
	class TeaAction : public IAction
	{
		virtual void Action() override
		{
			cout << "���� ���" << endl;
		}
	};
	class DogAction : public IAction
	{
		virtual void Action() override
		{
			cout << "������ ������" << endl;
		}
	};
	class SleepAction : public IAction
	{
		virtual void Action() override
		{
			cout << "����" << endl;
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