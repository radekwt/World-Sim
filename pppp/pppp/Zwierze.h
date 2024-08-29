#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	bool czyZwierze = true;
public:
	Zwierze(Swiat* swiat, Organizm::Type type, Punkt position, int sila, int inicjatywa,int szybkosc);
	void akcja() override;
	void poruszSie(int deltaX, int deltaY);
	void rysowanie() override;
	bool kolizja(Organizm* organizmKolidujacy) override;
	virtual bool atakNaOrganizm(Organizm* organizmAtakowany);
	virtual int ruchNaWolnePole(int x, int deltaX, int y, int deltaY);
	virtual char getSymbol() = 0;
	virtual string organizmToString() override;
	void rozmnazanie(Organizm* organizm2);
	bool getCzyZwierze() override;
};
