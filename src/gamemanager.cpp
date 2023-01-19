#include "gamemanager.h"

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
    this->m_chosenWord = "DOG";
    this->m_gameMode = in_progress;
    this->m_letterGuesses = 5;
    this->m_wordGuesses = 2;
}

bool GameManager::makeLetterGuess(QChar letter)
{
    this->m_currentLetterGuess = letter.toUpper();
    bool found = this->m_chosenWord
            .contains(letter, Qt::CaseInsensitive);
    if (!found)
    {
        this->m_guessedLetters.append(letter);
        this->m_letterGuesses--;
        checkGameLoss();
    }
    else
    {
        this->m_foundLetters.append(this->m_currentLetterGuess);
        checkGameWonByLetters();
    }

    if (this->m_gameMode == in_progress)
    {
        emit letterGuessesUpdated();
    }
    return found;
}

QList<int> GameManager::currentLetterIndices()
{
    QList<QChar> chosenLetters = getChosenLetters();
    QList<int> indices;
    QList<QChar>::iterator c;
    int i = 0;
    for (c = chosenLetters.begin(); c != chosenLetters.end(); ++c)
    {
        if (*c == this->m_currentLetterGuess)
        {
            indices.append(i);
        }
        ++i;
    }
    return indices;
}

bool GameManager::hasFoundLetter(QChar letter)
{
    bool found = this->m_foundLetters.contains(letter);
    return found;
}

bool GameManager::makeWordGuess(QString guess)
{
    if (this->m_chosenWord == guess.toUpper())
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

void GameManager::checkGameLoss()
{
    if (this->m_wordGuesses == 0 || this->m_letterGuesses == 0)
    {
        this->m_gameMode = lost;
    }
}

void GameManager::checkGameWonByLetters()
{
    int wordCount = getChosenLetters().count();
    int matched = 0;
    for (int i = 0; i < this->m_foundLetters.count(); ++i)
    {
        QChar f = this->m_foundLetters[i];
        for (int j = 0; j < getChosenLetters().count(); ++j)
        {
            QChar c = getChosenLetters()[j];
            if (f == c)
            {
                matched++;
                break;
            }
        }
    }

    if (matched == wordCount)
    {
        this->m_gameMode = won;
    }
}

QString GameManager::endGameMessage()
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

void GameManager::resetGame()
{

}

QString GameManager::getGuessedLetters()
{
    QList<QChar>::iterator c;
    QString result = "";
    for (c = this->m_guessedLetters.begin(); c != this->m_guessedLetters.end(); ++c)
    {

        result = result + c->toUpper() + " ";
    }
    return result;
}

QString GameManager::getChosenWord()
{
    return this->m_chosenWord;
}

void GameManager::setChosenWord(QString word)
{
    this->m_chosenWord = word.toUpper();
}

QList<QChar> GameManager::getChosenLetters()
{
    QList<QChar> result;
    for (int i = 0; i < this->m_chosenWord.length(); ++i)
    {
        result.append(this->m_chosenWord[i]);
    }
    return result;
}

QString GameManager::getGameModeStr()
{
    switch (this->m_gameMode)
    {
    case lost:
        return "lost";
    case won:
        return "won";
    case in_progress:
        return "in_progress";
    default:
        return "";
    }
}

GameMode GameManager::getGameMode()
{
    return this->m_gameMode;
}

void GameManager::setGameMode(GameMode gameMode)
{
    this->m_gameMode = gameMode;
}

int GameManager::getWordGuesses()
{
    return this->m_wordGuesses;
}

void GameManager::setWordGuesses(int guesses)
{
    this->m_wordGuesses = guesses;
}

int GameManager::getLetterGuesses()
{
    return this->m_letterGuesses;
}

void GameManager::setLetterGuesses(int guesses)
{
    this->m_letterGuesses = guesses;
}
