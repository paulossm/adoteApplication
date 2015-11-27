#ifndef LISTACRIANCAS_H
#define LISTACRIANCAS_H

#include "Criança.h"

class ListaCriancas
{
    public:
        ListaCriancas();
        virtual ~ListaCriancas();

    private:
        Criança *crianca;
        ListaCriancas *proximo;

        void listarCriancas();
        void removerCrianca();
        void adicionarCrianca();
};

#endif // LISTACRIANCAS_H
