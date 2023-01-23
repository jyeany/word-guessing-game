#ifndef SHORTWORDS_H
#define SHORTWORDS_H

#include "iwordprovider.h"

class ShortWords : IWordProvider
{
public:
    ShortWords();
    QString provideWord();
};

#endif // SHORTWORDS_H
