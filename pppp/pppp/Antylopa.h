#pragma once
#include "Zwierze.h"
#define ANTYLOPA_SZYBKOSC 2
#define ANTYLOPA_SILA 4
#define ANTYLOPA_INICJATYWA 4
#define ANTYLOPA_SYMBOL 'A'
class Antylopa: public Zwierze
{
private:
	bool czyZwierze = true;
public:
	Antylopa();
	Antylopa(Swiat *swiat,Punkt position);
	char getSymbol() override;
	int obronaPrzedOrganizmem(Organizm* organizmAtakujacy) override;
	string organizmToString() override;
};

