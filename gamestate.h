#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <QObject>

enum GameMode {won, lost, in_progress};

class GameState : public QObject
{
    Q_OBJECT
public:
    explicit GameState(QObject *parent = nullptr);
    Q_INVOKABLE QString getChosenWord();
    Q_INVOKABLE bool makeLetterGuess(QChar letter);
    Q_INVOKABLE bool makeWordGuess(QString guess);
    void checkGameLoss();

    // Getters
    Q_INVOKABLE int getWordGuesses();
    Q_INVOKABLE int getLetterGuesses();
    GameMode getGameMode();

    // Setters
    void setChosenWord(QString word);
    void setWordGuesses(int guesses);
    void setLetterGuesses(int guesses);

signals:

private:
    QString m_chosenWord;
    GameMode m_gameMode;
    int m_letterGuesses;
    int m_wordGuesses;
};

#endif // GAMESTATE_H
