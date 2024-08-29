#include "Punkt.h"

Punkt::Punkt(int x, int y) {
	this->x = x;
	this->y = y;
}

Punkt::Punkt() :x(0), y(0) {
}

void Punkt::SetX(int x) {
	this->x = x;
}

void Punkt::SetY(int y) {
	this->y = y;
}

int Punkt::GetX()const {
	return x;
}

int Punkt::GetY()const {
	return y;
}

void Punkt::moveUp() {
	y++;
}

void Punkt::moveDown() {
	y--;
}

void Punkt::moveRight() {
	x++;
}

void Punkt::moveLeft() {
	x--;
}

void Punkt::punktToString()const
{
	std::cout << "x: " << x << " y: " << y << std::endl;
}

void Punkt::move(int newX, int newY){
	x = newX;
	y = newY;
}

bool Punkt::checkIfTheSame(Punkt p) const {
	if (this->GetX() == p.GetX()) {
		if (this->GetY() == p.GetY()) {
			return true;
		}
	}
	return false;
}

Punkt* Punkt::returnPunkt()
{
	return this;
}
