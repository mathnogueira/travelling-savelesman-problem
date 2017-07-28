#include <tsp/graph/graph.hpp>
#include <gtest/gtest.h>

TEST(Graph, emptyGraph) {
    Graph<int> graph;
    ASSERT_EQ(graph.getNumberNodes(), 0);
}

TEST(Graph, doesNotAllowDuplicates) {
    Graph<int> graph;

    int i = 3;
    int j = 5;
    int k = 4;
    graph.add(i, j, 3);
    graph.add(i, k, 5);

    ASSERT_EQ(graph.getNumberNodes(), 3);
}

TEST(Graph, getNumberOfConnectionsOfANode) {
    Graph<int> graph;

    int i = 3;
    int j = 5;
    int k = 4;
    graph.add(i, j, 3);
    graph.add(i, k, 5);

    GraphNode<int> *node = graph.getNode(0);
    ASSERT_TRUE(node != NULL);
    ASSERT_EQ(node->getNumberLinks(), 2);
}

TEST(Graph, getCostOfMovingFromANodeToAnother) {
    Graph<int> graph;

    int i = 8;
    int j = 33;
    int k = 12;

    graph.add(i, j, 8);
    graph.add(i, j, 33);
    graph.add(j, k, 12);

    // float cost = graph.getCostFrom(i, j);
    // ASSERT_EQ(cost, 8);
}