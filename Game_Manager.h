#pragma once
#include <iostream>

#include "Plaers.h"
#include "Bot.h"
#include "Ball.h"
#include "Table.h"

enum class Type_Of_Plaer { PERSON = 1, BOT, };

class Game_Manager
{
public:
	Game_Manager() = default;
	Game_Manager(int weidht, int height);
	virtual ~Game_Manager();

	void Run();
private:
	Table* _table = nullptr;
protected:
};