#ifndef SHORTWORDS_H
#define SHORTWORDS_H

#include <QList>
#include <QString>
#include "iwordprovider.h"
#include "dictutils.h"

class ShortWords : public IWordProvider
{
public:
    ShortWords();
    QString provideWord();

private:
    DictUtils *dictUtils;
    QList<QString> shortWords;
    void populateDictionary();
};

#endif // SHORTWORDS_H
