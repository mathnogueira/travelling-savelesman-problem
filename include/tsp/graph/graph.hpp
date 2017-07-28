#ifndef TSP_GRAPH
#define TSP_GRAPH

#include <tsp/utils/collection.hpp>
#include <tsp/graph/graph_node.hpp>
#include <tsp/graph/graph_link.hpp>

#include <cstdlib>

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

        float getCostFrom(T &source, T &dest) {
            GraphNode<T> *node = retrieveNode(source);
        }

        GraphNode<T>* getNode(unsigned short position) {
            return nodes.at(position);
        }

        int getNumberNodes() {
            return nodes.count();
        }
};

#endif