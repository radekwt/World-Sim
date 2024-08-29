#pragma once
#include "Organizm.h"
class Organizm;
class Komentator
{
public:
	static void powiadomOSmierci(Organizm* zabijajacy, Organizm* umierajacy);
	static void powiadomOUniku(Organizm* atakujacy, Organizm* unikajcy);
	static void powiadomOBloku(Organizm* atakujacy, Organizm* blokujacy);
	static void powiadomOZatruciu(Organizm* roslina, Organizm* zwierze);
};

