#pragma once
#include "Roslina.h"
#define BARSZCZ_SOSNOWSKIEGO_SZYBKOSC 1
#define BARSZCZ_SOSNOWSKIEGO_SILA 99
#define BARSZCZ_SOSNOWSKIEGO_INICJATYWA 0
#define BARSZCZ_SOSNOWSKIEGO_SYMBOL 'B'

class BarszczSosnowskiego : public Roslina {
private:
	bool czyZwierze = false;
public:
	BarszczSosnowskiego(Swiat* swiat, Punkt position);
	BarszczSosnowskiego();
	char getSymbol() override;
	int obronaPrzedOrganizmem(Organizm* organizmAtakujacy) override;
	void akcja() override;
	string organizmToString() override;
};