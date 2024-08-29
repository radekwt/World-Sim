#pragma once
#include "Roslina.h"
#define GUARANA_SZYBKOSC 1
#define GUARANA_SILA 0
#define GUARANA_INICJATYWA 0
#define GUARANA_SYMBOL 'G'

class Guarana : public Roslina {
private:
	bool czyZwierze = false;
public:
	Guarana(Swiat* swiat, Punkt position);
	Guarana();
	char getSymbol() override;
	int obronaPrzedOrganizmem(Organizm* organizmAtakujacy) override;
	string organizmToString() override;
};