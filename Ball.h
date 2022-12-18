#pragma once

#include <iostream>
#include <vector>

#include "Games_Object.h"

class Ball : public Games_object
{
public:
	Ball(int posX, int posY);

	void Change_Dir(eDir dir);
	void Rand_Dir();
	
	~Ball() = default;
private:
	std::vector<eDir> _vecOfDir = {eDir::STOP, eDir::LEFT, eDir::UPLEFT, eDir::DOWNLEFT, eDir::RIGHT, eDir::UPRIGHT, eDir::DOWNRIGHT};

	eDir Return_randon_dir();
protected:
};