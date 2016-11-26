#include "Enemy.h"
Enemy::Enemy(int h, int w, sf::Vector2f pos)
:Player::Player(h,w,pos)
{
    ballBounced=true;
    isPredicted=true;
    predictedY=-1;
    realPredictedY=0;
    bounces=0;
}
bool Enemy::Update(sf::RectangleShape up, sf::RectangleShape down, sf::CircleShape circle, sf::Vector2f speed)
{
    if(ballBounced||!isPredicted){AI(circle, speed);}
    Move(circle);
    Player::Move(up,down);
}
void Enemy::AI(sf::CircleShape circle, sf::Vector2f bspeed)
{
    float Ynormal=0;
    if(bspeed.x<0){bspeed.x-=bspeed.x*2;}
    if(bspeed.y<0){Ynormal=bspeed.y-bspeed.y*2;}
    bool up;
    float centerY=circle.getGlobalBounds().top+circle.getRadius();
    float centerX=circle.getGlobalBounds().left+circle.getRadius();
        float yIn;
    if(bspeed.y>=0){yIn=(763-centerY)/bspeed.y+1; up=true;}
    else{yIn=(centerY+5)/Ynormal+1; up=false;}
    float xIn=(1386-centerX)/bspeed.x+1;
    if (yIn>xIn&&ballBounced==false)
    {
    if (circle.getPosition().y+circle.getRadius()>rectangle.getPosition().y+Height/2||circle.getPosition().y+circle.getRadius()<rectangle.getPosition().y+Height/2)
    {
        predictedY=-1;
    }
    }
    else if (!isPredicted)
    {
    bounces=1;
    while(yIn<xIn)
    {
        bounces++;
        if (up){up=0;}
        else{up=1;}
        xIn-=yIn;
        if (bspeed.y>=0){yIn=(758/bspeed.y+1);}
        else{yIn=(758/Ynormal+1);}
    }
    if (bspeed.y>=0)
    {
    if (!up){realPredictedY=763-xIn*bspeed.y;}
    else{realPredictedY=(5+xIn)*bspeed.y;}
    }
    else
    {
    if (!up){realPredictedY=763-xIn*Ynormal;}
    else{realPredictedY=(5+xIn)*Ynormal;}
    }
    }
    else
    {
        bounces--;
        int minpx=5, maxpx=761;
        switch (bounces)
        {
            case 3:
            if (realPredictedY<=380)maxpx=380;
            else{minpx=380;maxpx=761;}
            break;
            case 2:
            for (int i=0; i<3; i++)
            {
                if (realPredictedY>=252*i+5&&realPredictedY<=252*i+252){minpx=252*i+5;maxpx=252*i+252;}
            }
            break;
            case 1:
            predictedY=realPredictedY;
            break;

        }
        srand(time(NULL));
            if(bounces>1){predictedY=rand()%(maxpx-minpx)+minpx;};
            ballBounced=false;
    }
    isPredicted=true;

}
void Enemy::Move(sf::CircleShape circle)
{
    if (predictedY!=-1)
    {

    if (predictedY>rectangle.getGlobalBounds().top+rectangle.getGlobalBounds().height)
    {
        speed++;
    }
    else if (predictedY<rectangle.getGlobalBounds().top)
    {
        speed--;
    }
    }
    else
    {
    if (circle.getGlobalBounds().top+circle.getGlobalBounds().height/2>rectangle.getGlobalBounds().top+rectangle.getGlobalBounds().height)
    {
        speed++;
    }
    else if (circle.getGlobalBounds().top+circle.getGlobalBounds().height/2<rectangle.getGlobalBounds().top)
    {
        speed--;
    }
    }
}
void Enemy::Draw(sf::RenderWindow &window)
{
    window.draw(rectangle);
}
