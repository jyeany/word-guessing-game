#include "gamestate.h"

// ----- Constructors -----

GameState::GameState() {}

// --- End Constructors ---


// ----- Getters -----

QString GameState::getSolutionWord()
{
    return this->solutionWord;
}

QList<QChar> GameState::getSolutionLetters()
{
    return this->solutionLetters;
}

QList<QChar> GameState::getGuessedLetters()
{
    return this->guessedLetters;
}

int GameState::getNumLetterGuesses()
{
    return this->numLetterGuesses;
}

int GameState::getNumWordGuesses()
{
    return this->numWordGuesses;
}

// --- End Getters ---


// ----- Setters -----

void GameState::setSolutionWord(QString word)
{
    this->solutionWord = word.toUpper();
    this->populateSolutionLetters();
}

void GameState::setNumLetterGuesses(int guesses)
{
    this->numLetterGuesses = guesses;
}

void GameState::setNumWordGuesses(int guesses)
{
    this->numWordGuesses = guesses;
}

// --- End Setters ---


// ----- Private -----

void GameState::populateSolutionLetters()
{
    for (short i = 0; i < this->solutionWord.length(); ++i)
    {
        this->solutionLetters.append(this->solutionWord[i]);
    }
}

// --- End Private ---
