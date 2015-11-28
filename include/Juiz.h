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

        Wt::WPushButton *addFamilia_;
        Wt::WPushButton *delFamilia_;

        void adicionarFamilia();
        void excluirFamilia();
};

#endif // JUIZ_H
