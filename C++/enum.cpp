#include "header.h"
using namespace std;
//������ �������������� ����(enum)


class PC
{
public:
	//������������ ��������� PC
	enum PCState
	{
		OFF,
		ON,
		SLEEP
	};

	PCState GetState()
	{
		return state;
	}

	void SetState(PCState state)
	{
		this->state = state;
	}

private:
	PCState state;
};

void Enum()//���������� �������: -en
{
	PC pc;
	pc.SetState(PC::PCState::ON);

	switch (pc.GetState())
	{
	case PC::PCState::OFF:
		cout << "PC ��������" << endl;
		break;
	case PC::PCState::ON:
		cout << "PC ��������" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "PC ����" << endl;
		break;
	}
}