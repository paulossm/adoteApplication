#ifndef JUIZ_H_
#define JUIZ_H_

#include <Wt/WStackedWidget>

#include "Crianca.h"
#include "Familia.h"
#include "CriancaPretendida.h"

class Juiz : public Wt::WStackedWidget
{
    public:
        Juiz(Wt::WStackedWidget *parent = 0);
        virtual ~Juiz();

    private:
        Familia *listaFamilias;
        CriancaPretendida *caracteristicas;

        Wt::WTemplate *view_;
        Wt::WPushButton *addFamilia_;
        Wt::WPushButton *delFamilia_;
        Wt::WPushButton *SolicitarVinculo_;
        Wt::WPushButton *buscarCrianca_;

        void adicionarFamilia();
        void excluirFamilia();
        void buscarCrianca();
};

#endif // JUIZ_H_
