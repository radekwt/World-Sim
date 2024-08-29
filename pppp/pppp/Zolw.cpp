#include "Zolw.h"
Zolw::Zolw(Swiat* swiat, Punkt position)
	:Zwierze(swiat, Type::ZOLW, position, ZOLW_SILA, ZOLW_INICJATYWA, ZOLW_SZYBKOSC)
{
}

char Zolw::getSymbol()
{
	return ZOLW_SYMBOL;
}

int Zolw::ruchNaWolnePole(int x, int deltaX, int y, int deltaY)
{
	int czySiePoruszy = rand() % 4;
	if (!czySiePoruszy) {
		swiat->changeMapaOrganizmow(x, deltaX, y, deltaY);
		return 1;
	}
	return 0;
}

int Zolw::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	if (organizmAtakujacy->getSila() < 5) {
		return OBRONA_BLOK;
	}
	return OBRONA_BRAK_OBRONY;
}

string Zolw::organizmToString()
{
	return "Zolw";
}
