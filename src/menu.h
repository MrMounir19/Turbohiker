

#ifndef MENU
#define MENU

#include "SFML/Graphics.hpp"

#define MAX_NUMBER_OF_ITEMS 3
class Menu
{
public:
	Menu(float width, float height);
	~Menu();
    
    bool isActivated();
    void setActivated(bool activated);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int GetPressedItem() { return selectedItemIndex; }

private:
    bool activated;
	int selectedItemIndex;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];

};

#endif

