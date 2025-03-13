#include "gtest/gtest.h"
#include "InvertedIndex.h"

TEST(TestCaseInvertedIndex, TestBasic) {
    InvertedIndex idx;
    std::vector<std::string> docs = {
        "milk water",
        "milk milk milk",
    };
    idx.UpdateDocumentBase(docs);
    std::vector<Entry> expected = {{0, 1}, {1, 3}};
    ASSERT_EQ(idx.GetWordCount("milk"), expected);
}
