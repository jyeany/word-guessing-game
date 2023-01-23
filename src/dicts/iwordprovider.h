#ifndef IWORDPROVIDER_H
#define IWORDPROVIDER_H

#include <QString>

class IWordProvider
{
public:
    virtual QString provideWord() = 0;
};

#endif // IWORDPROVIDER_H
