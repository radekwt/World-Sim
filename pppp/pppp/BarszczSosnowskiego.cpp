#include  "BarszczSosnowskiego.h"
BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, Punkt position)
	:Roslina(swiat, Type::BARSZCZ_SOSNOWSKIEGO, position, BARSZCZ_SOSNOWSKIEGO_SILA, BARSZCZ_SOSNOWSKIEGO_INICJATYWA, BARSZCZ_SOSNOWSKIEGO_SZYBKOSC)
{
}

char BarszczSosnowskiego::getSymbol()
{
	return BARSZCZ_SOSNOWSKIEGO_SYMBOL;
}
int BarszczSosnowskiego::obronaPrzedOrganizmem(Organizm* organizmAtakujacy)
{
	return OBRONA_OBOJE_GINA;
}

void BarszczSosnowskiego::akcja()
{
	int szansaNarozprzestrzenianie = rand() % 18;
	if (!szansaNarozprzestrzenianie)
		rozprzestrzenianie();

	int x = this->getHorizontalPostion();
	int y = this->getVerticalPostion();
	int s = 1;
	int szansaNaAtakObszarowy = rand() % 3;
	if (szansaNaAtakObszarowy) {
		return;
	}
	if (checkNextMove(x, s, y, 0) == ANOTHER_ORGANIZM_DETECTED_ZWIERZE) {
		Komentator::powiadomOSmierci(this, this->swiat->getOrganizmFromMapa(x + s, y));
		this->swiat->killOrganizm(this->swiat->getOrganizmFromMapa(x + s, y));
	}
	if (checkNextMove(x, -s, y, 0) == ANOTHER_ORGANIZM_DETECTED_ZWIERZE) {
		Komentator::powiadomOSmierci(this, this->swiat->getOrganizmFromMapa(x - s, y));
		this->swiat->killOrganizm(this->swiat->getOrganizmFromMapa(x - s, y));
	}
	if (checkNextMove(x, 0, y, s) == ANOTHER_ORGANIZM_DETECTED_ZWIERZE) {
		Komentator::powiadomOSmierci(this, this->swiat->getOrganizmFromMapa(x, y+s));
		this->swiat->killOrganizm(this->swiat->getOrganizmFromMapa(x, y + s));
	}
	if (checkNextMove(x, 0, y, -s) == ANOTHER_ORGANIZM_DETECTED_ZWIERZE) {
		Komentator::powiadomOSmierci(this, this->swiat->getOrganizmFromMapa(x, y-s));
		this->swiat->killOrganizm(this->swiat->getOrganizmFromMapa(x, y - s));
	}
	return;
}

string BarszczSosnowskiego::organizmToString()
{
	return "Barszcz Sosnowskiego";
}
