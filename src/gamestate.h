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
    void addFoundLetter(QChar letter);
    void addMissedLetter(QChar letter);
    void addMissedWord(QString word);

    // getters
    GamePhase getGamePhase();
    QString getSolutionWord();
    QList<QChar> getSolutionLetters();
    QList<QChar> getGuessedLetters();
    QChar getCurrentLetterGuess();
    QList<QChar> getFoundLetters();
    QList<QChar> getMissedLetters();
    QList<QString> getMissedWords();
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
    QList<QString> missedWords;
    int numLetterGuesses;
    int numWordGuesses;

    // functions
    void populateSolutionLetters();
};

#endif // GAMESTATE_H
