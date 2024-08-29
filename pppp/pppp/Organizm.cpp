#include "Organizm.h"
#include "GeneratorOrganizmow.h"
#define ORGANIZM_NA_POLU 1
#define PUSTE_POLE 0
#define BRAK_MIEJSCA -1


int Organizm::getSila()const
{
	return sila;
}
int Organizm::getInicjatywa()const
{
	return inicjatywa;
}
int Organizm::getAge()const
{
	return age;
}
int Organizm::getSzybkosc() const {
	return szybkosc;
}
Organizm::Type Organizm::getType()const
{
	return this->type;
}
void Organizm::increseAge()
{
	age += 1;
}

void Organizm::increseSila(int deltaSila)
{
	sila = sila + deltaSila;
}


void Organizm::changePunkt(int newX, int newY)
{
	this->position.move(newX, newY);
}
Organizm::Organizm(Swiat* swiat, Type type, Punkt position, int sila, int inicjatywa,int szybkosc)
	:swiat(swiat), type(type), position(position), sila(sila), inicjatywa(inicjatywa) ,szybkosc(szybkosc){
}

int Organizm::getVerticalPostion()const
{
	return position.GetY();
}

int Organizm::getHorizontalPostion()const
{
	return position.GetX();
}
Punkt Organizm::getPosition()const
{
	return position;
}
int Organizm::checkNextMove(int x, int deltaX, int y, int deltaY)const
{
	int maxX = this->swiat->getWidth() - 1;
	int maxY = this->swiat->getHeight() - 1;
	int minX = 0, minY = 0;
	if (minX > x + deltaX || x + deltaX > maxX || minY > y + deltaY || y + deltaY > maxY) {
		return MOVE_OUT_OF_BORDER;
	}
	else {
		if (swiat->getOrganizmFromMapa(x + deltaX, y + deltaY) != nullptr) {
			if (swiat->getOrganizmFromMapa(x + deltaX, y + deltaY)->getCzyZwierze())
				return ANOTHER_ORGANIZM_DETECTED_ZWIERZE;
			else
				return ANOTHER_ORGANIZM_DETECTED_ROSLINA;

		}
		return MOVE_IN_BORDER;
	}
}

Punkt Organizm::findFreeSpace(int x, int y)const
{
	int s = 1;
	if (checkNextMove(x, s, y, 0)==MOVE_IN_BORDER) {
		return Punkt(x + s, y);
	}
	else if (checkNextMove(x, -s, y, 0)== MOVE_IN_BORDER) {
		return Punkt(x - s, y);
	}
	else if (checkNextMove(x, 0, y, s)== MOVE_IN_BORDER) {
		return Punkt(x, y + s);
	}
	else if (checkNextMove(x, 0, y, -s)== MOVE_IN_BORDER) {
		return Punkt(x, y - s);
	}
	return Punkt(x, y);
}

int Organizm::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	return OBRONA_BRAK_OBRONY;
}

bool Organizm::obronaHandler(Organizm* organizmAtakujacy)
{
	int typObrony = this->obronaPrzedOrganizmem(organizmAtakujacy);
	if (typObrony == OBRONA_BRAK_OBRONY) {
		Komentator::powiadomOSmierci(organizmAtakujacy, this);
		this->swiat->killOrganizm(this);
		return true;
	}
	else if (typObrony == OBRONA_BLOK) {
		Komentator::powiadomOBloku(organizmAtakujacy, this);
		return false;
	}
	else if (typObrony == OBRONA_OBOJE_GINA) {
		Komentator::powiadomOZatruciu(this, organizmAtakujacy);
		swiat->killOrganizm(organizmAtakujacy);
		swiat->killOrganizm(this);
		return false;
	}
	else if (typObrony ==OBRONA_UCIECZKA) {
		Komentator::powiadomOUniku(organizmAtakujacy,this);
		return true;
	}
	return false;
}


