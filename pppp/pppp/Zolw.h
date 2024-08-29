#pragma once
#include "Zwierze.h"
#define ZOLW_SZYBKOSC 1
#define ZOLW_SILA 2
#define ZOLW_INICJATYWA 1
#define ZOLW_SYMBOL 'Z'
class Zolw : public Zwierze
{
private:
	bool czyZwierze = true;
public:
	Zolw();
	Zolw(Swiat * swiat,Punkt position);
	char getSymbol() override;
	int ruchNaWolnePole(int x, int deltaX, int y, int deltaY) override;
	int obronaPrzedOrganizmem(Organizm* organizmAtakujacy) override;
	string organizmToString() override;
};

