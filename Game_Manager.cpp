#include "Game_Manager.h"

Game_Manager::Game_Manager(int width, int height)
{
	srand(time(NULL));
	this->_table = new Table(width, height);
}

Game_Manager::~Game_Manager()
{
	if (this == nullptr)
		return;

	delete this->_table;
}

void Game_Manager::Run()
{
	while (!this->_table->End())
	{
		this->_table->Draw();
		this->_table->Input();
		this->_table->Logic();
	}
	
}