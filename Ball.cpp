#include "Ball.h"

Ball::Ball(int posX, int posY): Games_object(posX, posY){}

void Ball::Change_Dir(eDir dir) { this->_dir = dir;}

void Ball::Rand_Dir()
{
	this->_dir = this->Return_randon_dir();
}

eDir Ball::Return_randon_dir()
{
	return this->_vecOfDir.at(rand() % (this->_vecOfDir.size()-1)+1);
}

