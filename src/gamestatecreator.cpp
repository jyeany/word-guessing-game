#include "gamestatecreator.h"

// ----- Constructors -----

GameStateCreator::GameStateCreator()
{
    this->wordProviderFactory = new WordProviderFactory();
}

// --- End Constructors ---


// ----- Public -----

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

// --- End Public ---


// ----- Private -----

GameState* GameStateCreator::shortGame()
{
    GameState *shortGame = new GameState();
    IWordProvider *wordProvider = this->wordProviderFactory->createWordProvider("Short");
    shortGame->setGamePhase(in_progress);
    shortGame->setSolutionWord(wordProvider->provideWord());
    shortGame->setNumWordGuesses(3);
    shortGame->setNumLetterGuesses(10);
    return shortGame;
}

GameState* GameStateCreator::mediumGame()
{
    GameState *mediumGame = new GameState();
    IWordProvider *wordProvider = this->wordProviderFactory->createWordProvider("Medium");
    mediumGame->setGamePhase(in_progress);
    mediumGame->setSolutionWord(wordProvider->provideWord());
    mediumGame->setNumWordGuesses(4);
    mediumGame->setNumLetterGuesses(12);
    return mediumGame;
}

GameState* GameStateCreator::longGame()
{
    GameState *longGame = new GameState();
    IWordProvider *wordProvider = this->wordProviderFactory->createWordProvider("Long");
    longGame->setGamePhase(in_progress);
    longGame->setSolutionWord(wordProvider->provideWord());
    longGame->setNumWordGuesses(5);
    longGame->setNumLetterGuesses(15);
    return longGame;
}

// --- End Private ---
