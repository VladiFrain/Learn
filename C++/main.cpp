#include "header.h"
using namespace std;
//��������� ������� ��� ������ ����������� � ������ ������ ��� �����������(� �������� ���� �� ������ ���������� ������� DRY)

int main(int argc, char* argv[])
{
	//���������� ������� �����������
	setlocale(LC_ALL, "ru");
	//�������� ��������� �����
	srand(time(0));
	//�������� ����� ������ ������� ���������
	ArgStart(argc, argv);
	return 0;
}