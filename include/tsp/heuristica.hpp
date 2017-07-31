#ifndef TSP_HEURISTICA
#define TSP_HEURISTICA

#include <tsp/graph/graph.hpp>
#include <tsp/models/cidade.hpp>

#include <vector>

class Heuristica {

    public:
        void solve(Graph<Cidade> *graph, std::vector<int> &optimumPath);

    protected:
        GraphNode<Cidade>* getNextNodeToVisit(GraphNode<Cidade> *node);
        float getStopThreshold(Graph<Cidade> *graph);

};

#endif