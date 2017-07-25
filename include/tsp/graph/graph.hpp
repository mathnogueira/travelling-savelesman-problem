#ifndef TSP_GRAPH
#define TSP_GRAPH

#include <tsp/graph/graph_node.hpp>
#include <tsp/graph/graph_link.hpp>

#include <vector>

template <typename T>
class Graph {

    private:
        std::vector<GraphNode<T> > nodes;
        GraphNode<T> *startNode;

        GraphNode<T>* addOrRetrieveOld(GraphNode<T> &node) {
            for (short i = 0; i < nodes.size(); ++i) {
                if (node.getContent() == nodes.at(i).getContent()) {
                    return &(nodes.at(i));
                }
            }
            this->nodes.push_back(node);
            return &node;
        }

    public:
        Graph() {}
        ~Graph() {}

        void add(T &source, T &destination, float cost) {
            GraphNode<T> src(&source);
            GraphNode<T> dest(&destination);

            GraphNode<T> *nodeSrc = addOrRetrieveOld(src);
            GraphNode<T> *nodeDest = addOrRetrieveOld(dest);

            GraphLink *linkDestToSrc = new GraphLink(nodeSrc, cost);
            GraphLink *linkSrcToDest = new GraphLink(nodeDest, cost);

            nodeSrc->addLink(linkSrcToDest);
            nodeDest->addLink(linkDestToSrc);
        }

        void setInitialNode(T &node) {
            for (short i = 0; i < nodes.size(); ++i) {
                if (&node == nodes.at(i).getContent()) {
                    this->startNode = &(nodes.at(i));
                }
            }
        }

        GraphNode<T>* getNode(unsigned short position) {
            return &nodes.at(position);
        }

        int getNumberNodes() {
            return nodes.size();
        }
};

#endif