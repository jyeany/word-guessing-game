
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../gamestate.h"

using namespace testing;


TEST(WordGuessGameSuite, FirstCase)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(WordGuessGameSuite, IncorrectLetterCase)
{
    GameState *gameState = new GameState();
    int expLetterGuesses = gameState->getLetterGuesses() - 1;
    gameState->makeLetterGuess('Z');
    ASSERT_EQ(expLetterGuesses, gameState->getLetterGuesses());
}

