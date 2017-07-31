#include <tsp/heuristica.hpp>
#include <tsp/graph/graph.hpp>
#include <tsp/models/cidade.hpp>

#include <vector>
#include <gtest/gtest.h>

TEST(Heuristica, ReturnEmptyIfNoGraphProvided) {
    std::vector<int> optimumPath;
    Graph<Cidade> *graph = new Graph<Cidade>();
    Heuristica heuristica;

    heuristica.solve(graph, optimumPath);

    ASSERT_EQ(optimumPath.size(), 0);
}

TEST(Heuristica, ShouldAddTheInicialCityAsFirstPathItem) {
    std::vector<int> optimumPath;
    Graph<Cidade> *graph = new Graph<Cidade>();
    Cidade city1(1);
    Cidade city2(2);
    graph->add(city1, city2, 3);
    Heuristica heuristica;

    heuristica.solve(graph, optimumPath);

    ASSERT_EQ(optimumPath.size(), 1);
}