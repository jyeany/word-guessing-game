#ifndef GAMESTATEBUILDER_H
#define GAMESTATEBUILDER_H

#include <QString>
#include "gamestate.h"

class GameStateCreator
{
public:
    GameStateCreator();
    GameState* createGame(QString wordLength);

private:
    GameState* shortGame();
    GameState* mediumGame();
    GameState* longGame();
};

#endif // GAMESTATEBUILDER_H
