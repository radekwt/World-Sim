#include "Trawa.h"
Trawa::Trawa(Swiat* swiat, Punkt position)
	:Roslina(swiat, Type::TRAWA, position, TRAWA_SILA, TRAWA_INICJATYWA, TRAWA_SZYBKOSC)
{
}

char Trawa::getSymbol()
{
	return TRAWA_SYMBOL;
}

string Trawa::organizmToString()
{
	return "Trawa";
}
