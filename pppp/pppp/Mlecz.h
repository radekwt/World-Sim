#pragma once
#include "Roslina.h"
#define MLECZ_SZYBKOSC 1
#define MLECZ_SILA 0
#define MLECZ_INICJATYWA 0
#define MLECZ_SYMBOL 'M'

class Mlecz : public Roslina {
private:
	bool czyZwierze = false;
public:
	Mlecz(Swiat* swiat, Punkt position);
	Mlecz();
	char getSymbol() override;
	void akcja() override;
	string organizmToString() override;
};