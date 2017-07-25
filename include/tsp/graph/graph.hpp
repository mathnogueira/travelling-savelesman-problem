#pragma once

#include <tsp/graph/graph_node.hpp>
#include <tsp/graph/graph_link.hpp>

#include <vector>

template <typename T>
class Graph {

    private:
        std::vector<GraphNode<T> > nodes;

        void addIfDoesntExist(GraphNode<T> &node) {
            for (short i = 0; i < nodes->size(); ++i) {
                if (node.getContent() == nodes.get(i).getContent()) return;
            }
            this->nodes.push_back(node);
        }

    public:
        Graph() {}
        ~Graph() {}

        void add(T &source, T &destination, float cost) {
            GraphNode<T> src(&source);
            GraphNode<T> dest(&destination);

            GraphLink<T> link(src, dest, cost);

            addIfDoesntExist(src);
            addIfDoesntExist(dest);
            
        }
};