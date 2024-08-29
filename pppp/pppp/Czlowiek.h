#pragma once
#include "Zwierze.h"
#define CZLOWIEK_SZYBKOSC 1
#define CZLOWIEK_SILA 5
#define CZLOWIEK_INICJATYWA 1
#define CZLOWIEK_SYMBOL 'C'
class Czlowiek : public Zwierze
{
private:
	bool czyZwierze = true;
	bool czySpecAktywna = false;
	bool czyMoznaAktywowac = true;
	int cooldownUmiejetnosci = 0;
	int pozostalyCzas = 0;
public:
	Czlowiek(Swiat* swiat, Punkt position);
	Czlowiek();
	char getSymbol() override;
	string organizmToString() override;
	int obronaPrzedOrganizmem(Organizm* organizmAtakujacy) override;
	void akcja() override;
	void aktywujUmiejetnosc();
};

