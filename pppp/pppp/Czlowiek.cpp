#pragma warning(disable : 4996)
#include "Czlowiek.h"
#include <conio.h>
#include <iostream>
#include <stdlib.h>
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define SPACEBAR 32
Czlowiek::Czlowiek(Swiat* swiat, Punkt position)
	:Zwierze(swiat, Type::CZLOWIEK, position, CZLOWIEK_SILA, CZLOWIEK_INICJATYWA, CZLOWIEK_SZYBKOSC)
{
}

char Czlowiek::getSymbol()
{
	return CZLOWIEK_SYMBOL;
}

string Czlowiek::organizmToString()
{
	return "Czlowiek";
}

void Czlowiek::akcja()
{
	int input = 0;
	int deltaX = 0, deltaY = 0, range = 1;
	bool poruszenie = false;
	bool aktywacjaUmiejetnosci = false;
	while (1) {
		input = getch();
		if (input == KEY_UP) {
			deltaY = -range;
			poruszenie = true;
			break;
		}
		else if (input == KEY_DOWN) {
			deltaY = range;
			poruszenie = true;
			break;
		}
		else if (input == KEY_LEFT) {
			deltaX = -range;
			poruszenie = true;
			break;
		}
		else if (input == KEY_RIGHT) {
			deltaX = range;
			poruszenie = true;
			break;
		}
		else if (input == SPACEBAR) {
			if ((cooldownUmiejetnosci == 0)) {
				aktywujUmiejetnosc();
				break;
			}
			else
			{
				cout << "nie mozna aktywowac umiejetnosci. Cooldown: " << cooldownUmiejetnosci << endl;
			}
		}
	}
	if(poruszenie)
	this->poruszSie(deltaX, deltaY);
}
void Czlowiek::aktywujUmiejetnosc()
{
	cooldownUmiejetnosci = 10;
	czySpecAktywna = true;
}
int Czlowiek::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	if (czySpecAktywna) {
		return OBRONA_BLOK;
	}
	return OBRONA_BRAK_OBRONY;
}


