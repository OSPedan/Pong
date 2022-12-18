#pragma once
#include <time.h>
#include <conio.h>
#include <thread>
#include <chrono>

#include "Ball.h"
#include "Plaers.h"
#include "Bot.h"

class Table 
{
public:
	Table() = default;
	Table(int width, int height);
	virtual ~Table();
	
	virtual void UP_Score(Plaers* racket);
	void Draw();
	void Logic();
	void Input();
	bool End();

	void Moving_Bot(Bot& bot);
private:
	Ball* _ball = nullptr;
	Plaers* _plaer_1 = nullptr;
	Bot* _plaer_2 = nullptr;

	int _width;
	int _height;
	bool _quit;
protected:
};
