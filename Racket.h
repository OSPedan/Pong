#pragma once

#include <iostream>
#include <vector>

#include "Games_Object.h"

class Racket : public Games_object
{
public:
	Racket();
	Racket(int posX, int posY);
	~Racket() = default;

	friend std::ostream& operator<<(std::ostream& osOp, const Racket& obj)
	{
		osOp << "Obj[" << obj._posX << "," << obj._posY << "]";
		return osOp;
	}
	
	virtual void Reset();
	void Move_Down();
	void Move_UP();
	void Set_posY(int posY);

private:
protected:
};
