#include "Move.h"
#include <iostream>
using std::cout;
using std::endl;

void Move::move(int d)
{
	if (d > 1 && d <= 4) {
		if (d == 1) cout << "Движеимся на Север!" << endl;
		else if (d == 2) cout << "Движеимся на Восток!" << endl;
		else if (d == 3) cout << "Движеимся на Запад!" << endl;
		else if (d == 4) cout << "Движеимся на Юг!" << endl;
	}
	
}
