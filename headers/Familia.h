#ifndef FAMILIA_H
#define FAMILIA_H

#include <Wt/WContainerWidget>
#include "Pais.h"
#include "Criança.h"


class Familia : public Wt::WContainerWidget
{
    public:
        Familia();
        virtual ~Familia();
    private:
        Pais *pais;
        Criança pretendida;
        std::string sobrenome;

        Familia *proximo;
        Familia *anterior;

        void cadastrarMembro();
        void excluirPais();
        void atualizarFamilia();
        void atualizarCriancaPretendida();
};

#endif // FAMILIA_H
