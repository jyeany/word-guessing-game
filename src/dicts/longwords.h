#ifndef LONGWORDS_H
#define LONGWORDS_H

#include "iwordprovider.h"

class LongWords : public IWordProvider
{
public:
    LongWords();
    QString provideWord();
};

#endif // LONGWORDS_H
