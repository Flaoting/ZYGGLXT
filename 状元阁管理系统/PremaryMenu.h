#ifndef  PREMENU_H_
#define PREMENU_H_

#include "Menu.h"

#include <iostream>
using namespace std;

class PremaryMenu :public Menu
{
public:
	PremaryMenu(){}
	void display();
	~PremaryMenu() { cout << "������PremaryMenu������������" << endl; };
};
#endif // ! PREMENU_H_

