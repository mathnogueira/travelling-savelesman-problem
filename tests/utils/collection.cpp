#include <gtest/gtest.h>

#include <tsp/utils/collection.hpp>

TEST(Collection, canFilterUsingLambdas) {
    Collection<int> *collection = new Collection<int>();
    collection->add(1);
    collection->add(18);
    collection->add(12);
    collection->add(33);
    collection->add(51);

    Collection<int> *filtered = collection->filter([](auto i) { return i % 2 == 0; });

    ASSERT_EQ(collection->count(), 5);
    ASSERT_EQ(filtered->count(), 2);

    int* firstElement = filtered->firstOrDefault();
    ASSERT_FALSE(firstElement == NULL);
    ASSERT_EQ(*firstElement, 18);
}

TEST(Collection, canAccessUsingArrayOperator) {
    Collection<int> *collection = new Collection<int>();
    collection->add(1);
    collection->add(18);
    collection->add(12);
    collection->add(33);
    collection->add(51);

    ASSERT_EQ(collection->at(0), 1);
    ASSERT_EQ(collection->at(1), 18);
    ASSERT_EQ(collection->at(2), 12);
    ASSERT_EQ(collection->at(4), 51);
}