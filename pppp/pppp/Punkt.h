#pragma once
#include<iostream>
class Punkt {
protected:
	int x, y;
public:
	Punkt();
	Punkt(int x, int y);
	void SetX(int x);
	void SetY(int y);
	int GetX() const;
	int GetY() const;
	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();
	void punktToString() const;
	void move(int deltaX,int deltaY);
	bool checkIfTheSame(Punkt p) const;
	Punkt* returnPunkt();
};