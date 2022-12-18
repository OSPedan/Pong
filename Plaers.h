#pragma once

#include "Racket.h"

class Plaers
{
public:
	Plaers() = default;
	Plaers(int posX, int posY);
	Plaers(const Plaers& obj);
	virtual ~Plaers();

	Plaers& operator=(const Plaers& obj);

	virtual void Reset();
	virtual void Move(char& current, int& height);
	void Up_Score();
	int Get_X();
	int Get_Y();

	int Get_Score();
private:
protected:
	int _score;
	char _up;
	char _down;

	Racket* racket = nullptr;
};
