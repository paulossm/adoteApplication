#ifndef PAIS_H
#define PAIS_H

#include <Wt/WContainerWidget>


class Pais : public Wt::WContainerWidget
{
    public:
        Pais(Wt::WContainerWidget *parent = 0);
        virtual ~Pais();
    protected:
    private:
        struct Localidade{
            Wt::WText *estado;
            Wt::WText *cidade;
            Wt::WText *bairro;
            Wt::WText *rua;
            int numero;
        };

};

#endif // PAIS_H
