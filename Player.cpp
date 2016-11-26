#include "Game.h"
Player::Player(int h, int w, sf::Vector2f pos)
:maxSpeed(20), minSpeed(-20)
{

    Height = h;
    Width = w;
    rectangle.setSize(sf::Vector2f(Width,Height));
    rectangle.setPosition(pos);
    speed=0;
}
void Player::Draw(sf::RenderWindow &window)
{
    window.draw(Player::rectangle);
}
bool Player::Update(sf::RectangleShape up, sf::RectangleShape down)
{
   HandleInputs();
   Move(up,down);
}
void Player::Move(sf::RectangleShape up, sf::RectangleShape down)
{
    sf::FloatRect fr=rectangle.getGlobalBounds(), u=up.getGlobalBounds(), d=down.getGlobalBounds();
    if (speed<0&&!(fr.intersects(u))){rectangle.move(sf::Vector2f(0,speed));}
    if (speed>0&&!(fr.intersects(d))){rectangle.move(sf::Vector2f(0,speed));}
    if (speed>0.5||speed<-0.5){speed*=0.7;}
    else{speed=0;}
}
void Player::HandleInputs()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (speed>minSpeed)
        {
            speed-=1;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (speed<maxSpeed)
        {
            speed+=1;
        }
    }
}
Player::~Player()
{
    ;
}
