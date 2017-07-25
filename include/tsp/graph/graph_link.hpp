#ifndef TSP_GRAPH_LINK
#define TSP_GRAPH_LINK

class GraphLink {

    private:
        void *to;
        float cost;

    public:

        GraphLink(void *dest, float cost) {
            this->to = dest;
            this->cost = cost;
        }

        void* getDestination() {
            return this->to;
        }

        float getCost() {
            return this->cost;
        }
};

#endif