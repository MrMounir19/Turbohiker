//TURBOHIKER::ENTITY REPRESENTATION

#ifndef ENTITYREP
#define ENTITYREP

#include <SFML/Graphics.hpp>

class EntityRep {
    sf::Texture texture;
    sf::Sprite sprite;
    int animationCounter;
public:
    EntityRep();
    virtual void initTexture();
    virtual void initSprite();
    void setTexture(std::string filename);
    void setSprite();
    void scaleSprite(float x, float y);
    void setPositionSprite(sf::Vector2f position);
    void setTextureRect(sf::IntRect rect);
    void move(float x, float y);
    void render(sf::RenderWindow& renderTarget);
    int getCounter();
    void addCounter(int amount);
    void moduloCounter(int modulo);
};

#endif