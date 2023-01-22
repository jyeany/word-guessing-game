#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>
#include "gamestatecreator.h"
#include "gamestate.h"

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);
    Q_INVOKABLE void createGame(QString wordLength);
    Q_INVOKABLE bool makeLetterGuess(QChar letter);
    Q_INVOKABLE bool makeWordGuess(QString guess);
    Q_INVOKABLE QString endGameMessage();
    Q_INVOKABLE void resetGame();
    Q_INVOKABLE bool hasFoundLetter(QChar letter);
    Q_INVOKABLE QList<int> currentLetterIndices();
    void checkGameLoss();
    void checkGameWonByLetters();

    // Getters
    Q_INVOKABLE QString getSolutionWord();
    Q_INVOKABLE QList<QChar> getSolutionLetters();
    Q_INVOKABLE int getWordGuesses();
    Q_INVOKABLE int getLetterGuesses();
    Q_INVOKABLE QString getGuessedLetters();
    Q_INVOKABLE QString getGameModeStr();
    GamePhase getGamePhase();

    // Setters
    void setSolutionWord(QString word);
    void setWordGuesses(int guesses);
    void setLetterGuesses(int guesses);
    void setGamePhase(GamePhase gamePhase);

signals:
    void letterGuessesUpdated();

private:
    GameStateCreator *gameStateCreator;
    GameState *gameState;
    bool hasGuessedLetter(QChar letter);
};

#endif // GAMEMANAGER_H
