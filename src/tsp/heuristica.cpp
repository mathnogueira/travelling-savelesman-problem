#include <tsp/heuristica.hpp>
#include <cstdlib>
#include <iostream>

void Heuristica::solve(Graph<Cidade> *graph, std::vector<int> &optimumPath) {
    if (graph == NULL || graph->getNumberNodes() == 0) return;

    GraphNode<Cidade> *currentNode = NULL;
    GraphNode<Cidade> *nextNode = graph->getInitialNode();

    float halfProfits = getStopThreshold(graph);
    float sumProfits = 0;

    do {
        currentNode = nextNode;
        optimumPath.push_back(currentNode->getContent()->getId());

        nextNode = getNextNodeToVisit(currentNode);
    } while (nextNode != NULL && sumProfits < halfProfits);
}

GraphNode<Cidade>* Heuristica::getNextNodeToVisit(GraphNode<Cidade> *node) {
    return NULL;
}

float Heuristica::getStopThreshold(Graph<Cidade> *graph) {
    float allProfits = 0;
    Collection<GraphNode<Cidade>*>* nodes = graph->getAllNodes();
    for (unsigned int i = 0; i < nodes->count(); ++i) {
        Cidade *cidade = nodes->at(i)->getContent();
        allProfits += cidade->getPremio();
    }

    return allProfits / 2;
}