

#ifndef MENU
#define MENU

#include "SFML/Graphics.hpp"
#include <vector>
#include <algorithm>
#define MAX_NUMBER_OF_ITEMS 2
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
	void setType(int type);
	int getType();
	void setIndex(int index);
	void setScores(int playerScore, std::vector<int> AIScores);

private:
	float width;
	float height;
    bool activated;
	int selectedItemIndex;
	int type;
	sf::Font font;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	sf::Text scores[4];
	sf::Text menu2[2];
};

class MenuFactory {
    public:
        virtual std::unique_ptr<Menu> createMenu(float width, float height);
};


#endif

