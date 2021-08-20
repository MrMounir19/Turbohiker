#include "menu.h"


Menu::Menu(float width, float height) {
	if (!font.loadFromFile("arial.ttf")) {
		// handle error
	}
	this->height = height;
	this->width = width;
	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));


	menu2[0].setFont(font);
	menu2[0].setColor(sf::Color::Red);
	menu2[0].setString("Play Again");
	menu2[0].setPosition(sf::Vector2f(width / 2, height / (6 + 1) * 5));

	menu2[1].setFont(font);
	menu2[1].setColor(sf::Color::White);
	menu2[1].setString("Exit");
	menu2[1].setPosition(sf::Vector2f(width / 2, height / (6 + 1) * 6));

	type = 0;
	selectedItemIndex = 0;
	activated = true;
}


Menu::~Menu() {

}

void Menu::draw(sf::RenderWindow &window) {
	if (type == 0) {
		for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
			window.draw(menu[i]);
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			window.draw(scores[i]);
		}
		for (int i = 0; i < 2; i++) {
			window.draw(menu2[i]);
		}
	}
}

void Menu::MoveUp() {
	if (type == 0) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex--;
		if (this->selectedItemIndex < 0) this->selectedItemIndex = 1;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
	else {
		menu2[selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex--;
		if (this->selectedItemIndex < 0) this->selectedItemIndex = 1;
		menu2[selectedItemIndex].setColor(sf::Color::Red);
	}
}


void Menu::MoveDown() {
	if (type == 0) {
		menu[selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex = (this->selectedItemIndex + 1) % 2;
		menu[selectedItemIndex].setColor(sf::Color::Red);
	}
	else {
		menu2[selectedItemIndex].setColor(sf::Color::White);
		this->selectedItemIndex = (this->selectedItemIndex + 1) % 2;
		menu2[selectedItemIndex].setColor(sf::Color::Red);
	}
}

void Menu::setScores(int playerScore, std::vector<int> AIScores) {
	AIScores.push_back(playerScore);
	std::sort(AIScores.begin(), AIScores.end());
	std::reverse(AIScores.begin(), AIScores.end());
	bool temp = true;
	for (int i = 0; i < AIScores.size(); i++) {
		scores[i].setFont(font);
		scores[i].setColor(sf::Color::White);
		scores[i].setPosition(sf::Vector2f(width / 2, height / (6 + 1) * (i+1)));
		if (AIScores[i] == playerScore and temp) {
			scores[i].setString(std::to_string(i+1)+". PLAYER: " + std::to_string(AIScores[i]));
			temp = false;
		}
		else {
			scores[i].setString(std::to_string(i+1)+". BOT: " + std::to_string(AIScores[i]));	
		}
	}
}

bool Menu::isActivated() {
	return activated;
}

void Menu::setActivated(bool activated) {
	this->activated = activated;
}

std::unique_ptr<Menu> MenuFactory::createMenu(float width, float height) {
    return std::make_unique<Menu>(width, height);
}

void Menu::setType(int type) {
	this->type = type;
}

void Menu::setIndex(int index) {
	this->selectedItemIndex = index;
}

int Menu::getType() {
	return this->type;
}
