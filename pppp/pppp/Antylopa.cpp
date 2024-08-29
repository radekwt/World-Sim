#include "Antylopa.h"

Antylopa::Antylopa(Swiat* swiat, Punkt position)
	:Zwierze(swiat, Type::ANTYLOPA, position, ANTYLOPA_SILA, ANTYLOPA_INICJATYWA, ANTYLOPA_SZYBKOSC)
{
}

char Antylopa::getSymbol()
{
	return ANTYLOPA_SYMBOL;
}

int Antylopa::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	bool czyUcieknie = rand() % 2;
	if (!czyUcieknie)
		return OBRONA_BRAK_OBRONY;
	Punkt newPunkt = findFreeSpace(this->getHorizontalPostion(), this->getVerticalPostion());
	if (!newPunkt.checkIfTheSame(this->getPosition())) {
		this->ruchNaWolnePole(this->getHorizontalPostion(), newPunkt.GetX(), this->getVerticalPostion(), newPunkt.GetY());
		return OBRONA_UCIECZKA;
	}
	return OBRONA_BRAK_OBRONY;
}

string Antylopa::organizmToString()
{
	return "Antylopa";
}

