#ifndef LISTACRIANCAS_H
#define LISTACRIANCAS_H

#include "Crianca.h"

class ListaCriancas
{
    public:
        ListaCriancas();
        virtual ~ListaCriancas();

    private:
        Crianca *crianca;
        ListaCriancas *proximo;

        void listarCriancas();
        void removerCrianca();
        void adicionarCrianca();
        ListaCriancas* buscarCrianca(int idadeInf = 0, int idadeSup = 0, std::string sexo = "");
};

#endif // LISTACRIANCAS_H
