#include "gamemanager.h"

// ----- Constructors -----

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
//    this->m_chosenWord = "DOG";
//    this->m_letterGuesses = 5;
//    this->m_wordGuesses = 2;
    this->m_gameMode = in_progress;
    this->gameStateCreator = new GameStateCreator();
}

// --- End Constructors ---


// ----- Public -----

void GameManager::createGame(QString wordLength)
{
    this->gameState = this->gameStateCreator->createGame(wordLength);
}

bool GameManager::makeLetterGuess(QChar letter)
{
    this->m_currentLetterGuess = letter.toUpper();
    bool found = getSolutionWord().contains(letter, Qt::CaseInsensitive);
    if (!found)
    {
        this->gameState->addGuessedLetter(letter);
        this->gameState->decrementNumLetterGuesses();
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

bool GameManager::makeWordGuess(QString guess)
{
    if (getSolutionWord() == guess.toUpper())
    {
        this->m_gameMode = won;
        return true;
    }
    else
    {
        this->gameState->decrementNumWordGuesses();
        checkGameLoss();
        return false;
    }
}

QList<int> GameManager::currentLetterIndices()
{
    QList<QChar> solutionLetters = getSolutionLetters();
    QList<int> indices;
    QList<QChar>::iterator c;
    int i = 0;
    for (c = solutionLetters.begin(); c != solutionLetters.end(); ++c)
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

// --- End Public ---


void GameManager::checkGameLoss()
{
    if (getWordGuesses() == 0 || getLetterGuesses() == 0)
    {
        this->m_gameMode = lost;
    }
}

void GameManager::checkGameWonByLetters()
{
    int wordCount = getSolutionLetters().count();
    int matched = 0;
    for (int i = 0; i < this->m_foundLetters.count(); ++i)
    {
        QChar f = this->m_foundLetters[i];
        for (int j = 0; j < getSolutionLetters().count(); ++j)
        {
            QChar c = getSolutionLetters().at(j);
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
    QList<QChar> guessedLetters = this->gameState->getGuessedLetters();
    for (c = guessedLetters.begin(); c != guessedLetters.end(); ++c)
    {
        result = result + c->toUpper() + " ";
    }

    return result;
}

QString GameManager::getSolutionWord()
{
    return this->gameState->getSolutionWord();
}

void GameManager::setSolutionWord(QString word)
{
    this->gameState->setSolutionWord(word.toUpper());
}

QList<QChar> GameManager::getSolutionLetters()
{   
    return this->gameState->getSolutionLetters();
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
    return this->gameState->getNumWordGuesses();
}

void GameManager::setWordGuesses(int guesses)
{
    this->gameState->setNumWordGuesses(guesses);
}

int GameManager::getLetterGuesses()
{
    return this->gameState->getNumLetterGuesses();
}

void GameManager::setLetterGuesses(int guesses)
{
    this->gameState->setNumLetterGuesses(guesses);
}
