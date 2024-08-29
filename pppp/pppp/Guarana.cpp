#include "Guarana.h"
Guarana::Guarana(Swiat* swiat, Punkt position)
	:Roslina(swiat, Type::GUARANA, position, GUARANA_SILA, GUARANA_INICJATYWA, GUARANA_SZYBKOSC)
{
}

char Guarana::getSymbol()
{
	return GUARANA_SYMBOL;
}
int Guarana::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	organizmAtakujacy->increseSila(3);
	return OBRONA_BRAK_OBRONY;
}

string Guarana::organizmToString()
{
	return "Guarana";
}

