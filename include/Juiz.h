#ifndef JUIZ_H
#define JUIZ_H

#include <Wt/WContainerWidget>
#include "Orfanato.h"
#include "Criança.h"
#include "Familia.h"

class Juiz : public Wt::WContainerWidget
{
    public:
        Juiz(const std::string &name, Wt::WContainerWidget *parent = 0);
        virtual ~Juiz();

    private:
        struct ListaFamilias {
            Familia *familia;
            ListaFamilias *proximo;
        };

        void adicionarFamilia();
        void excluirFamilia();
        void buscarCriança();
};

#endif // JUIZ_H
