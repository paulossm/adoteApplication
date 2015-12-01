#ifndef JUIZ_H
#define JUIZ_H

#include <Wt/WContainerWidget>

#include "Criança.h"
#include "Familia.h"

class Juiz : public Wt::WContainerWidget
{
    public:
        Juiz(Wt::WContainerWidget *parent = 0);
        virtual ~Juiz();

    private:
        Familia *listaFamilias;
        CriancaPretendida *caracteristicas;

        Wt::WPushButton *addFamilia_;
        Wt::WPushButton *delFamilia_;
        Wt::WPushButton *SolicitarVinculo_;
        Wt::WPushButton *buscarCrianca_;

        void adicionarFamilia();
        void excluirFamilia();
        void dashboard(Wt::WContainerWidget *parent = 0);
        void buscarCrianca();
};

#endif // JUIZ_H
