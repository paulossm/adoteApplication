#ifndef FAMILIA_H_
#define FAMILIA_H_

#include <Wt/WContainerWidget>
#include "Pais.h"
#include "Crianca.h"


class Familia : public Wt::WContainerWidget
{
    public:
        Familia();
        virtual ~Familia();
    private:
        Pais *pais;
        Crianca pretendida;
        std::string sobrenome;

        Familia *proximo;
        Familia *anterior;

        void cadastrarMembro();
        void excluirPais();
        void atualizarFamilia();
        void atualizarCriancaPretendida();
};

#endif // FAMILIA_H_
