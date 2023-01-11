#include "gamestate.h"

GameState::GameState(QObject *parent)
    : QObject{parent}
{
    this->m_chosenWord = "Cat";
    this->m_gameMode = in_progress;
    this->m_letterGuesses = 5;
    this->m_wordGuesses = 2;
}

QString GameState::getChosenWord()
{
    return this->m_chosenWord;
}

void GameState::setChosenWord(QString word)
{
    this->m_chosenWord = word;
}

GameMode GameState::getGameMode()
{
    return this->m_gameMode;
}

bool GameState::makeLetterGuess(QChar letter)
{
    bool found = this->m_chosenWord.contains(letter);
    if (!found)
    {
        this->m_letterGuesses--;
        checkGameLoss();
    }
    return found;
}

bool GameState::makeWordGuess(QString guess)
{
    if (this->m_chosenWord == guess)
    {
        this->m_gameMode = won;
        return true;
    }
    else
    {
        this->m_wordGuesses--;
        checkGameLoss();
        return false;
    }
}

void GameState::checkGameLoss()
{
    if (this->m_wordGuesses == 0 || this->m_letterGuesses == 0)
    {
        this->m_gameMode = lost;
    }
}

int GameState::getWordGuesses()
{
    return this->m_wordGuesses;
}

void GameState::setWordGuesses(int guesses)
{
    this->m_wordGuesses = guesses;
}

int GameState::getLetterGuesses()
{
    return this->m_letterGuesses;
}

void GameState::setLetterGuesses(int guesses)
{
    this->m_letterGuesses = guesses;
}