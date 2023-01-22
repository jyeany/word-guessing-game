
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../src/gamemanager.h"

using namespace testing;


TEST(WordGuessGameSuite, IncorrectLetterGuess)
{    
    GameManager *gameManager = new GameManager();
    int expLetterGuesses = gameManager->getLetterGuesses() - 1;
    gameManager->makeLetterGuess('Z');
    ASSERT_EQ(expLetterGuesses, gameManager->getLetterGuesses());
}

TEST(WordGuessGameSuite, IncorrectWordGuess)
{
    GameManager *gameManager = new GameManager();
    int expWordGuesses = gameManager->getWordGuesses() - 1;
    gameManager->makeWordGuess("Bogus");
    ASSERT_EQ(expWordGuesses, gameManager->getWordGuesses());
}

TEST(WordGuessGameSuite, CorrectWordGuess)
{
    GameManager *gameManager = new GameManager();
    QString theWord = "Winner";
    gameManager->setSolutionWord(theWord);
    gameManager->makeWordGuess(theWord);
    ASSERT_EQ(won, gameManager->getGamePhase());
}

TEST(WordGuessGameSuite, LossByLetterGuesses)
{
    GameManager *gameManager = new GameManager();
    gameManager->setLetterGuesses(0);
    gameManager->checkGameLoss();
    ASSERT_EQ(lost, gameManager->getGamePhase());
}

TEST(WordGuessGameSuite, LossByWordGuesses)
{
    GameManager *gameManager = new GameManager();
    gameManager->setWordGuesses(0);
    gameManager->checkGameLoss();
    ASSERT_EQ(lost, gameManager->getGamePhase());
}

TEST(LetterGuessGameSuite, WonEndMessage)
{
    GameManager *gameManager = new GameManager();
    gameManager->setGamePhase(won);
    QString msg = gameManager->endGameMessage();
    ASSERT_EQ(msg, "You Win!");
}

TEST(LetterGuessGameSuite, GuessedLetterFormat)
{
    GameManager *gameManager = new GameManager();
    gameManager->setGamePhase(in_progress);
    gameManager->setSolutionWord("HAT");
    gameManager->makeLetterGuess('G');
    gameManager->makeLetterGuess('B');
    gameManager->makeLetterGuess('Q');
    QString expected = "G B Q ";
    QString result = gameManager->getGuessedLetters();
    ASSERT_TRUE(result == expected);
}

TEST(LetterGuessGameSuite, WinByLettersGameInProgress)
{
    GameManager *gameManager = new GameManager();
    gameManager->setGamePhase(in_progress);
    gameManager->setSolutionWord("HAT");
    gameManager->makeLetterGuess('H');
    const GamePhase resultPhase = gameManager->getGamePhase();
    ASSERT_EQ(resultPhase, in_progress);
}

TEST(LetterGuessGameSuite, WinByLettersGameWon)
{
    GameManager *gameManager = new GameManager();
    gameManager->setGamePhase(in_progress);
    gameManager->setSolutionWord("HAT");
    gameManager->makeLetterGuess('H');
    gameManager->makeLetterGuess('A');
    gameManager->makeLetterGuess('T');
    const GamePhase resultMode = gameManager->getGamePhase();
    ASSERT_EQ(resultMode, won);
}

TEST(LetterGuessGameSuite, WinByLettersGameWonLowerCase)
{
    GameManager *gameManager = new GameManager();
    gameManager->setGamePhase(in_progress);
    gameManager->setSolutionWord("HAT");
    gameManager->makeLetterGuess('h');
    gameManager->makeLetterGuess('a');
    gameManager->makeLetterGuess('t');
    const GamePhase resultMode = gameManager->getGamePhase();
    ASSERT_EQ(resultMode, won);
}