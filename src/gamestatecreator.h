#ifndef GAMESTATEBUILDER_H
#define GAMESTATEBUILDER_H

#include <QString>
#include "gamestate.h"

class GameStateCreator
{
public:
    GameStateCreator();
    GameState* createGame(QString userChoice);

private:
    GameState* shortGame();
    GameState* mediumGame();
    GameState* longGame();
};

#endif // GAMESTATEBUILDER_H
