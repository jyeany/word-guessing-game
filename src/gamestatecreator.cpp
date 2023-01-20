#include "gamestatecreator.h"

GameStateCreator::GameStateCreator() {}

GameState* GameStateCreator::createGame(QString userChoice)
{
    GameState *gameState;
    if (userChoice == "Short")
    {
        gameState = this->shortGame();
    }
    else if (userChoice == "Medium")
    {
        gameState = this->mediumGame();
    }
    else
    {
        gameState = this->longGame();
    }
    return gameState;
}

GameState* GameStateCreator::shortGame()
{
    GameState *shortGame = new GameState();
    return shortGame;
}

GameState* GameStateCreator::mediumGame()
{
    GameState *mediumGame = new GameState();
    return mediumGame;
}

GameState* GameStateCreator::longGame()
{
    GameState *longGame = new GameState();
    return longGame;
}
