#include "Plaers.h"

Plaers::Plaers(int posX, int posY)
{
	this->racket = new Racket(posX, posY);

	this->_down = 'd';
	this->_up = 'a';
	this->_score = 0;
}

Plaers::Plaers(const Plaers& obj)
{
	if (obj.racket == nullptr)
		return;

	this->racket = obj.racket;

	this->_down = obj._down;
	this->_score = obj._score;
	this->_up = obj._up;
}

Plaers::~Plaers()
{
	if (this == nullptr)
		return;

	delete this->racket;
}

Plaers& Plaers::operator=(const Plaers& obj)
{
	this->racket = obj.racket;

	this->_down = this->_down;
	this->_score = this->_score;
	this->_up = this->_up;

	return *this;
}

void Plaers::Reset() 
{
	this->racket->Reset();
}

void Plaers::Move(char& current, int& heigt) 
{
	if (current == this->_up && this->racket->Get_Y() > 0)
		this->racket->Move_UP();
	else if (current == this->_down && this->racket->Get_Y() < heigt-1)
		this->racket->Move_Down();
}

void Plaers::Up_Score()
{
	++this->_score;
}

int Plaers::Get_X()
{
	return this->racket->Get_X();
}

int Plaers::Get_Y()
{
	return this->racket->Get_Y();
}

int Plaers::Get_Score()
{
	return this->_score;
}

