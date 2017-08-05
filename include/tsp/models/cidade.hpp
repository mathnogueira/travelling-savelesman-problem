#ifndef TSP_CIDADE
#define TSP_CIDADE

#include <tsp/utils/identificable.hpp>
#include <tsp/utils/id_generator.hpp>

class Cidade : public Identificable {

    private:
        float premio;
        float prejuizo;

    public:
        Cidade(unsigned int id);
        Cidade(unsigned int id, float premio, float prejuizo);
        Cidade(IdGenerator &idGenerator, float premio, float prejuizo);
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