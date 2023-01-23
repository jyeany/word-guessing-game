#include "mediumwords.h"

// ----- Constructors -----

MediumWords::MediumWords()
{
    this->dictUtils = new DictUtils();
    populateDictionary();
}

// --- End Constructors ---


// ----- Public -----

QString MediumWords::provideWord()
{
    return this->dictUtils->chooseRandom(this->mediumWords);
}

// --- End Public ---


// ----- Private -----

void MediumWords::populateDictionary()
{
    this->mediumWords.append("ABSOLUTE");
    this->mediumWords.append("ABSTRACT");
    this->mediumWords.append("ADJACENT");
    this->mediumWords.append("LOCATION");
    this->mediumWords.append("MEDIEVAL");
}

// --- End Private ---
