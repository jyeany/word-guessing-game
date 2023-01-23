#ifndef MEDIUMWORDS_H
#define MEDIUMWORDS_H

#include <QList>
#include <QString>
#include "iwordprovider.h"
#include "dictutils.h"

class MediumWords : public IWordProvider
{
public:
    MediumWords();
    QString provideWord();

private:
    DictUtils *dictUtils;
    QList<QString> mediumWords;
    void populateDictionary();
};

#endif // MEDIUMWORDS_H
