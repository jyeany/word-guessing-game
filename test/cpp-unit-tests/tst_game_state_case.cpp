
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/gamestate.h"

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

TEST(LetterGuessGameSuite, WonEndMessage)
{
    GameState *gameState = new GameState();
    gameState->setGameMode(won);
    QString msg = gameState->endGameMessage();
    ASSERT_EQ(msg, "You Win!");
}

TEST(LetterGuessGameSuite, GuessedLetterFormat)
{
    GameState *gameState = new GameState();
    gameState->setGameMode(in_progress);
    gameState->setChosenWord("HAT");
    gameState->makeLetterGuess('G');
    gameState->makeLetterGuess('B');
    gameState->makeLetterGuess('Q');
    QString expected = "G B Q ";
    QString result = gameState->getGuessedLetters();
    ASSERT_TRUE(result == expected);
}

TEST(LetterGuessGameSuite, WinByLettersGameInProgress)
{
    GameState *gameState = new GameState();
    gameState->setGameMode(in_progress);
    gameState->setChosenWord("HAT");
    gameState->makeLetterGuess('H');
    const GameMode resultMode = gameState->getGameMode();
    ASSERT_EQ(resultMode, in_progress);
}

TEST(LetterGuessGameSuite, WinByLettersGameWon)
{
    GameState *gameState = new GameState();
    gameState->setGameMode(in_progress);
    gameState->setChosenWord("HAT");
    gameState->makeLetterGuess('H');
    gameState->makeLetterGuess('A');
    gameState->makeLetterGuess('T');
    const GameMode resultMode = gameState->getGameMode();
    ASSERT_EQ(resultMode, won);
}

TEST(LetterGuessGameSuite, WinByLettersGameWonLowerCase)
{
    GameState *gameState = new GameState();
    gameState->setGameMode(in_progress);
    gameState->setChosenWord("HAT");
    gameState->makeLetterGuess('h');
    gameState->makeLetterGuess('a');
    gameState->makeLetterGuess('t');
    const GameMode resultMode = gameState->getGameMode();
    ASSERT_EQ(resultMode, won);
}
