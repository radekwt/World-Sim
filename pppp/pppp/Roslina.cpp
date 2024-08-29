#include "Roslina.h"
#include "GeneratorOrganizmow.h"
Roslina::Roslina(Swiat* swiat, Organizm::Type type, Punkt position, int sila, int inicjatywa, int szybkosc)
	:Organizm(swiat, type, position, sila, inicjatywa, szybkosc)
{
}
void Roslina::rozprzestrzenianie() const {
	if (this->getAge() <2 )
		return;
	Punkt newPunkt;
	newPunkt = this->findFreeSpace(this->getHorizontalPostion(), this->getVerticalPostion());
	if (newPunkt.checkIfTheSame(this->getPosition())) {
		return;
	}
	this->swiat->pushOrganizmToVector(GeneratorOrganizmow::generateNewOrganizm(this->getType(), swiat, newPunkt));
	return;
}
bool Roslina::getCzyZwierze()
{
	return czyZwierze;
}
string Roslina::organizmToString()
{
	return "NoNameRoslina";
}
void Roslina::akcja() {
	int szansaNarozprzestrzenianie = rand() % 18;
	if(!szansaNarozprzestrzenianie)
		rozprzestrzenianie();
}

void Roslina::rysowanie()
{
}

bool Roslina::kolizja(Organizm* organizmKolidujacy)
{
	return true;
}
