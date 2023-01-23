#include "wordproviderfactory.h"
#include "longwords.h"
#include "shortwords.h"
#include "mediumwords.h"

WordProviderFactory::WordProviderFactory() {}


IWordProvider* WordProviderFactory::createWordProvider(QString wordLength)
{
    IWordProvider* result;
    if (wordLength == "Short")
    {
        result = new ShortWords();
    }
    else if (wordLength == "Medium")
    {
        result = new MediumWords();
    }
    else
    {
        result = new LongWords();
    }
    return result;
}
