#include "Wilk.h"

Wilk::Wilk(Swiat* swiat, Punkt position)
	:Zwierze(swiat, Type::WILK, position, WILK_SILA, WILK_INICJATYWA, WILK_SZYBKOSC)
{
}

char Wilk::getSymbol()
{
	return WILK_SYMBOL;
}

string Wilk::organizmToString()
{
	return "Wilk";
}
