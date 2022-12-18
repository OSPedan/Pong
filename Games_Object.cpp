#include "Games_Object.h"

Games_object::Games_object(int posX, int posY)
	:_origX(posX), _origY(posY), _posX(posX), _posY(posY), _dir(eDir::STOP){}

Games_object::Games_object(const Games_object& obj)
{
	this->_origX = obj._origX;
	this->_origY = obj._origY;
	this->_posX = obj._posX;
	this->_posY = obj._posY;
	this->_dir = obj._dir;
}

Games_object& Games_object::operator=(const Games_object& obj)
{
	this->_origX = obj._origX;
	this->_origY = obj._origY;
	this->_posX = obj._posX;
	this->_posY = obj._posY;
	this->_dir = obj._dir;

	return *this;
}

void Games_object::Move()
{
	switch (this->_dir)
	{
	case eDir::LEFT:
		this->_posX--;
		break;
	case eDir::UPLEFT:
		this->_posX--;
		this->_posY--;
		break;
	case eDir::DOWNLEFT:
		this->_posX--;
		this->_posY++;
		break;
	case eDir::RIGHT:
		this->_posX++;
		break;
	case eDir::UPRIGHT:
		this->_posX++;
		this->_posY--;
		break;
	case eDir::DOWNRIGHT:
		this->_posX++;
		this->_posY++;
		break;
	default:
		break;
	}
}

void Games_object::Reset()
{
	this->_posX = this->_origX;
	this->_posY = this->_origY;
	this->_dir = eDir::STOP;
}

int Games_object::Get_X() { return this->_posX; }
int Games_object::Get_Y() { return this->_posY; }
eDir Games_object::Get_Dir() { return this->_dir; }