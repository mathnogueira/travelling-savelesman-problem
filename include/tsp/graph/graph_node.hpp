#ifndef TSP_GRAPH_NODE
#define TSP_GRAPH_NODE

#include <tsp/graph/graph_link.hpp>
#include <tsp/utils/collection.hpp>

template <typename T>
class GraphNode {

    private:
        T *content;
        Collection<GraphLink*> links;

    public:
        GraphNode(T *content) {
            this->content = content;
        }

        void addLink(GraphNode<T> *to, float cost) {
            GraphLink* link = new GraphLink(to, cost);
            links.add(link);
        }

        unsigned short getNumberLinks() {
            return links.count();
        }

        T* getContent() {
            return content;
        }

        Collection<GraphLink*>* getLinks() {
            return &links;
        }
};

#endif