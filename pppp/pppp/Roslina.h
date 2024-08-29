#pragma once
#include "Organizm.h"

class Roslina : public Organizm {
protected:
	bool czyZwierze = false;
public:
	Roslina(Swiat* swiat, Organizm::Type type, Punkt position, int sila, int inicjatywa, int szybkosc);
	void akcja() override;
	void rysowanie() override;
	bool kolizja(Organizm* organizmKolidujacy) override;
	virtual char getSymbol() = 0;
	void rozprzestrzenianie() const;
	bool getCzyZwierze() override;
	virtual string organizmToString() override;
};