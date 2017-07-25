#pragma once

#include <tsp/graph/graph_node.hpp>

template <typename T>
class GraphLink {

    private:
        GraphNode<T> *from;
        GraphNode<T> *to;
        float cost;

    public:

        GraphLink(GraphNode<T> &source, GraphNode<T> &dest, float cost) {
            this->from = &source;
            this->to = &dest;
            this->cost = cost;
        }
};