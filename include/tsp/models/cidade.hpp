#ifndef TSP_CIDADE
#define TSP_CIDADE

#include <tsp/utils/identificable.hpp>

class Cidade : public Identificable {

    private:
        float premio;
        float prejuizo;

        static int nextId;

    public:
        Cidade();
        ~Cidade();

        float getPrejuizo();
        void setPrejuizo(float prejuizo);

        float getPremio();
        void setPremio(float premio);

        int compareTo(Identificable &other) {
            return id - other.getId();
        }

};

#endif