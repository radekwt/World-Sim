#include "Lis.h"
#include "Swiat.h"
Lis::Lis(Swiat* swiat, Punkt position)
	:Zwierze(swiat, Type::LIS, position, LIS_SILA, LIS_INICJATYWA, LIS_SZYBKOSC)
{
}
char Lis::getSymbol()
{
	return LIS_SYMBOL;
}

bool Lis::atakNaOrganizm(Organizm* organizmAtakowany)
{
	if (organizmAtakowany->getSila() > this->getSila() && organizmAtakowany->getCzyZwierze()==true) {
		return false;
	}
	if (this->kolizja(organizmAtakowany))
		return true;
	else
		return false;
}

string Lis::organizmToString()
{
	return "Lis";
}
