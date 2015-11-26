#ifndef ORFANATO_H
#define ORFANATO_H

#include <Wt/WContainerWidget>
#include "Criança.h"
#include "Familia.h"

class Orfanato : public Wt::WContainerWidget
{
    public:
        Orfanato(Wt::WContainerWidget *parent = 0);
        virtual ~Orfanato();

    private:

        Wt::WText *nome;
        struct Endereco {
            Wt::WText *estado;
            Wt::WText *cidade;
            Wt::WText *bairro;
            Wt::WText *rua;
            int numero;
        };

        struct ListaCriancas {
            Criança *crianca;
            struct ListaCriancas *proximo;
        };

        void listarCriancas();
        void removerCrianca();
        void adicionarCrianca();
        void removerCrianca();
        void registrarAdoção(Criança *criança, Familia *pais);

        void salvarDados();
        void atualizarDados();
};

#endif // ORFANATO_H
