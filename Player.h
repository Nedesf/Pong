#include <SFML/Graphics.hpp>
class Player
{
protected:
    float speed;
    int Height;
    int Width;
    const float maxSpeed, minSpeed;
public:
    sf::RectangleShape rectangle;
    Player(int=75, int=10, sf::Vector2f=sf::Vector2f(0,347));
    virtual ~Player();
    void Draw(sf::RenderWindow &window);
    bool Update(sf::RectangleShape up, sf::RectangleShape down);
    void Move(sf::RectangleShape up, sf::RectangleShape down);
    void HandleInputs();
};
