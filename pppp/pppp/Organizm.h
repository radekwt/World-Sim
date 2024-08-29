#pragma once
#include <string>
#include "Swiat.h"
#include "Punkt.h"
#include "Direction.h"
#include "Komentator.h"
#define MOVE_IN_BORDER 1
#define MOVE_OUT_OF_BORDER -1
#define ANOTHER_ORGANIZM_DETECTED 0
#define ANOTHER_ORGANIZM_DETECTED_ZWIERZE 2
#define ANOTHER_ORGANIZM_DETECTED_ROSLINA 3


#define OBRONA_OBOJE_GINA -1
#define OBRONA_BLOK 1
#define OBRONA_BRAK_OBRONY 0
#define OBRONA_UCIECZKA 5

using namespace std;

class Swiat;
class Punkt;
class Komentator;

class Organizm {
public:
	enum class Type {
		WILK,
		LIS,
		OWCA,
		ZOLW,
		ANTYLOPA,
		TRAWA,
		MLECZ,
		GUARANA,
		WILCZE_JAGODY,
		BARSZCZ_SOSNOWSKIEGO,
		CZLOWIEK
	};
protected:
	Type type;
	int sila, inicjatywa,szybkosc;
	int age = 0;
	Swiat* swiat;
	Punkt position;
public:
	int getSila() const;
	int getInicjatywa() const;
	int getAge() const;
	int getSzybkosc() const;
	Type getType() const;
	void increseAge();
	void increseSila(int deltaSila);
	virtual char getSymbol()=0;
	void changePunkt(int deltaX,int deltaY);
	Organizm(Swiat* swiat, Type type, Punkt position, int sila, int inicjatywa,int szybkosc);
	int getVerticalPostion()const;
	int getHorizontalPostion()const;
	Punkt getPosition()const;
	virtual void akcja() = 0;
	virtual bool kolizja(Organizm* organizmKolidujacy) = 0;
	virtual void rysowanie() = 0;
	int checkNextMove(int x, int deltaX, int y, int deltaY)const;
	Punkt findFreeSpace(int x, int y)const;
	virtual int obronaPrzedOrganizmem(Organizm* organizmAtakujacy);
	bool obronaHandler(Organizm* organizmAtakujacy);
	virtual bool getCzyZwierze() = 0;
	virtual string organizmToString() = 0;
};