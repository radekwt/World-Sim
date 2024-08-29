#pragma once
#include "Swiat.h"
#include "Wilk.h"
#include "Lis.h"
#include "Owca.h"
#include "Zolw.h"
#include "Antylopa.h"
#include "Trawa.h"
#include "Mlecz.h"
#include "Guarana.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Czlowiek.h"
class GeneratorOrganizmow
{
public:
	static Organizm* generateNewOrganizm(Organizm::Type typOrganizmu, Swiat* swiat, Punkt pozycja);
};

