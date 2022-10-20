#include "header.h"
#include <vector>

#define DEBUG
#define FOO(x,y) ((x)*(y))
//объявление псевдонима
typedef std::vector<int> int_vector;


//пример работы define

void IfDef()//консольная команда: -d
{
#ifdef DEBUG
	std::cout << "debug on" << std::endl;
#else
	cout << "debug off" << endl;
#endif // DEBUG

	std::cout << FOO(5, 6) << std::endl;

	std::vector<int> myVector;
	//можно создавать через псевдоним
	int_vector myVector2;
}