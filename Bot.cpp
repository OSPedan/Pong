#include "Bot.h"

Bot::Bot(){}
Bot::Bot(int posX, int posY)
{
	this->racket = new Racket(posX, posY);
	this->_score = 0;
}

Bot::Bot(const Bot& obj)
{
	if (&obj == nullptr)
		return;

	this->racket = obj.racket;
	this->_score = obj._score;
}

Bot::~Bot() 
{
	if (this == nullptr)
		return;
}

void Bot::Move(Ball& obj)
{
	Choise_to_Move(obj);
}

void Bot::Choise_to_Move(Ball& obj)
{
	if (obj.Get_Dir() == eDir::UPRIGHT)
		this->Move_UP(obj);
	else if (obj.Get_Dir() == eDir::DOWNRIGHT)
		this->Move_Down(obj);
	else if (obj.Get_Dir() == eDir::RIGHT)
	{
		this->Move_Down(obj);
		this->Move_UP(obj);
	}
}

void Bot::Move_UP(Ball& obj)
{
	if (this->racket->Get_Y() != obj.Get_Y() && this->racket->Get_Y() > obj.Get_Y())
		racket->Move_UP();
}

void Bot::Move_Down(Ball& obj)
{
	if (this->racket->Get_Y() != obj.Get_Y() && this->racket->Get_Y() < obj.Get_Y())
		racket->Move_Down();
}