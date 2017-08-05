#include <tsp/models/cidade.hpp>

#include <gtest/gtest.h>

TEST(Cidade, sequentialIdGeneration) {
    Cidade cidade1(1);
    Cidade cidade2(2);
    Cidade cidade3(3);

    ASSERT_EQ(cidade1.getId(), 1);
    ASSERT_EQ(cidade2.getId(), 2);
    ASSERT_EQ(cidade3.getId(), 3);
}

TEST(Cidade, noCitiesAreEqual) {
    Cidade cidade1(1);
    Cidade cidade2(2);
    Cidade cidade3(3);

    ASSERT_FALSE(cidade1.equals(cidade2));
    ASSERT_FALSE(cidade1.equals(cidade3));
    ASSERT_FALSE(cidade2.equals(cidade3));

    ASSERT_TRUE(cidade1.equals(cidade1));
}