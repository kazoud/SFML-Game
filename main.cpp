#pragma once
#include "Game.h"
#include "ResourceHolder.h"
#include "ResourceHolder.inl"
int main()
{
	try
	{
		Game game;
		game.run();
	}

	catch (std::exception& e)
	{
		std::cout << "\nEXCEPTION: " << e.what() << std::endl;
	}

	return 0;
}