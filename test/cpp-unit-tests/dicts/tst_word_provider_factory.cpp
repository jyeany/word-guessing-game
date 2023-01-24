#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

#include "../../../src/dicts/wordproviderfactory.h"
#include "../../../src/dicts/iwordprovider.h"

WordProviderFactory *wordProviderFactory = new WordProviderFactory();

TEST(WordProviderFactoryUnitTests, ShortWords)
{
    IWordProvider *result = wordProviderFactory->createWordProvider("Short");
    ShortWords *resultCast = dynamic_cast<ShortWords*>(result);
    ASSERT_TRUE(resultCast != nullptr);
}

TEST(WordProviderFactoryUnitTests, MediumWords)
{
    IWordProvider *result = wordProviderFactory->createWordProvider("Medium");
    MediumWords *resultCast = dynamic_cast<MediumWords*>(result);
    ASSERT_TRUE(resultCast != nullptr);
}

TEST(WordProviderFactoryUnitTests, LongWords)
{
    IWordProvider *result = wordProviderFactory->createWordProvider("Long");
    LongWords *resultCast = dynamic_cast<LongWords*>(result);
    ASSERT_TRUE(resultCast != nullptr);
}
