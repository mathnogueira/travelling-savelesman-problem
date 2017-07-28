#ifndef TSP_GRAPH
#define TSP_GRAPH

#include <tsp/graph/graph_node.hpp>
#include <tsp/graph/graph_link.hpp>

#include <vector>
#include <cstdlib>

template <typename T>
class Graph {

    private:
        std::vector<GraphNode<T>*> nodes;
        GraphNode<T> *startNode;

        GraphNode<T>* createOrRetrieveNode(T &nodeContent) {
            GraphNode<T> *node = NULL;
            std::size_t i = 0;
            while (node == NULL && i < nodes.size()) {
                if (nodes.at(i)->getContent() == &nodeContent) {
                    node = nodes.at(i);
                }
                ++i;
            }
            
            return node != NULL ? node : new GraphNode<T>(&nodeContent);
        }

        void addNodeIfNotExists(GraphNode<T>* newNode) {
            for (size_t i = 0; i < nodes.size(); ++i) {
                if (nodes.at(i) == newNode) return;
            }
            nodes.push_back(newNode);
        }

    public:
        Graph() {}
        ~Graph() {}

        void add(T &source, T &destination, float cost) {
            // GraphNode<T> src(&source);
            // GraphNode<T> dest(&destination);

            // GraphNode<T> *nodeSrc = addOrRetrieveOld(src);
            // GraphNode<T> *nodeDest = addOrRetrieveOld(dest);

            // GraphLink *linkDestToSrc = new GraphLink(nodeSrc, cost);
            // GraphLink *linkSrcToDest = new GraphLink(nodeDest, cost);

            // nodeSrc->addLink(linkSrcToDest);
            // nodeDest->addLink(linkDestToSrc);
            GraphNode<T> *sourceNode = createOrRetrieveNode(source);
            GraphNode<T> *destinationNode = createOrRetrieveNode(destination);

            sourceNode->addLink(destinationNode, cost);
            destinationNode->addLink(sourceNode, cost);

            addNodeIfNotExists(sourceNode);
            addNodeIfNotExists(destinationNode);
        }

        void setInitialNode(T &node) {
            for (short i = 0; i < nodes.size(); ++i) {
                if (&node == nodes.at(i)->getContent()) {
                    this->startNode = nodes.at(i);
                }
            }
        }

        GraphNode<T>* getNode(unsigned short position) {
            return nodes.at(position);
        }

        int getNumberNodes() {
            return nodes.size();
        }
};

#endif