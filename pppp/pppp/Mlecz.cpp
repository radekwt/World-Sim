#include "Mlecz.h"
Mlecz::Mlecz(Swiat* swiat, Punkt position)
	:Roslina(swiat, Type::MLECZ, position, MLECZ_SILA, MLECZ_INICJATYWA, MLECZ_SZYBKOSC)
{
}

char Mlecz::getSymbol()
{
	return MLECZ_SYMBOL;
}
void Mlecz::akcja() {
	int szansaNarozprzestrzenianie = rand() % 6;
	if (!szansaNarozprzestrzenianie)
		rozprzestrzenianie();
}

string Mlecz::organizmToString()
{
	return "Mlecz";
}
