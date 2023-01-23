#include "longwords.h"

// ----- Constructors -----

LongWords::LongWords()
{
    this->dictUtils = new DictUtils();
    populateDictionary();
}

// --- End Constructors ---


// ----- Public -----

QString LongWords::provideWord()
{
    return this->dictUtils->chooseRandom(this->longWords);
}

// --- End Public ---


// ----- Private -----

void LongWords::populateDictionary()
{
    this->longWords.append("ABSOLUTE");
    this->longWords.append("ABSTRACT");
    this->longWords.append("ADJACENT");
    this->longWords.append("LOCATION");
    this->longWords.append("MEDIEVAL");
}

// --- End Private ---
