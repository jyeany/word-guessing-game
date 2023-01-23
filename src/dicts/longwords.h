#ifndef LONGWORDS_H
#define LONGWORDS_H

#include <QList>
#include <QString>
#include "iwordprovider.h"
#include "dictutils.h"

class LongWords : public IWordProvider
{
public:
    LongWords();
    QString provideWord();

private:
    DictUtils *dictUtils;
    QList<QString> longWords;
    void populateDictionary();
};

#endif // LONGWORDS_H
