#pragma once
#include "Roslina.h"
#define WILCZE_JAGODY_SZYBKOSC 1
#define WILCZE_JAGODY_SILA 10
#define WILCZE_JAGODY_INICJATYWA 0
#define WILCZE_JAGODY_SYMBOL 'J'

class WilczeJagody : public Roslina {
private:
	bool czyZwierze = false;
public:
	WilczeJagody(Swiat* swiat, Punkt position);
	WilczeJagody();
	char getSymbol() override;
	int obronaPrzedOrganizmem(Organizm* organizmAtakujacy) override;
	string organizmToString() override;
};