#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
	if (!MenuF.loadFromFile("vermin_vibes_1989"))
	{
		return EXIT_FAILURE;
	}

	MenuT[0].setFont(MenuF);
	MenuT[0].setColor(sf::Color::Blue);
	MenuT[0].setString("Play");
	MenuT[0].setPosition(300, 210);

	MenuT[1].setFont(MenuF);
	MenuT[1].setColor(sf::Color::Red);
	MenuT[1].setString("Exit");
	MenuT[1].setPosition(300, 110);
}


ScreenManager::~ScreenManager()
{
}

void ScreenManager::MoveUp()
{
}

