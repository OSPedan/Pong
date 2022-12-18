#include "Table.h"

Table::Table(int width, int height)
{
	this->_width = width;
	this->_height = height;
	this->_quit = false;

	this->_ball = new Ball(width / 2, height / 2);

	this->_plaer_1 = new Plaers(1, height / 2 - 3);
	this->_plaer_2 = new Bot(width - 2, height / 2 - 3);
}

Table::~Table()
{
	if (this == nullptr)
		return;

	delete this->_ball;
	delete this->_plaer_1;
	delete this->_plaer_2;
}

void Table::UP_Score(Plaers* plaer)
{
	if (plaer == this->_plaer_1)
		this->_plaer_1->Up_Score();
	else if (plaer == this->_plaer_2)
		this->_plaer_2->Up_Score();

	this->_ball->Reset();
	this->_plaer_1->Reset();
	this->_plaer_2->Reset();
}

void Table::Draw()
{
	system("cls");

	for (int i = 0; i < this->_width + 2; ++i)
	{
		std::cout << "\xB2";
	}
	std::cout << std::endl;

	for (int i = 0; i < this->_height; ++i)
	{
		for (int j = 0; j < this->_width; ++j)
		{
			if (j == 0)
				std::cout << "\xB2";

			if (this->_ball->Get_X() == j && this->_ball->Get_Y() == i)
				std::cout << "O";
			else if (this->_plaer_1->Get_X() == j && this->_plaer_1->Get_Y() == i)
				std::cout << "\xDB";
			else if (this->_plaer_2->Get_X() == j && this->_plaer_2->Get_Y() == i)
				std::cout << "\xDB";
			else
				std::cout << " ";

			if (j == this->_width - 1)
				std::cout << "\xB2";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < this->_width + 2; ++i)
	{
		std::cout << "\xB2";
	}
	std::cout << std::endl;

	std::cout << "Score plaer 1 " << this->_plaer_1->Get_Score() << std::endl;
	std::cout << "Score plaer 2 " << this->_plaer_2->Get_Score() << std::endl;

	std::this_thread::sleep_for(std::chrono::microseconds(15000));
}

void Table::Input()
{
	this->_ball->Move();

	this->Moving_Bot(*this->_plaer_2);

	if (_kbhit())
	{
		char current = _getch();

		if (this->_ball->Get_Dir() == eDir::STOP)
			this->_ball->Rand_Dir();

		this->_plaer_1->Move(current, this->_height);

		if (current == 'q')
			 this->_quit = true;
	}
}

void Table::Logic()
{
	if (this->_ball->Get_X() == (this->_plaer_1->Get_X() + 1) && this->_ball->Get_Y() == this->_plaer_1->Get_Y())
		this->_ball->Change_Dir(static_cast<eDir>((rand() % 3) + 4));

	if (this->_ball->Get_X() == this->_plaer_2->Get_X() - 1 && this->_ball->Get_Y() == this->_plaer_2->Get_Y())
		this->_ball->Change_Dir(static_cast<eDir>((rand() % 3) + 1));

	if (this->_ball->Get_Y() == this->_height - 1)
		this->_ball->Change_Dir(this->_ball->Get_Dir() == eDir::DOWNRIGHT ? eDir::UPRIGHT : eDir::UPLEFT);

	if (this->_ball->Get_Y() == 0)
		this->_ball->Change_Dir(this->_ball->Get_Dir() == eDir::UPRIGHT ? eDir::DOWNRIGHT : eDir::DOWNLEFT);

	if (this->_ball->Get_X() == this->_width - 1)
		this->UP_Score(this->_plaer_1);
	if (this->_ball->Get_X() == 0)
		this->UP_Score(this->_plaer_2);
}

bool Table::End()
{
	return this->_quit;
}

void Table::Moving_Bot(Bot& obj)
{
	obj.Move(*this->_ball);
}