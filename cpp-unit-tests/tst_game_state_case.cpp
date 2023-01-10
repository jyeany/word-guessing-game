
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../gamestate.h"

using namespace testing;


TEST(WordGuessGameSuite, IncorrectLetterGuess)
{    
    GameState *gameState = new GameState();
    int expLetterGuesses = gameState->getLetterGuesses() - 1;
    gameState->makeLetterGuess('Z');
    ASSERT_EQ(expLetterGuesses, gameState->getLetterGuesses());
}

TEST(WordGuessGameSuite, IncorrectWordGuess)
{
    GameState *gameState = new GameState();
    int expWordGuesses = gameState->getWordGuesses() - 1;
    gameState->makeWordGuess("Bogus");
    ASSERT_EQ(expWordGuesses, gameState->getWordGuesses());
}

TEST(WordGuessGameSuite, CorrectWordGuess)
{
    GameState *gameState = new GameState();
    QString theWord = "Winner";
    gameState->setChosenWord(theWord);
    gameState->makeWordGuess(theWord);
    ASSERT_EQ(won, gameState->getGameMode());
}

TEST(WordGuessGameSuite, LossByLetterGuesses)
{
    GameState *gameState = new GameState();
    gameState->setLetterGuesses(0);
    gameState->checkGameLoss();
    ASSERT_EQ(lost, gameState->getGameMode());
}

TEST(WordGuessGameSuite, LossByWordGuesses)
{
    GameState *gameState = new GameState();
    gameState->setWordGuesses(0);
    gameState->checkGameLoss();
    ASSERT_EQ(lost, gameState->getGameMode());
}
