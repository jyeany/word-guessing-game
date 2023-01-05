#include "gamestate.h"

GameState::GameState(QObject *parent)
    : QObject{parent}
{
    this->m_chosenWord = "Cat";
    this->m_letterGuesses = 5;
    this->m_wordGuesses = 2;
}

QString GameState::getChosenWord()
{
    return this->m_chosenWord;
}

bool GameState::makeLetterGuess(QChar letter)
{
    bool found = this->m_chosenWord.contains(letter);
    if (!found)
    {
        this->m_letterGuesses--;
    }
    return found;
}

bool GameState::makeWordGuess(QString guess)
{
    if (this->m_chosenWord == guess)
    {
        return true;
    }
    else
    {
        this->m_wordGuesses--;
        return false;
    }
}

int GameState::getWordGuesses()
{
    return this->m_wordGuesses;
}

int GameState::getLetterGuesses()
{
    return this->m_letterGuesses;
}
