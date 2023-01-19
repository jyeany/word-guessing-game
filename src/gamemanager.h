#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QObject>

enum GameMode {won, lost, in_progress};

class GameManager : public QObject
{
    Q_OBJECT
public:
    explicit GameManager(QObject *parent = nullptr);
    Q_INVOKABLE bool makeLetterGuess(QChar letter);
    Q_INVOKABLE bool makeWordGuess(QString guess);
    Q_INVOKABLE QString endGameMessage();
    Q_INVOKABLE void resetGame();
    Q_INVOKABLE bool hasFoundLetter(QChar letter);
    Q_INVOKABLE QList<int> currentLetterIndices();
    void checkGameLoss();
    void checkGameWonByLetters();

    // Getters
    Q_INVOKABLE QString getChosenWord();
    Q_INVOKABLE QList<QChar> getChosenLetters();
    Q_INVOKABLE int getWordGuesses();
    Q_INVOKABLE int getLetterGuesses();
    Q_INVOKABLE QString getGuessedLetters();
    GameMode getGameMode();
    Q_INVOKABLE QString getGameModeStr();

    // Setters
    void setChosenWord(QString word);
    void setWordGuesses(int guesses);
    void setLetterGuesses(int guesses);
    void setGameMode(GameMode gameMode);

signals:
    void letterGuessesUpdated();

private:
    QString m_chosenWord;
    QChar m_currentLetterGuess;
    GameMode m_gameMode;
    QList<QChar> m_guessedLetters;
    QList<QChar> m_foundLetters;
    int m_letterGuesses;
    int m_wordGuesses;
};

#endif // GAMEMANAGER_H
