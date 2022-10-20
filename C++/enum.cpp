#include "header.h"
using namespace std;
//пример перечисляемого типа(enum)


class PC
{
public:
	//перечисление состояний PC
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

void Enum()//консольная команда: -en
{
	PC pc;
	pc.SetState(PC::PCState::ON);

	switch (pc.GetState())
	{
	case PC::PCState::OFF:
		cout << "PC выключен" << endl;
		break;
	case PC::PCState::ON:
		cout << "PC работает" << endl;
		break;
	case PC::PCState::SLEEP:
		cout << "PC спит" << endl;
		break;
	}
}