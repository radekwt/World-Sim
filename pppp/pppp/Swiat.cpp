#pragma once
#include "Swiat.h"
#include <random>
#include "GeneratorOrganizmow.h"
int Swiat::getWidth() const
{
	return width;
}

int Swiat::getHeight() const
{
	return height;
}

Swiat::Swiat(int width, int height)
	:width(width), height(height) {
	mapaOrganizmow = new Organizm * *[width];
	for (int i = 0; i < width; i++) {
		mapaOrganizmow[i] = new Organizm * [height];
		for (int j = 0; j < height; j++) {
			mapaOrganizmow[i][j] = nullptr;
		}
	}
	iloscOrganizmow = 0;
}

void Swiat::GenerujSwiat() const{

	
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			if (mapaOrganizmow[j][i] == nullptr) {
				cout << ". ";
			}
			else {
				cout << mapaOrganizmow[j][i]->getSymbol()<<" ";
			}
		}
		cout << endl;
	}
}

void Swiat::moveTheWorld(){
	bool czyCzlowiekZyje = false;
	for (int i = 1; i < iloscOrganizmow-1; i++) {
		for (int j = 1; j < iloscOrganizmow - i - 1; j++) {
			if (vektorOrganizmow[j]->getInicjatywa() < vektorOrganizmow[j + 1]->getInicjatywa()) {
				swap(vektorOrganizmow[j], vektorOrganizmow[j + 1]);
			}
		}
	}
	for (int i = 0; i < iloscOrganizmow; i++) {
		if (vektorOrganizmow[i]->getType() == Organizm::Type::CZLOWIEK) {
			czyCzlowiekZyje = true;
		}
		vektorOrganizmow[i]->increseAge();
		vektorOrganizmow[i]->akcja();
	}
	if (!czyCzlowiekZyje) {
		koniecGry = true;
	}
	cout << endl;
}
void Swiat::increseIloscOrganizmow(){
	this->iloscOrganizmow++;
}
void Swiat::killOrganizm(Organizm* organizm)
{
	int XPosition = organizm->getHorizontalPostion();
	int YPosition = organizm->getVerticalPostion();
	mapaOrganizmow[XPosition][YPosition] = nullptr;
	this->iloscOrganizmow--;
	for (size_t i = 0; i < vektorOrganizmow.size(); i++)
	{
		if (vektorOrganizmow[i] == organizm)
			vektorOrganizmow.erase(vektorOrganizmow.begin() + i);
	}

}
bool Swiat::czyKoniecGry()
{
	return koniecGry;
}
void Swiat::zakonczGre()
{
	koniecGry = true;
	return;
}
void Swiat::pushOrganizmToVector(Organizm* organizm) {
	this->vektorOrganizmow.push_back(organizm);
	this->increseIloscOrganizmow();
	int XPosition = organizm->getHorizontalPostion();
	int YPosition = organizm->getVerticalPostion();
	mapaOrganizmow[XPosition][YPosition] = organizm;
	organizm->increseAge();
}
void Swiat::createNewRandom(Punkt pozycja)
{
	vector<Organizm::Type> type = { 
		Organizm::Type::WILK,
		Organizm::Type::OWCA,
		Organizm::Type::ZOLW,
		Organizm::Type::ANTYLOPA,
		Organizm::Type::LIS,
		Organizm::Type::TRAWA,
		Organizm::Type::MLECZ,
		Organizm::Type::GUARANA,
		Organizm::Type::BARSZCZ_SOSNOWSKIEGO

	};
	this->pushOrganizmToVector(GeneratorOrganizmow::generateNewOrganizm(type[rand() % type.size()], this, pozycja));
}


vector<Punkt> Swiat::generateRandomPoints(int number) const{
	std::mt19937 eng;
	std::random_device r;
	std::seed_seq seed{ r(), r(), r(), r(), r(), r(), r(), r() };
	eng.seed(seed);
	std::uniform_int_distribution<> distX(0, width - 1); 
	std::uniform_int_distribution<> distY(0, height - 1);
	vector<Punkt> punkty;
	int k = 0;
	for (int i = 0; i < number + k; i++) {
		int x = distX(eng);
		int y = distY(eng);
		bool isTheSame = false;
		for (int j = i - 1 - k; j >= 0; j--) {
			if (Punkt(x, y).checkIfTheSame(punkty[j])) {
				k++;
				isTheSame = true;
				break;
			}
		}
		if (!isTheSame)
			punkty.push_back(Punkt(x, y));
	}
	return punkty;
}

void Swiat::generateRandomWorld()
{
	int ilosc = width*height/6;

	vector<Punkt> punkty = generateRandomPoints(ilosc);
	for (int i = 0; i < ilosc; i++) {
		if (i == 0) {
			this->pushOrganizmToVector(GeneratorOrganizmow::generateNewOrganizm(Organizm::Type::CZLOWIEK, this, punkty[i]));
		}
		else
		createNewRandom(punkty[i]);
	}
}

Organizm* Swiat::getOrganizmFromMapa(int X, int Y) const
{
	return mapaOrganizmow[X][Y];
}

void Swiat::changeMapaOrganizmow(int oldX, int newX, int oldY, int newY) const
{
	Organizm* org = mapaOrganizmow[oldX][oldY];
	mapaOrganizmow[oldX][oldY] = nullptr;
	mapaOrganizmow[newX][newY] = org;

	org->changePunkt(newX,newY);
}

vector<Direction> Swiat::getDirections() const
{
	return directions;
}



