#include <iostream>
#include <fstream>
#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "unlocks.h"
#include "BoundingBoxes.h"

int main()
{
#include "characters.h"
#include "levels.h"

	int Level_Selection = 0;
	bool Level_Selection_Repeat = 0;
	int Character1_Selection = 5;
	bool Character1_Selection_Repeat = 0;
	int Character2_Selection = 8;
	bool Character2_Selection_Repeat = 0;

	sf::Vector2f Ground_Size(0, 0);
	sf::Vector2f Ground_Origin(0, 0);

	sf::Vector2f Character1_Origin(0, 0);

	sf::Vector2f Character2_Origin(0, 0);

	getCharacterUnlocks;
	getLevelUnlocks;

	sf::RenderWindow Game(sf::VideoMode(800, 640), "The Rise of Donald", sf::Style::Default);
	sf::Event command;
	//character selection
#include "Character1_Selection.h"
#include "Character2_Selection.h"
	//level selection
#include "Level_Selection.h"
	//Movement
	enum movement { standright, standleft, jump, fall, moveleft, moveright, jableft, jabright, upsmash, downsmashleft, downsmashright, smashleft, smashright, specnu, specup, specdown, specleft, specright };
	sf::Vector2f Character1_Movement(0, 0);
	bool Character1IsJumping = 0;
	bool Character1IsRight = 1;
	bool Character1Up = 0;
	bool Character1Down = 0;
	bool Character1Left = 0;
	bool Character1Right = 0;
	sf::Clock Character1_MovementClock;
	float Character1_MovementTimer = 0;

	sf::Vector2f Character2_Movement(0, 0);
	bool Character2IsJumping = 0;
	bool Character2IsRight = 0;
	bool Character2Up = 0;
	bool Character2Down = 0;
	bool Character2Left = 0;
	bool Character2Right = 0;
	sf::Clock Character2_MovementClock;
	float Character2_MovementTimer = 0;
	//Attacks
	bool Character1AttackKeyIsPressed = 0;
	bool Character1IsAttacking = 0;
	bool Character2AttackKeyIsPressed = 0;
	bool Character2IsAttacking = 0;
	//Physics
	sf::Clock Character1_PhysicsClock;
	float Character1_PhysicsTimer = 0;

	sf::Clock Character2_PhysicsClock;
	float Character2_PhysicsTimer = 0;
	//Animation
	sf::Vector2i Character1_Anime(0, 0);
	sf::IntRect Character1_AnimeRect;
	int Character1_AnimeSize = 672;

	sf::Vector2i Character2_Anime(0, 0);
	sf::IntRect Character2_AnimeRect;
	int Character2_AnimeSize = 672;

	sf::Clock AnimeClock;
	float AnimeCounter = 0;
	float AnimeSpeed = 1000;
	float AnimeSwitch = 100;
	//Kill Zones
	sf::Vector2i SafeZone_Origin(0, 0);
	BoundingBox SafeZone(sf::Vector2f(-96, 0), sf::Vector2f(992, 640), sf::Color(0, 255, 0));
	//HitBoxes
	BoundingBox Character1_HB(sf::Vector2f(Character1_Origin), sf::Vector2f(25, 10), sf::Color(255, 255, 255));
	sf::Clock Character1_HitClock;
	float Character1_HitTimer = 0;
	bool Character1IsHit = 0;
	sf::Vector2f Character1_HitMulti(2, -2);
	float Character1_HBHeight = 48;

	BoundingBox Character2_HB(sf::Vector2f(Character2_Origin), sf::Vector2f(25, 10), sf::Color(255, 255, 255));
	sf::Clock Character2_HitClock;
	float Character2_HitTimer = 0;
	bool Character2IsHit = 0;
	sf::Vector2f Character2_HitMulti(2, -2);
	float Character2_HBHeight = 48;
	//BoundingBoxes
	BoundingBox Ground(Ground_Origin, Ground_Size, sf::Color(0, 0, 0));
	bool Character1_GroundCollision = 0, Character2_GroundCollision = 0;

	BoundingBox Character1(sf::Vector2f(Character1_Origin), sf::Vector2f(96, 96), sf::Color(0, 0, 255));

	BoundingBox Character2(sf::Vector2f(Character2_Origin), sf::Vector2f(96, 96), sf::Color(255, 0, 255));
	//Score
	int Character1_Score = 0;
	int Character2_Score = 0;
	//Game Loop
	Character1_Sprite.setPosition(sf::Vector2f(Character1_Origin));
	Character2_Sprite.setPosition(sf::Vector2f(Character2_Origin));
	while (Game.isOpen())
	{//Game Loop Begin
		while (Game.pollEvent(command))
		{//Event Loop Begin
			switch (command.type)
			{
			case (sf::Event::Closed) :
				Game.close();
				break;
			}
			//Control Input & movement
			Game.setKeyRepeatEnabled(false);
			//Character1
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				if (!Character1IsAttacking)
				{
					if (!Character1IsJumping)
					{
						Character1_Anime.y = jump;
						Character1IsJumping = true;
						Character1_Movement.y = -3;
					}
				}
				Character1Up = 1;
				if (Character1_Movement.y == 0)
				{
					if (Character1IsRight)
					{
						Character1_Anime.y = standright;
					}
					else
					{
						Character1_Anime.y = standleft;
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				Character1Down = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				if (!Character1IsAttacking)
				{
					Character1_Anime.y = moveleft;
					Character1_Movement.x = -1;
				}
				Character1Left = 1;
				Character1IsRight = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				if (!Character1IsAttacking)
				{
					Character1_Anime.y = moveright;
					Character1_Movement.x = 1;
				}
				Character1Right = 1;
				Character1IsRight = 1;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && Character1Left)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = jableft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && Character1IsRight)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = jabright;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && Character1Up)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = upsmash;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Character1Down && Character1Left)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = downsmashleft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && Character1Down && Character1Right)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = downsmashright;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && Character1Left)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = smashleft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) && Character1IsRight)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = smashright;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = specnu;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && Character1IsJumping)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = specup;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && Character1Down)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = specdown;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && Character1Left)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = specleft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y) && Character1Right)
			{
				Character1IsAttacking = true;
				Character1_Anime.x = 0;
				Character1_Anime.y = specright;
			}
			else
			{
				Character1_Movement.x = 0;
				if (Character1IsAttacking)
				{
					Character1_Movement.x = 0;
				}
				if (Character1IsRight)
				{
					Character1_Anime.y = standright;
				}
				else
				{
					Character1_Anime.y = standleft;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::T) || sf::Keyboard::isKeyPressed(sf::Keyboard::Y))
			{
				Character1AttackKeyIsPressed = true;
			}
			else
			{
				Character1AttackKeyIsPressed = false;
			}

			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			{
				Character1Up = 0;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			{
				Character1Down = 0;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			{
				Character1Left = 0;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			{
				Character1Right = 0;
			}
			//Character2
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				if (!Character2IsAttacking)
				{
					if (!Character2IsJumping)
					{
						Character2_Anime.y = jump;
						Character2IsJumping = true;
						Character2_Movement.y = -3;
					}
				}
				Character2Up = 1;
				if (Character2_Movement.y == 0)
				{
					if (Character2IsRight)
					{
						Character2_Anime.y = standright;
					}
					else
					{
						Character2_Anime.y = standleft;
					}
				}
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				Character2Down = 1;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				if (!Character2IsAttacking)
				{
					Character2_Anime.y = moveleft;
					Character2_Movement.x = -1;
				}
				Character2Left = 1;
				Character2IsRight = 0;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				if (!Character2IsAttacking)
				{
					Character2_Anime.y = moveright;
					Character2_Movement.x = 1;
				}
				Character2Right = 1;
				Character2IsRight = 1;

			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Left)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = jableft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Right)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = jabright;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Up)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = upsmash;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Down && Character2Left)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = downsmashleft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Down && Character2Right)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = downsmashright;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Left)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = smashleft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) && Character2Right)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = smashright;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = specnu;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Character2IsJumping)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = specup;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Character2Down)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = specdown;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Character2Left)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = specleft;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K) && Character2Right)
			{
				Character2IsAttacking = true;
				Character2_Anime.x = 0;
				Character2_Anime.y = specright;
			}
			else
			{
				Character2_Movement.x = 0;
				if (Character2IsAttacking)
				{
					Character2_Movement.x = 0;
				}
				if (Character2IsRight)
				{
					Character2_Anime.y = standright;
				}
				else
				{
					Character2_Anime.y = standleft;
				}
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::J) || sf::Keyboard::isKeyPressed(sf::Keyboard::K))
			{
				Character2AttackKeyIsPressed = true;
			}
			else
			{
				Character2AttackKeyIsPressed = false;
			}

			if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				Character2Up = 0;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				Character2Down = 0;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				Character2Left = 0;
			}
			else if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				Character2Right = 0;
			}
			//End of Control Input & movement
		}//Event Loop End
		//Movement
		if (Character1IsAttacking && !Character1AttackKeyIsPressed)
		{
			Character1IsAttacking = false;
		}
		if (Character1IsAttacking)
		{
			Character1_Movement = sf::Vector2f(0, 0);
		}
		Character1_MovementTimer += Character1_MovementClock.getElapsedTime().asSeconds();
		if (Character1_MovementTimer >= 0.10f)
		{
			Character1_MovementTimer = 0;
			if (Character1IsAttacking)
			{
				Character1_Movement = sf::Vector2f(0, 0);
			}
			Character1_Sprite.move(sf::Vector2f(Character1_Movement));
		}

		if (Character2IsAttacking && !Character2AttackKeyIsPressed)
		{
			Character2IsAttacking = false;
		}
		if (Character2IsAttacking)
		{
			Character2_Movement = sf::Vector2f(0, 0);
		}
		Character2_MovementTimer += Character2_MovementClock.getElapsedTime().asSeconds();
		if (Character2_MovementTimer >= 0.10f)
		{
			Character2_MovementTimer = 0;
			if (Character2IsAttacking)
			{
				Character2_Movement = sf::Vector2f(0, 0);
			}
			Character2_Sprite.move(sf::Vector2f(Character2_Movement));
		}
		//Physics
		//Character1
		Character1_PhysicsTimer += Character1_PhysicsClock.restart().asSeconds();
		if (!Character1.Collision(Ground) || Character1_Movement.y < 0)
		{
			if (Character1_PhysicsTimer >= 0.1f)
			{
				Character1_Movement.y += 1.0f;
				Character1_PhysicsTimer = 0;
			}
		}
		else
		{
			Character1_Movement.y = 0;
			Character1IsJumping = false;
		}

		if (Character1IsHit)
		{
			Character1_Movement = sf::Vector2f(Character1_HitMulti);
		}
		//Character2
		Character2_PhysicsTimer += Character2_PhysicsClock.restart().asSeconds();
		if (!Character2.Collision(Ground) || Character2_Movement.y < 0)
		{
			if (Character2_PhysicsTimer >= 0.1f)
			{
				Character2_Movement.y += 1.0f;
				Character2_PhysicsTimer = 0;
			}
		}
		else
		{
			Character2_Movement.y = 0;
			Character2IsJumping = false;
		}
		if (Character2IsHit)
		{
			Character2_Movement = sf::Vector2f(Character2_HitMulti);
		}
		//killzones
		SafeZone.update();
		if (!Character2.Collision(SafeZone))
		{
			std::cout << "Player 1 Score : " << Character1_Score << std::endl;
			Character1_Score++;
			Character2_Sprite.setPosition(sf::Vector2f(Character2_Origin));
			Character2_Movement = sf::Vector2f(0, 0);
		}

		if (!Character1.Collision(SafeZone))
		{
			std::cout << "Player 2 Score : " << Character1_Score << std::endl;
			Character2_Score++;
			Character1_Sprite.setPosition(sf::Vector2f(Character1_Origin));
			Character1_Movement = sf::Vector2f(0, 0);
		}
		//HitBoxes
		//Character1
		Character2_HB.update();

		if (Character1_HB.Collision(Character2) && Character1IsAttacking)
		{
			Character2IsHit = true;
			Character2_HitClock.restart();
			Character2_HitTimer = 0;
			if (Character1IsRight)
			{
				Character1_HitMulti.x = abs(Character1_HitMulti.x);
			}
			else if (!Character1IsRight)
			{
				Character1_HitMulti.x *= -1.0f;
			}
		}
		Character2_HitTimer += Character1_HitClock.restart().asSeconds();
		if (Character2_HitTimer > 0.10f && Character2IsHit)
		{
			Character2IsHit = false;
			Character2_HitTimer = 0;
		}

		if (!Character1IsRight)
		{
			Character1_HB.rect.setPosition(Character1_Sprite.getPosition() + sf::Vector2f(0, (Character2_HBHeight - Character2_HB.rect.getSize().y)));
		}
		else if (Character1IsRight)
		{
			Character1_HB.rect.setPosition(Character1_Sprite.getPosition() + sf::Vector2f(71, (Character2_HBHeight - Character2_HB.rect.getSize().y)));
		}
		//Character 2
		Character1_HB.update();

		if (Character2_HB.Collision(Character1) && Character2IsAttacking)
		{
			Character1IsHit = true;
			Character1_HitClock.restart();
			Character1_HitTimer = 0;
			if (Character1IsRight)
			{
				Character1_HitMulti.x = abs(Character1_HitMulti.x);
			}
			else if (!Character1IsRight)
			{
				Character1_HitMulti.x *= -1.0f;
			}
		}
		Character1_HitTimer += Character2_HitClock.restart().asSeconds();
		if (Character1_HitTimer >= 0.10f && Character1IsHit)
		{
			Character1_HitTimer = 0;
			Character1IsHit = false;
		}

		if (!Character2IsRight)
		{
			Character2_HB.rect.setPosition(Character2_Sprite.getPosition() + sf::Vector2f(0, (Character2_HBHeight - Character2_HB.rect.getSize().y)));
		}
		else if (Character2IsRight)
		{
			Character2_HB.rect.setPosition(Character2_Sprite.getPosition() + sf::Vector2f(71, (Character2_HBHeight - Character2_HB.rect.getSize().y)));
		}
		//Bounding Boxes
		Ground.update();

		Character1.update();
		Character1.rect.setPosition(Character1_Sprite.getPosition());

		Character2.update();
		Character2.rect.setPosition(Character2_Sprite.getPosition());
		//Animation
		AnimeCounter += AnimeSpeed * AnimeClock.restart().asSeconds();
		if (AnimeCounter >= AnimeSwitch)
		{
			AnimeCounter = 0;

			Character1_Anime.x++;
			if (Character1_Anime.x * 96 >= Character1_AnimeSize)
			{
				Character1_Anime.x = 0;
			}

			Character2_Anime.x++;
			if (Character2_Anime.x * 96 >= Character2_AnimeSize)
			{
				Character2_Anime.x = 0;
			}
		}
		Character1_Sprite.setTextureRect(sf::IntRect(Character1_Anime.x * 96, Character1_Anime.y * 96, 96, 96));

		Character2_Sprite.setTextureRect(sf::IntRect(Character2_Anime.x * 96, Character2_Anime.y * 96, 96, 96));
		//Score

		//drawing bounding boxes
		Game.draw(SafeZone.rect);
		Game.draw(Ground.rect);
		Game.draw(Character1.rect);
		Game.draw(Character2.rect);
		//drawing Hit Boxes
		Game.draw(Character1_HB.rect);
		Game.draw(Character2_HB.rect);
		//Drawing textures
		Game.draw(LevelBackground_Sprite);
		Game.draw(Level_Sprite);
		Game.draw(Character1_Sprite);
		Game.draw(Character2_Sprite);
		//Display
		Game.display();
	}//Game Loop End

	return 0;
}