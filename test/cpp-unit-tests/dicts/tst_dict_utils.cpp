#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../../src/dicts/dictutils.h"


TEST(DictUtilsUnitTests, ChoosesRandomWord)
{
    DictUtils *dictUtils = new DictUtils();
    QList<QString> wordList;
    wordList.append("ONE");
    wordList.append("TWO");
    wordList.append("THREE");
    const QString result = dictUtils->chooseRandom(wordList);
    ASSERT_TRUE(result == "ONE" || result == "TWO" || result == "THREE");
}
