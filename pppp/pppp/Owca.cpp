#include "Owca.h"

Owca::Owca(Swiat* swiat, Punkt position)
	:Zwierze(swiat, Type::OWCA, position, OWCA_SILA, OWCA_INICJATYWA, OWCA_SZYBKOSC)
{
}

char Owca::getSymbol()
{
	return OWCA_SYMBOL;
}

string Owca::organizmToString()
{
	return "Owca";
}
