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
    Cidade city3(3);
    graph->add(city1, city2, 33);
    graph->add(city1, city3, 8);
    graph->setInitialNode(city1);
    Heuristica heuristica;

    heuristica.solve(graph, optimumPath);

    ASSERT_EQ(optimumPath.size(), 1);
    ASSERT_EQ(optimumPath.at(0), 1);
}

TEST(Heuristica, TesteAlgoritmoGuloso) {
    std::vector<int> optimumPath;
    Graph<Cidade> *graph = new Graph<Cidade>();
    Cidade city1(1, 2, 5);
    Cidade city2(2, 50, 3);
    Cidade city3(3, 10, 7);
    graph->add(city1, city2, 33);
    graph->add(city1, city3, 8);
    graph->add(city3, city2, 15);
    graph->setInitialNode(city1);
    Heuristica heuristica;

    heuristica.solve(graph, optimumPath);

    ASSERT_EQ(optimumPath.size(), 3);
    ASSERT_EQ(optimumPath.at(0), 1);
    ASSERT_EQ(optimumPath.at(1), 3);
    ASSERT_EQ(optimumPath.at(2), 2);
}