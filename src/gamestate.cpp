#include "gamestate.h"

// ----- Constructors -----

GameState::GameState() {}

// --- End Constructors ---


// ----- Public -----

int GameState::decrementNumLetterGuesses()
{
    this->numLetterGuesses = this->numLetterGuesses - 1;
    return this->numLetterGuesses;
}

int GameState::decrementNumWordGuesses()
{
    this->numWordGuesses = this->numWordGuesses - 1;
    return this->numWordGuesses;
}

void GameState::addMissedLetter(QChar letter)
{
    this->missedLetters.append(letter.toUpper());
}

void GameState::addGuessedLetter(QChar letter)
{
    this->guessedLetters.append(letter.toUpper());
}

void GameState::addFoundLetter(QChar letter)
{
    this->foundLetters.append(letter.toUpper());
}

void GameState::addMissedWord(QString word)
{
    this->missedWords.append(word.toUpper());
}

// --- End Public ---


// ----- Private -----

void GameState::populateSolutionLetters()
{
    this->solutionLetters.clear();
    for (short i = 0; i < this->solutionWord.length(); ++i)
    {
        this->solutionLetters.append(this->solutionWord[i]);
    }
}

// --- End Private ---



// ----- Getters -----

GamePhase GameState::getGamePhase()
{
    return this->gamePhase;
}

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

QChar GameState::getCurrentLetterGuess()
{
    return this->currentLetterGuess;
}

QList<QChar> GameState::getFoundLetters()
{
    return this->foundLetters;
}

QList<QChar> GameState::getMissedLetters()
{
    return this->missedLetters;
}

QList<QString> GameState::getMissedWords()
{
    return this->missedWords;
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

void GameState::setGamePhase(GamePhase gamePhase)
{
    this->gamePhase = gamePhase;
}

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

void GameState::setCurrentLetterGuess(QChar letter)
{
    this->currentLetterGuess = letter.toUpper();
}

// --- End Setters ---
