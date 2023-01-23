#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<QString>
#include<QList>
#include<QChar>
#include "dicts/wordproviderfactory.h"

enum GamePhase {won, lost, in_progress};

class GameState
{
public:
    GameState();

    // functions
    int decrementNumLetterGuesses();
    int decrementNumWordGuesses();
    void addGuessedLetter(QChar letter);
    void addFoundLetter(QChar letter);
    void addMissedLetter(QChar letter);

    // getters
    GamePhase getGamePhase();
    QString getSolutionWord();
    QList<QChar> getSolutionLetters();
    QList<QChar> getGuessedLetters();
    QChar getCurrentLetterGuess();
    QList<QChar> getFoundLetters();
    QList<QChar> getMissedLetters();
    int getNumLetterGuesses();
    int getNumWordGuesses();

    // setters
    void setGamePhase(GamePhase gamePhase);
    void setSolutionWord(QString word);
    void setNumLetterGuesses(int guesses);
    void setNumWordGuesses(int guesses);
    void setCurrentLetterGuess(QChar letter);

private:

    // properties
    GamePhase gamePhase;
    QString solutionWord;
    QList<QChar> solutionLetters;
    QList<QChar> guessedLetters;
    QChar currentLetterGuess;
    QList<QChar> foundLetters;
    QList<QChar> missedLetters;
    int numLetterGuesses;
    int numWordGuesses;

    // functions
    void populateSolutionLetters();
};

#endif // GAMESTATE_H
