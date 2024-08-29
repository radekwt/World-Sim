#include "Zwierze.h"
#include <Windows.h>
#include "GeneratorOrganizmow.h"
Zwierze::Zwierze(Swiat* swiat, Organizm::Type type, Punkt position, int sila, int inicjatywa,int szybkosc)
	:Organizm(swiat, type, position, sila, inicjatywa,szybkosc)
{
}
bool Zwierze::atakNaOrganizm(Organizm* organizmAtakowany)
{
	if (this->kolizja(organizmAtakowany))
		return true;
	else
		return false;
}

int Zwierze::ruchNaWolnePole(int x, int deltaX, int y, int deltaY)
{
	swiat->changeMapaOrganizmow(x, deltaX, y, deltaY);
	return 1;
}
void Zwierze::akcja()
{
	Direction direction = swiat->getDirections()[rand() % 4];
	int deltaX = 0, deltaY = 0, range = this->getSzybkosc();
	if (direction == Direction::UP)
		deltaY = range;
	if (direction == Direction::DOWN)
		deltaY = -range;
	if (direction == Direction::RIGHT)
		deltaX = range;
	if (direction == Direction::LEFT)
		deltaX = -range;
	this->poruszSie(deltaX, deltaY);
	return;
}

void Zwierze::poruszSie(int deltaX,int deltaY)
{
	int x = this->getHorizontalPostion();
	int y = this->getVerticalPostion();
	int nextMove = checkNextMove(x, deltaX, y, deltaY);
	if (nextMove == MOVE_IN_BORDER) {
		this->ruchNaWolnePole(x, x + deltaX, y, y + deltaY);
		return;
	}
	else if (nextMove == ANOTHER_ORGANIZM_DETECTED_ZWIERZE || nextMove == ANOTHER_ORGANIZM_DETECTED_ROSLINA) {
		if (this->atakNaOrganizm(swiat->getOrganizmFromMapa(x + deltaX, y + deltaY))) {
			this->ruchNaWolnePole(x, x + deltaX, y, y + deltaY);
			return;
		}
		return;
	}
	else if (nextMove == MOVE_OUT_OF_BORDER) {
		return;
	}
}

void Zwierze::rysowanie()
{
}
string Zwierze::organizmToString()
{
	return "NoNameZwierze";
}
void Zwierze::rozmnazanie(Organizm* organizm2) {
	if (this->getAge() < 2 || organizm2->getAge() < 2){
		return;
	}
	Punkt newPunkt;
	newPunkt = this->findFreeSpace(this->getHorizontalPostion(), this->getVerticalPostion());
	if (newPunkt.checkIfTheSame(this->getPosition())) {
		newPunkt = organizm2->findFreeSpace(organizm2->getHorizontalPostion(), organizm2->getVerticalPostion());
		if (newPunkt.checkIfTheSame(organizm2->getPosition())) {
			return;
		}
		this->swiat->pushOrganizmToVector(GeneratorOrganizmow::generateNewOrganizm(this->getType(), swiat, newPunkt));
		return;
	}
	this->swiat->pushOrganizmToVector(GeneratorOrganizmow::generateNewOrganizm(this->getType(), swiat, newPunkt));
	return;
}
bool Zwierze::getCzyZwierze()
{
	return czyZwierze;
}
bool Zwierze::kolizja(Organizm* organizmKolidujacy){
	if (organizmKolidujacy->getCzyZwierze() == false) {
		if (organizmKolidujacy->obronaHandler(this))
			return true;
		else
			return false;
	}
	else if (this->getType() == organizmKolidujacy->getType()) {
		this->rozmnazanie(organizmKolidujacy);
		return false;
	}
	else if (this->getSila() == organizmKolidujacy->getSila()) {
		if (this->getAge() > organizmKolidujacy->getAge()) {
			if (organizmKolidujacy->obronaHandler(this))
				return true;
			else
				return false;
		}
		else if (this->getAge() < organizmKolidujacy->getAge()) {
			Komentator::powiadomOSmierci(organizmKolidujacy, this);
			this->swiat->killOrganizm(this);
			return false;
		}
		else {
			Komentator::powiadomOSmierci(organizmKolidujacy, this);
			this->swiat->killOrganizm(this);
			return false;
		}
	}
	else if (this->getSila() > organizmKolidujacy->getSila()) {
		if (organizmKolidujacy->obronaHandler(this))
			return true;
		else
			return false;
	}
	else if (this->getSila() < organizmKolidujacy->getSila()) {
		Komentator::powiadomOSmierci(organizmKolidujacy, this);
		this->swiat->killOrganizm(this);
		return false;
	}
	return false;
}





