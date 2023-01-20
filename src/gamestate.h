#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<QString>
#include<QList>
#include<QChar>

enum GamePhase {won, lost, in_progress};

class GameState
{
public:
    GameState();

    // functions
    int decrementNumLetterGuesses();
    int decrementNumWordGuesses();
    void addGuessedLetter(QChar letter);

    // getters
    GamePhase getGamePhase();
    QString getSolutionWord();
    QList<QChar> getSolutionLetters();
    QList<QChar> getGuessedLetters();
    int getNumLetterGuesses();
    int getNumWordGuesses();

    // setters
    void setGamePhase(GamePhase gamePhase);
    void setSolutionWord(QString word);
    void setNumLetterGuesses(int guesses);
    void setNumWordGuesses(int guesses);

private:

    // properties
    GamePhase gamePhase;
    QString solutionWord;
    QList<QChar> solutionLetters;
    QList<QChar> guessedLetters;
    int numLetterGuesses;
    int numWordGuesses;

    // functions
    void populateSolutionLetters();
};

#endif // GAMESTATE_H
