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
    int getNumLetterGuesses();
    int getNumWordGuesses();

private:
   QString solutionWord;
   QList<QChar> solutionLetters;
   int numLetterGuesses;
   int numWordGuesses;
};

#endif // GAMESTATE_H
