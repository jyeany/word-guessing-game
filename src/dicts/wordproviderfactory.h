#ifndef WORDPROVIDERFACTORY_H
#define WORDPROVIDERFACTORY_H

#include "shortwords.h"
#include "mediumwords.h"
#include "longwords.h"
#include "iwordprovider.h"

class WordProviderFactory
{
public:
    WordProviderFactory();
    IWordProvider* createWordProvider(QString wordLength);
};

#endif // WORDPROVIDERFACTORY_H
