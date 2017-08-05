#ifndef TSP_UTILS_ID_GENERATOR
#define TSP_UTILS_ID_GENERATOR

class IdGenerator {

    private:
        unsigned int nextId;

    public:
        IdGenerator();
        
        unsigned int generateId();

};

#endif