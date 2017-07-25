#ifndef TSP_GRAPH_NODE
#define TSP_GRAPH_NODE

#include <tsp/graph/graph_link.hpp>
#include <vector>

template <typename T>
class GraphNode {

    private:
        T *content;
        std::vector<GraphLink*> links;

    public:
        GraphNode(T *content) {
            this->content = content;
        }

        void addLink(GraphLink *link) {
            links.push_back(link);
        }

        unsigned short getNumberLinks() {
            return links.size();
        }

        T* getContent() {
            return content;
        }
};

#endif