#include "header.h"
#include <vector>

#define DEBUG
#define FOO(x,y) ((x)*(y))
//���������� ����������
typedef std::vector<int> int_vector;


//������ ������ define

void IfDef()//���������� �������: -d
{
#ifdef DEBUG
	std::cout << "debug on" << std::endl;
#else
	cout << "debug off" << endl;
#endif // DEBUG

	std::cout << FOO(5, 6) << std::endl;

	std::vector<int> myVector;
	//����� ��������� ����� ���������
	int_vector myVector2;
}