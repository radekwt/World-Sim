#pragma once
#include "Zwierze.h"
#define LIS_SZYBKOSC 1
#define LIS_SILA 3
#define LIS_INICJATYWA 7
#define LIS_SYMBOL 'L'

class Lis : public Zwierze {
private:
	bool czyZwierze = true;
public:
	Lis(Swiat* swiat, Punkt position);
	Lis();
	char getSymbol() override;
	bool atakNaOrganizm(Organizm* organizmAtakowany) override;
	string organizmToString() override;
};