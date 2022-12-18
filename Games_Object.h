#pragma once

#include <iostream>

enum class eDir { STOP = 0, LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT, };

class Games_object
{
public:
	Games_object() = default;
	Games_object(int posX, int posY);
	Games_object(const Games_object& obj);
	virtual ~Games_object() = default;

	Games_object& operator=(const Games_object& obj);
	friend std::ostream& operator<< (std::ostream& osOp, const Games_object& obj) 
	{
		osOp << "Obj[" << obj._posX << "," << obj._posY << "][" << static_cast<int>(obj._dir) << "]";
		return osOp;
	}

	virtual void Move();
	virtual void Reset();

	virtual int Get_X();
	virtual int Get_Y();
	virtual eDir Get_Dir();

private:
protected:
	int _posX, _posY;
	int _origX, _origY;
	eDir _dir;
};