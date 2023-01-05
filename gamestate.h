#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>

class GameState : public QObject
{
    Q_OBJECT
public:
    explicit GameState(QObject *parent = nullptr);
    Q_INVOKABLE QString getChosenWord();
    Q_INVOKABLE bool makeLetterGuess(QChar letter);
    Q_INVOKABLE bool makeWordGuess(QString guess);
    Q_INVOKABLE int getWordGuesses();
    Q_INVOKABLE int getLetterGuesses();

signals:

private:
    QString m_chosenWord;
    int m_letterGuesses;
    int m_wordGuesses;

};

#endif // GAMESTATE_H
