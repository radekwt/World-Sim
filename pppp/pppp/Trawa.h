#pragma once
#include "Roslina.h"
#define TRAWA_SZYBKOSC 1
#define TRAWA_SILA 0
#define TRAWA_INICJATYWA 0
#define TRAWA_SYMBOL 'T'

class Trawa : public Roslina {
private:
	bool czyZwierze = false;
public:
	Trawa(Swiat* swiat, Punkt position);
	Trawa();
	char getSymbol() override;
	string organizmToString() override;
};