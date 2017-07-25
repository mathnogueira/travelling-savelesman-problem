#ifndef TSP_CIDADE
#define TSP_CIDADE

class Cidade {

    private:
        float premio;
        float prejuizo;

    public:
        Cidade();
        ~Cidade();

        float getPrejuizo();
        void setPrejuizo(float prejuizo);

        float getPremio();
        void setPremio(float premio);

};

#endif