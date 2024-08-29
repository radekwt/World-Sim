#include <iostream>
#include "Swiat.h"
using namespace std;

int main()
{
	cout << "Radoslaw Wojt 184468" << endl;
	Swiat s(20, 20);
	s.generateRandomWorld();
	while (!s.czyKoniecGry()) {
		s.GenerujSwiat();
		s.moveTheWorld();
	}
	return 0;
}