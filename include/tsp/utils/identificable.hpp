#ifndef TSP_UTILS_IDENTIFICABLE
#define TSP_UTILS_IDENTIFICABLE

class Identificable {

    protected:
        int id;

    public:
        int getId() { return id; }
        bool equals(Identificable &other) { return compareTo(other) == 0; }
        virtual int compareTo(Identificable &other) = 0;

};

#endif