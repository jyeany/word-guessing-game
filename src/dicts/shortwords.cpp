#include "shortwords.h"

// ----- Constructors -----

ShortWords::ShortWords()
{
    this->dictUtils = new DictUtils();
    populateDictionary();
}

// --- End Constructors ---


// ----- Public -----

QString ShortWords::provideWord()
{
    return this->dictUtils->chooseRandom(this->shortWords);
}

// --- End Public ---


// ----- Private -----

void ShortWords::populateDictionary()
{
    this->shortWords.append("CAT");
    this->shortWords.append("HAT");
    this->shortWords.append("BOX");
    this->shortWords.append("FOX");

    this->shortWords.append("THAT");
    this->shortWords.append("ACRE");
    this->shortWords.append("ALLY");

    this->shortWords.append("SHARP");
    this->shortWords.append("SHELF");
    this->shortWords.append("SHINE");
}

// --- End Private ---
