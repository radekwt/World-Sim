#include "GeneratorOrganizmow.h"

Organizm* GeneratorOrganizmow::generateNewOrganizm(Organizm::Type typOrganizmu, Swiat* swiat, Punkt pozycja)
{
	if(typOrganizmu == Organizm::Type::WILK)
		return new Wilk(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::LIS)
		return new Lis(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::OWCA)
		return new Owca(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::ZOLW)
		return new Zolw(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::ANTYLOPA)
		return new Antylopa(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::TRAWA)
		return new Trawa(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::MLECZ)
		return new Mlecz(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::GUARANA)
		return new Guarana(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::WILCZE_JAGODY)
		return new WilczeJagody(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::BARSZCZ_SOSNOWSKIEGO)
		return new BarszczSosnowskiego(swiat, pozycja);
	if (typOrganizmu == Organizm::Type::CZLOWIEK)
		return new Czlowiek(swiat, pozycja);
}
