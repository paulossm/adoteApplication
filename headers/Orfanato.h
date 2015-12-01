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

        ListaCriancas *minhasCriancas;

        void registrarAdoção(Criança *criança, Familia *pais);

        void salvarDados();
        void atualizarDados();
        void dashboard();

    protected:
        Wt::WLineEdit *nome_;
        Wt::WLineEdit *estado_;
        Wt::WLineEdit *cidade_;
        Wt::WLineEdit *bairro_;
        Wt::WLineEdit *rua_;
        Wt::WLineEdit *numero_;

};

#endif // ORFANATO_H
