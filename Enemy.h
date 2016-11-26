#include <SFML/Graphics.hpp>
#include "Player.h"
class Enemy : public Player
{
    float predictedY; ///ta zmienna przechowuje Y przeciwnika, ktore zamierza on osiagnac
    float realPredictedY;
public:
    bool isPredicted;
    bool ballBounced;
    int bounces;
    Enemy(int=75, int=10, sf::Vector2f=sf::Vector2f(1356,347));
    bool Update(sf::RectangleShape, sf::RectangleShape, sf::CircleShape, sf::Vector2f);
    void AI(sf::CircleShape, sf::Vector2f);
    void Move(sf::CircleShape);
    void Draw(sf::RenderWindow&);
};
