#include "header.h"
using namespace std;
//����� ���������
//������ smart pointer
template<typename T>
class SmartPointer
{
public:
	SmartPointer(T *ptr)
	{
		this->ptr = ptr;
		//cout << "Constructor" << endl;//��� ������������ ������
	}

	~SmartPointer()
	{
		delete ptr;
		//cout << "Destructor" << endl;//��� ������������ ������
	}
	//���������� ��������� *
	T &operator * ()
	{
		return *ptr;
	}

	

private:
	T *ptr;
};

void SmartPointers()//������� �������: -s
{
	//������� ��������� ������ ����� � ����
	int *ptr1 = new int(5);
	int *ptr2 = new int(15);
	cout << *ptr1 << endl;
	//���������� ����������� ������
	delete ptr1;
	delete ptr2;
	cout << endl;
	//======================================
	
	//����� ��������� - ��� ������������� ����������� ������
	SmartPointer<int> spointer = new int(5);
	*spointer = 12356;
	cout << *spointer << endl;
	cout << endl;
	//SmartPointer<int> sp = spointer; - ����� exception

	//auto pointer - ����� ������� ������ ���� ������ �������
	auto_ptr<int> ap1(new int(105));
	auto_ptr<int> ap2(ap1);//ap1 - �������� ������
	//cout << *ap1 << endl; - exception
	cout << *ap2 << endl;
	cout << endl;

	//unique_ptr - ����� ������� ������ ���� ������ �������
	unique_ptr<int> up1(new int(305));
	//unique_ptr<int> up2(up1); - ������ ���������� ���� ptr �������
	unique_ptr<int> up2 = move(up1);//up1 - �������� ������
	//cout << *up1 << endl; - exception
	cout << *up2 << endl;
	up1.swap(up2);//up2 - �������� ������
	cout << *up1 << endl;
	int *temp = up1.get();//������� ���������
	cout << *temp << endl;
	//unique_ptr<int> up3(ptr1); - exception
	//up3.reset();//�������� ������ � ptr
	//unique_ptr<int> up4(ptr2); - exception
	//up4.release();//�������� ��������� �� ������
	cout << endl;

	//shared_ptr - ����� ����� ����� ������� ������ � ���� �� �������
	shared_ptr<int> sp1(new int(3));
	shared_ptr<int> sp2(sp1);
	cout << sp1 << " " << sp2 << endl;
	cout << *sp1 << " " << *sp2 << endl;
	cout << endl;

	//������ ����� ���������� � ������������ ��������
	int size;
	cout << "������� ������� ����� ��������� � �������: ";
	cin >> size;
	shared_ptr<int[]> ptr(new int[size]);//������������� ����� ����������� ������
	for (int i = 0; i < size; i++)
	{
		ptr[i] = rand() % 100;
		cout << ptr[i] << endl;
	}
}