#include "Game.h"
const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);
Game::Game(int x, int y)
{
    ball.Spawn(true);
    boundup.setSize(sf::Vector2f(1366,5));
    bounddown.setSize(sf::Vector2f(1366,5)); bounddown.setPosition(sf::Vector2f(0,763));
    Height=x;
    Width=y;
    pScore=0;
    eScore=0;
    Window.create(sf::VideoMode(Width, Height, 32),"Pong!", sf::Style::Fullscreen);
    Window.setFramerateLimit(60);
    GameFont.loadFromFile("consolab.ttf");
    pScoreT.setFont(GameFont); pScoreT.setPosition(60,20); pScoreT.setCharacterSize(80); pScoreT.setString("0");
    eScoreT.setFont(GameFont); eScoreT.setPosition(1246,20); eScoreT.setCharacterSize(80); eScoreT.setString("0");
}
void Game::Run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time delta;
    while (Window.isOpen())
    {
        delta=clock.restart();
        timeSinceLastUpdate+=delta;
        while (timeSinceLastUpdate > Game::TimePerFrame)
        {
            timeSinceLastUpdate-=Game::TimePerFrame;
            Update();
        }
        Draw();
    }
}
void Game::HandleInputs()
{
    sf::Event event;
    while (Window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
        {
            Window.close();
        }
    }
    player.HandleInputs();
}
bool Game::Update()
{
    HandleInputs();
    player.Update(boundup, bounddown);
    short score=ball.Update(boundup,bounddown,enemy.rectangle,player.rectangle, enemy.isPredicted, enemy.ballBounced);
    enemy.Update(boundup,bounddown,ball.circle, ball.speed);
    if (score==1)
    {
    std::string *help=new std::string;
    enemy.isPredicted=false;
    pScore++;
    ball.Spawn(1);
        help[0]=pScore%10+48;
        if (pScore>=10){help[1]=pScore/10+48;}
    pScoreT.setString(*help);
    delete help;
    }
    else if (score==2)
    {
    std::string *help=new std::string;
    enemy.isPredicted=false;
    eScore++;
    ball.Spawn(0);
            help[0]=eScore%10+48;
        if (eScore>=10){help[1]=eScore/10+48;}
    eScoreT.setString(*help);
    delete help;
    }
}
void Game::Draw()
{
    Window.clear();
    player.Draw(Window);
    Window.draw(boundup);
    Window.draw(bounddown);
    Window.draw(pScoreT);
    Window.draw(eScoreT);
    ball.Draw(Window);
    enemy.Draw(Window);
    Window.display();
}
Game::~Game()
{
    ;
}
