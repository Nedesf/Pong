#include "Ball.h"
#include "Enemy.h"
class Game
{
    sf::RenderWindow Window;
    Player player;
    Ball ball;
    Enemy enemy;
    static const sf::Time TimePerFrame;
public:
    sf::Font GameFont;
    sf::Text pScoreT;
    sf::Text eScoreT;
    sf::RectangleShape boundup, bounddown;
    int pScore, eScore;
    int Height;
    int Width;
    ////////////////
    Game(int=1366, int=768);
    virtual ~Game();
    void Run();
    void HandleInputs();
    bool Update();
    void Draw();
};
