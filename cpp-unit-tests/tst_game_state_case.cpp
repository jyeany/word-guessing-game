
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../gamestate.h"

using namespace testing;


TEST(WORD_GUESS_GAME_SUITE, GAME_STATE_CASE)
{
    EXPECT_EQ(1, 1);
    ASSERT_THAT(0, Eq(0));
}

TEST(WORD_GUESS_GAME_SUITE, INCORRECT_LETTER_CASE)
{
    GameState *gameState = new GameState();
    int expLetterGuesses = gameState->getLetterGuesses() - 1;
    gameState->makeLetterGuess('Z');
    ASSERT_EQ(expLetterGuesses, gameState->getLetterGuesses());
}

