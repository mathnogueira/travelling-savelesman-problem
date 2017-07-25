#pragma once

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