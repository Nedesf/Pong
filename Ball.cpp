#include "Ball.h"
Ball::Ball()
{
    circle.setFillColor(sf::Color::White);
    circle.setRadius(10);
}
short Ball::Update(sf::RectangleShape up, sf::RectangleShape down, sf::RectangleShape player, sf::RectangleShape enemy, bool &isPredicted, bool &ballBounced)
{
    isColliding(up,down,player,enemy, isPredicted, ballBounced);
    Move();
    return isScore();
}
void Ball::Move()
{
    circle.move(speed);
}
void Ball::isColliding(sf::RectangleShape up, sf::RectangleShape down, sf::RectangleShape enemy, sf::RectangleShape player, bool &isPredicted, bool &ballBounced)
{
    sf::FloatRect u=up.getGlobalBounds();
    sf::FloatRect d=down.getGlobalBounds();
    sf::FloatRect e=enemy.getGlobalBounds();
    sf::FloatRect p=player.getGlobalBounds();
    sf::FloatRect c=circle.getGlobalBounds();
    if (c.intersects(u)||c.intersects(d))
    {
        Bounce(0);
        ballBounced=true;
    }
    if (c.intersects(p))
    {       ///|
            ///V ta zmienna przechowuje odleglosc miedzy srodkiem pilki a srodkiem paletki i dzieli ja przez 5
            ///a to dlatego, ze postanowilem wprowadzic mechanizm, ktory "odbija w boki" pilke, zeby gra miala wiekszy sens;
            ///w przypadku gdyby odbicie pilki zmienialoby tylko szybkosc na plaszczyznie X, byloby troche nudno :)
            ///a dziele akurat przez 5, poniewaz pilka za bardzo zmieniala y i musialem to zmniejszyc
        float help=(player.getPosition().y+player.getSize().y/2-circle.getPosition().y+circle.getRadius()/2)/5;
        Bounce(1);
        circle.move(sf::Vector2f(0.2,0)); ///<---- zabezpieczenie przed tym, zeby pilka nie odbila sie dwa razy z rzedu od paletki (tak, zdarzaly sie takie sytuacje)
        ///|
        ///V tutaj obracamy zmienna help tzn. roznice miedzy srodkiem paletki a srodkiem pilki, a to dlatego, ¿e player.getPosition().y
        ///i circle.getPosition().y daje nam pozycje wyrazona w pikselach, tzn. od lewego gornego rogu okna
        ///a metoda circle.move() przesuwa nam pilke patrz¹c od lewego dolnego rogu np. przesuniecie o 5x i 10y metoda move()
        ///przesuwa nasza pilke 5 pikseli w prawo i 10 pikseli do gory
        speed.y=help-help*2;
        speed.x+=1;
        isPredicted=false;
    }
    if (c.intersects(e))
    {   ///tutaj jest jak wy¿ej
        float help=(enemy.getPosition().y+enemy.getSize().y/2-circle.getPosition().y+circle.getRadius()/2)/5;
        Bounce(1);
        circle.move(sf::Vector2f(0.2,0));
        speed.y=help-help*2;
        speed.x+=1;
    }

}
short Ball::isScore()
{
    if (circle.getPosition().x+circle.getRadius()/2>1386)
    {
        return 1;
    }
    if (circle.getPosition().x+circle.getRadius()/2<-20)
    {
        return 2;
    }
}
void Ball::Bounce(bool x)
{
    if (!x){speed.y-=speed.y*2;}
    if (x){speed.x-=speed.x*2;}
}
void Ball::Spawn(bool playerside)
{
    circle.setPosition(678,379);
    if (playerside){speed=sf::Vector2f(-5,1);}
    else{speed=sf::Vector2f(5,1);}
}
void Ball::Draw(sf::RenderWindow &window)
{
    window.draw(circle);
}
