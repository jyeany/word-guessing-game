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
    this->longWords.append("APPRECIATE");
    this->longWords.append("BACKPACKER");
    this->longWords.append("BEDAZZLING");
    this->longWords.append("BAMBOOZLED");
    this->longWords.append("CHICKENPOX");
    this->longWords.append("COMPLEXITY");
    this->longWords.append("EQUALIZERS");
    this->longWords.append("FRIENDSHIP");
    this->longWords.append("HYPNOTIZED");
    this->longWords.append("JACKRABBIT");
    this->longWords.append("LUMBERJACK");
    this->longWords.append("MOTIVATION");
    this->longWords.append("MOZZARELLA");
    this->longWords.append("PREQUALIFY");
    this->longWords.append("STRAWBERRY");
    this->longWords.append("ZOOMORPHIC");
}

// --- End Private ---
