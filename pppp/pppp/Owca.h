#pragma once
#define OWCA_SZYBKOSC 1
#define OWCA_SILA 4
#define OWCA_INICJATYWA 4
#define OWCA_SYMBOL 'O'
#include "Zwierze.h"
class Owca : public Zwierze
{
private:
	bool czyZwierze = true;
public:
	Owca(Swiat* swiat, Punkt position);
	Owca();
	char getSymbol() override;
	string organizmToString() override;
};

