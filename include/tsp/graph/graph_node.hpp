#ifndef TSP_GRAPH_NODE
#define TSP_GRAPH_NODE

#include <tsp/graph/graph_link.hpp>
#include <tsp/utils/collection.hpp>

#include <iostream>

template <typename T>
class GraphNode {

    private:
        T *content;
        std::vector<GraphLink*> *links;

    public:
        GraphNode(T *content) {
            this->content = content;
            links = new std::vector<GraphLink*>();
        }

        void addLink(GraphNode<T> *to, float cost) {
            GraphLink* link = new GraphLink(to, cost);
            links->push_back(link);
        }

        unsigned short getNumberLinks() {
            return links->size();
        }

        T* getContent() {
            return content;
        }

        std::vector<GraphLink*>* getLinks() {
            return links;
        }
};

#endif