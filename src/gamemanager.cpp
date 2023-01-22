#include "gamemanager.h"

// ----- Constructors -----

GameManager::GameManager(QObject *parent)
    : QObject{parent}
{
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
    this->gameState->setCurrentLetterGuess(letter);
    bool found = getSolutionWord().contains(letter, Qt::CaseInsensitive);
    bool alreadyGuessed = this->gameState->getFoundLetters()
            .contains(letter.toUpper());
    if (!found)
    {
        this->gameState->addGuessedLetter(letter);
        if (!alreadyGuessed)
        {
            this->gameState->decrementNumLetterGuesses();
        }
        checkGameLoss();
    }
    else
    {
        if (!alreadyGuessed)
        {
            this->gameState->addFoundLetter(this->gameState->getCurrentLetterGuess());
        }
        checkGameWonByLetters();
    }

    if (this->gameState->getGamePhase() == in_progress)
    {
        emit letterGuessesUpdated();
    }
    return found;
}

bool GameManager::makeWordGuess(QString guess)
{
    if (getSolutionWord() == guess.toUpper())
    {
        this->gameState->setGamePhase(won);
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
        if (*c == this->gameState->getCurrentLetterGuess())
        {
            indices.append(i);
        }
        ++i;
    }
    return indices;
}

bool GameManager::hasFoundLetter(QChar letter)
{
    bool found = this->gameState->getFoundLetters().contains(letter);
    return found;
}

// --- End Public ---


void GameManager::checkGameLoss()
{
    if (getWordGuesses() == 0 || getLetterGuesses() == 0)
    {
        this->gameState->setGamePhase(lost);
    }
}

void GameManager::checkGameWonByLetters()
{
    int wordCount = getSolutionLetters().count();
    int matched = 0;
    for (int i = 0; i < this->gameState->getFoundLetters().count(); ++i)
    {
        QChar f = this->gameState->getFoundLetters()[i];
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
        this->gameState->setGamePhase(won);
    }
}

QString GameManager::endGameMessage()
{
    QString msg;
    if (this->gameState->getGamePhase() == won)
    {
        msg = "You Win!";
    }
    else if (this->gameState->getGamePhase() == lost)
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
    switch (this->gameState->getGamePhase())
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

GamePhase GameManager::getGamePhase()
{
    return this->gameState->getGamePhase();
}

void GameManager::setGamePhase(GamePhase gamePhase)
{
    this->gameState->setGamePhase(gamePhase);
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
