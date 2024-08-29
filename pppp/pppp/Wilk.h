#pragma once
#include "Zwierze.h"
#define WILK_SZYBKOSC 1
#define WILK_SILA 9
#define WILK_INICJATYWA 5
#define WILK_SYMBOL 'W'

class Wilk : public Zwierze {
private:
	bool czyZwierze = true;
public:
	Wilk(Swiat* swiat, Punkt position);
	Wilk();
	char getSymbol() override;
	string organizmToString() override;
};