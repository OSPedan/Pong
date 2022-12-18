#pragma once
#include "Plaers.h"
#include "Ball.h"

class Bot : public Plaers
{
public:
	Bot();
	Bot(int posX, int posY);
	Bot(const Bot& obj);
	virtual ~Bot();

	virtual void Move(Ball& obj);
private:
	virtual void Choise_to_Move(Ball& obj);
	virtual void Move_UP(Ball& obj);
	virtual void Move_Down(Ball& obj);
protected:
};