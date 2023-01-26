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
    this->gameState->setCurrentLetterGuess(letter.toUpper());
    bool found = getSolutionWord().contains(letter, Qt::CaseInsensitive);
    bool alreadyGuessed = this->gameState->getGuessedLetters()
            .contains(letter.toUpper());
    if (!found)
    {
        if (!alreadyGuessed)
        {
            this->gameState->addGuessedLetter(letter);
            this->gameState->addMissedLetter(letter);
            this->gameState->decrementNumLetterGuesses();
        }
        checkGameLoss();
    }
    else
    {
        if (!alreadyGuessed)
        {
            this->gameState->addFoundLetter(this->gameState->getCurrentLetterGuess());
            this->gameState->addGuessedLetter(letter);
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
    bool correct = false;
    if (guess.length() > 0) {
        if (getSolutionWord() == guess.toUpper())
        {
            this->gameState->setGamePhase(won);
            correct = true;
        }
        else
        {
            bool wordAlreadyGuessed =
                    this->gameState->getMissedWords().contains(guess.toUpper());
            if (!wordAlreadyGuessed)
            {
                this->gameState->addMissedWord(guess);
                this->gameState->decrementNumWordGuesses();
                checkGameLoss();
                emit wordGuessesUpdated();
            }
            correct = false;
        }
    }
    return correct;
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

void GameManager::checkGameLoss()
{
    if (getWordGuesses() == 0 || getLetterGuesses() == 0)
    {
        this->gameState->setGamePhase(lost);
    }
}


void GameManager::checkGameWonByLetters()
{
    int wordCount = distinctSolutionLetters().count();
    int matched = 0;
    for (int i = 0; i < this->gameState->getFoundLetters().count(); ++i)
    {
        QChar f = this->gameState->getFoundLetters().at(i);
        for (int j = 0; j < distinctSolutionLetters().count(); ++j)
        {
            QChar c = distinctSolutionLetters().at(j);
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
    delete(this->gameState);
}

// --- End Public ---


// ----- Private -----

QList<QChar> GameManager::distinctSolutionLetters()
{
    QList<QChar> distinctLetters;
    QList<QChar> solutionLetters = getSolutionLetters();
    for (int i = 0; i < solutionLetters.count(); ++i)
    {
        if (!distinctLetters.contains(solutionLetters.at(i)))
        {
            distinctLetters.append(solutionLetters.at(i));
        }
    }
    return distinctLetters;
}

// --- End Private ---

QString GameManager::getMissedWords()
{
    QString result = "";
    QList<QString> missedWords = this->gameState->getMissedWords();
    for (int i = 0; i < missedWords.count(); ++i)
    {
        result.append(missedWords.at(i) + "\n");
    }
    return result;
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

QString GameManager::getMissedLetters()
{
    QList<QChar>::iterator c;
    QString result = "";
    QList<QChar> missedLetters = this->gameState->getMissedLetters();
    for (c = missedLetters.begin(); c != missedLetters.end(); ++c)
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
