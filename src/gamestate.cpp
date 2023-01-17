#include "gamestate.h"

GameState::GameState(QObject *parent)
    : QObject{parent}
{
    this->m_chosenWord = "ORANGE";
    this->m_gameMode = in_progress;
    this->m_letterGuesses = 5;
    this->m_wordGuesses = 2;
}

bool GameState::makeLetterGuess(QChar letter)
{
    bool found = this->m_chosenWord.contains(letter);
    if (!found)
    {
        this->m_guessedLetters.append(letter);
        this->m_letterGuesses--;
        checkGameLoss();
    }

    if (this->m_gameMode == in_progress)
    {
        emit letterGuessesUpdated();
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

QString GameState::endGameMessage()
{
    QString msg;
    if (this->m_gameMode == won)
    {
        msg = "You Win!";
    }
    else if (this->m_gameMode == lost)
    {
        msg = "You Lose!";
    }
    return msg;
}

void GameState::resetGame()
{

}

QString GameState::getGuessedLetters()
{
    QList<QChar>::iterator c;
    QString result = "";
    for (c = this->m_guessedLetters.begin(); c != this->m_guessedLetters.end(); ++c)
    {

        result = result + c->toUpper() + " ";
    }
    return result;
}

QString GameState::getChosenWord()
{
    return this->m_chosenWord;
}

void GameState::setChosenWord(QString word)
{
    this->m_chosenWord = word;
}

QList<QChar> GameState::getChosenLetters()
{
    QList<QChar> result;
    for (int i = 0; i < this->m_chosenWord.length(); ++i)
    {
        result.append(this->m_chosenWord[i]);
    }
    return result;
}

GameMode GameState::getGameMode()
{
    return this->m_gameMode;
}

void GameState::setGameMode(GameMode gameMode)
{
    this->m_gameMode = gameMode;
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
