#ifndef TSP_GRAPH
#define TSP_GRAPH

#include <tsp/utils/collection.hpp>
#include <tsp/graph/graph_node.hpp>
#include <tsp/graph/graph_link.hpp>

#include <cstdlib>
#include <limits>

template <typename T>
class Graph {

    private:
        Collection<GraphNode<T>*> nodes;
        GraphNode<T> *startNode;

        GraphNode<T>* createOrRetrieveNode(T &nodeContent) {
            GraphNode<T> *node = retrieveNode(nodeContent);
            return node != NULL ? node : new GraphNode<T>(&nodeContent);
        }

        void addNodeIfNotExists(GraphNode<T>* newNode) {
            for (size_t i = 0; i < nodes.count(); ++i) {
                if (nodes.at(i) == newNode) return;
            }
            nodes.add(newNode);
        }

        GraphNode<T>* retrieveNode(T &nodeContent) {
            GraphNode<T> *node = NULL;
            std::size_t i = 0;
            while (node == NULL && i < nodes.count()) {
                if (nodes.at(i)->getContent() == &nodeContent) {
                    node = nodes.at(i);
                }
                ++i;
            }
            return node;
        }

    public:
        Graph() {}
        ~Graph() {}

        void add(T &source, T &destination, float cost) {
            GraphNode<T> *sourceNode = createOrRetrieveNode(source);
            GraphNode<T> *destinationNode = createOrRetrieveNode(destination);

            sourceNode->addLink(destinationNode, cost);
            destinationNode->addLink(sourceNode, cost);

            addNodeIfNotExists(sourceNode);
            addNodeIfNotExists(destinationNode);
        }

        void setInitialNode(T &node) {
            for (short i = 0; i < nodes.count(); ++i) {
                if (&node == nodes.at(i)->getContent()) {
                    this->startNode = nodes.at(i);
                }
            }
        }

        GraphNode<T>* getInitialNode() {
            return startNode;
        }

        float getCostFrom(T &source, T &dest) {

            GraphNode<T> *sourceNode = NULL;
            for (size_t i = 0; i < nodes.count(); ++i) {
                if (nodes.at(i)->getContent() == &source) {
                    sourceNode = nodes.at(i);
                }
            }

            if (sourceNode == NULL) {
                return std::numeric_limits<float>::infinity();
            }

            Collection<GraphLink*> *links = sourceNode->getLinks();
            GraphLink *correctLink = NULL;
            for (size_t i = 0; i < links->count(); ++i) {
                GraphLink *link = links->at(i);
                GraphNode<T> *from = (GraphNode<T>*) link->getDestination();
                if (from->getContent() == &dest) {
                    correctLink = link;
                }
            }

            if (correctLink == NULL) {
                return std::numeric_limits<float>::infinity();
            }

            return correctLink->getCost();
        }

        GraphNode<T>* getNode(unsigned short position) {
            return nodes.at(position);
        }

        int getNumberNodes() {
            return nodes.count();
        }

        Collection<GraphNode<T>*>* getAllNodes() {
            return &nodes;
        }
};

#endif