#ifndef GAMESTATEBUILDER_H
#define GAMESTATEBUILDER_H

#include <QString>
#include "gamestate.h"
#include "dicts/wordproviderfactory.h"

class GameStateCreator
{
public:
    GameStateCreator();
    GameState* createGame(QString wordLength);

private:
    WordProviderFactory *wordProviderFactory;
    GameState* shortGame();
    GameState* mediumGame();
    GameState* longGame();
};

#endif // GAMESTATEBUILDER_H
