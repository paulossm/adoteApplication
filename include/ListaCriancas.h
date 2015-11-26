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
};

#endif // LISTACRIANCAS_H
