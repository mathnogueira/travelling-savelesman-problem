#include <tsp/heuristica.hpp>
#include <cstdlib>
#include <iostream>
#include <limits>

void Heuristica::solve(Graph<Cidade> *graph, std::vector<int> &optimumPath) {
    if (graph == NULL || graph->getNumberNodes() == 0) return;

    this->visitedNodes = &optimumPath;

    GraphNode<Cidade> *currentNode = NULL;
    GraphNode<Cidade> *nextNode = graph->getInitialNode();

    float halfProfits = getStopThreshold(graph);
    float sumProfits = 0;

    do {
        currentNode = nextNode;
        optimumPath.push_back(currentNode->getContent()->getId());
        sumProfits += getPremio(currentNode);

        nextNode = getNextNodeToVisit(currentNode);
    } while (nextNode != NULL && sumProfits < halfProfits);
}

GraphNode<Cidade>* Heuristica::getNextNodeToVisit(GraphNode<Cidade> *node) {
    std::vector<GraphLink*> *nodeLinks = node->getLinks();
    if (nodeLinks->size() == 0) return NULL;
    
    GraphLink *bestLink = NULL;
    float bestCost = std::numeric_limits<float>::infinity();
    for (int i = 0; i < nodeLinks->size(); ++i) {
        GraphLink *currentLink = nodeLinks->at(i);
        float currentCost = currentLink->getCost();
        // Verifica se o nó já foi visitado
        if (!nodeAlreadyVisited(currentLink->getDestination())) {
            if (currentCost < bestCost) {
                bestLink = currentLink;
                bestCost = currentCost;
            }
        }
    }

    if (bestLink == NULL) return NULL;
    GraphNode<Cidade> *cidadeNode = (GraphNode<Cidade>*) bestLink->getDestination();
    return cidadeNode;
}

float Heuristica::getStopThreshold(Graph<Cidade> *graph) {
    float allProfits = 0;
    std::vector<GraphNode<Cidade>*> nodes = graph->getAllNodes();
    for (unsigned int i = 0; i < nodes.size(); ++i) {
        Cidade *cidade = nodes.at(i)->getContent();
        allProfits += cidade->getPremio();
    }

    return allProfits / 2;
}

bool Heuristica::nodeAlreadyVisited(void *nodePtr) {
    GraphNode<Cidade>* node = (GraphNode<Cidade>*) nodePtr;
    unsigned int nodeId = node->getContent()->getId();

    for (unsigned int i = 0; i < visitedNodes->size(); ++i) {
        if (visitedNodes->at(i) == nodeId) {
            return true;
        }
    }

    return false;
}

float Heuristica::getPremio(GraphNode<Cidade> *node) {
    return node->getContent()->getPremio();
}

float Heuristica::getPrejuizo(GraphNode<Cidade> *node) {
    return node->getContent()->getPrejuizo();
}