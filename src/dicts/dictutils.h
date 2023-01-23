#ifndef DICTUTILS_H
#define DICTUTILS_H

#include <QList>
#include <QString>
#include <random>

using namespace std;

class DictUtils
{
public:
    DictUtils();
    QString chooseRandom(QList<QString> wordList);
};

#endif // DICTUTILS_H
