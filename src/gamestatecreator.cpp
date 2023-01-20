#include "gamestatecreator.h"

GameStateCreator::GameStateCreator() {}

GameState* GameStateCreator::createGame(QString wordLength)
{
    GameState *gameState;
    if (wordLength == "Short")
    {
        gameState = this->shortGame();
    }
    else if (wordLength == "Medium")
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
    shortGame->setSolutionWord("CAT");
    shortGame->setNumWordGuesses(3);
    shortGame->setNumLetterGuesses(10);
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
