#pragma once
#include <iostream>
#include <vector> 
#include "Organizm.h"
#include "Punkt.h"
#include "Direction.h"

using namespace std;

class Organizm;


class Swiat {
public:
	int getWidth() const;
	int getHeight() const;
	Swiat(int width, int height);
	void GenerujSwiat() const;
	void moveTheWorld();
	void createNewRandom(Punkt pozycja);
	vector<Punkt> generateRandomPoints(int number) const;
	void generateRandomWorld();
	Organizm* getOrganizmFromMapa(int X,int Y) const;
	void changeMapaOrganizmow(int X,int deltaX, int Y,int deltaY) const;
	vector<Direction> getDirections() const;
	void pushOrganizmToVector(Organizm* organizm);
	void increseIloscOrganizmow();
	void killOrganizm(Organizm* organizm);
	bool czyKoniecGry();
	void zakonczGre();
private:
	bool koniecGry = false;
	vector<Organizm*> vektorOrganizmow;
	vector<Direction> directions = {Direction::UP,Direction::DOWN, Direction::RIGHT, Direction::LEFT};
	int height, width, iloscOrganizmow;
	Organizm*** mapaOrganizmow;
};