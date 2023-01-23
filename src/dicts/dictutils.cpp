#include "dictutils.h"

// ----- Constructors -----

DictUtils::DictUtils() {}

// --- End Constructors ---


// ----- Public -----

QString DictUtils::chooseRandom(QList<QString> wordList)
{
    random_device rd; // obtain a random number from hardware
    mt19937 gen(rd()); // seed the generator
    int endIndex = wordList.count() - 1;
    uniform_int_distribution<> distr(0, endIndex); // define the range

    int index = distr(gen);
    return wordList.at(index);
}

// --- End Public ---
