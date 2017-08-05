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

    private:
        std::vector<int> *visitedNodes;
        bool nodeAlreadyVisited(void *nodePtr);
        float getPremio(GraphNode<Cidade> *node);
        float getPrejuizo(GraphNode<Cidade> *node);

};

#endif