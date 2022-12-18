#include "Racket.h"

Racket::Racket()
{
	this->_posX = 0;
	this->_posY = 0;
}

Racket::Racket(int posX, int posY)
{
	this->_origX = posX;
	this->_origY = posY;
	this->_posX = posX;
	this->_posY = posY;
}

void Racket::Reset()
{
	this->_posX = this->_origX;
	this->_posY = this->_origY;
}

void Racket::Move_Down() 
{
	++this->_posY;
}

void Racket::Move_UP() 
{
	--this->_posY;
}

void Racket::Set_posY(int posY)
{
	this->_posY = posY;
}