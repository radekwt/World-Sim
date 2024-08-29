#include "WilczeJagody.h"
WilczeJagody::WilczeJagody(Swiat* swiat, Punkt position)
	:Roslina(swiat, Type::WILCZE_JAGODY, position, WILCZE_JAGODY_SILA, WILCZE_JAGODY_INICJATYWA, WILCZE_JAGODY_SZYBKOSC)
{
}

char WilczeJagody::getSymbol()
{
	return WILCZE_JAGODY_SYMBOL;
}
int WilczeJagody::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	return OBRONA_OBOJE_GINA;
}

string WilczeJagody::organizmToString()
{
	return "Wilcze Jagody";
}
