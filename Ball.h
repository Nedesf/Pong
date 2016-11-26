#include <SFML/Graphics.hpp>
class Ball
{
public:
    sf::Vector2f speed;
    sf::CircleShape circle;
    Ball();
    short Update(sf::RectangleShape, sf::RectangleShape, sf::RectangleShape, sf::RectangleShape, bool&, bool&);
    void Move();
    void isColliding(sf::RectangleShape, sf::RectangleShape, sf::RectangleShape, sf::RectangleShape, bool&, bool&);
    short isScore();
    void Bounce(bool);
    void Spawn(bool);
    void Draw(sf::RenderWindow &);
};
