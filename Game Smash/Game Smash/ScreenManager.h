#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#define ITEMID 2;

class ScreenManager
{
public:
	ScreenManager();
	~ScreenManager();

	void Draw(sf::RenderWindow Game);
	void MoveUp();
	void MoveDown();

private:
	int selectedItem;

	sf::Font MenuF;
	sf::Text MenuT[ITEMID];
	sf::Music MenuM;
	sf::Sound MenuS;
};
