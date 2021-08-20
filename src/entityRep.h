//TURBOHIKER::ENTITY REPRESENTATION

#ifndef ENTITYREP
#define ENTITYREP

#include <SFML/Graphics.hpp>
#include <memory>

class EntityRep {
    sf::Texture texture;
    sf::Sprite sprite;
    int animationCounter;
public:
    EntityRep(std::tuple<float,float> resRatio);
    virtual void initTexture();
    virtual void initSprite(std::tuple<float,float> resRatio);
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

class EntityRepFactory {
    public:
        virtual std::shared_ptr<EntityRep> createEntityRep(std::tuple<float,float> resRatio);
};

#endif