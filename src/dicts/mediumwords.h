#ifndef MEDIUMWORDS_H
#define MEDIUMWORDS_H

#include "iwordprovider.h"

class MediumWords : IWordProvider
{
public:
    MediumWords();
    QString provideWord();
};

#endif // MEDIUMWORDS_H
