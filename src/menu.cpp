#include "menu.h"


Menu::Menu(float width, float height) {
	if (!font.loadFromFile("arial.ttf")) {
		// handle error
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	selectedItemIndex = 0;
	activated = true;
}


Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp() {
	menu[selectedItemIndex].setColor(sf::Color::White);
	this->selectedItemIndex--;
	if (this->selectedItemIndex < 0) this->selectedItemIndex = 2;
	menu[selectedItemIndex].setColor(sf::Color::Red);
}


void Menu::MoveDown() {
	menu[selectedItemIndex].setColor(sf::Color::White);
	this->selectedItemIndex = (this->selectedItemIndex + 1) % 3;
	menu[selectedItemIndex].setColor(sf::Color::Red);
}

bool Menu::isActivated() {
	return activated;
}

void Menu::setActivated(bool activated) {
	this->activated = activated;
}
