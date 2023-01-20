#ifndef GAMESTATE_H
#define GAMESTATE_H

#include<QString>
#include<QList>
#include<QChar>

class GameState
{
public:
    GameState();

    // getters
    QString getSolutionWord();
    QList<QChar> getSolutionLetters();
    QList<QChar> getGuessedLetters();
    int getNumLetterGuesses();
    int getNumWordGuesses();

    // setters
    void setSolutionWord(QString word);
    void setNumLetterGuesses(int guesses);
    void setNumWordGuesses(int guesses);

private:

    // properties
    QString solutionWord;
    QList<QChar> solutionLetters;
    QList<QChar> guessedLetters;
    int numLetterGuesses;
    int numWordGuesses;

    // functions
    void populateSolutionLetters();
};

#endif // GAMESTATE_H
