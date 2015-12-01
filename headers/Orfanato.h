#ifndef ORFANATO_H_
#define ORFANATO_H_

#include <Wt/WStackedWidget>
#include <Wt/WTemplate>

#include "ListaCriancas.h"

class Orfanato : public Wt::WStackedWidget
{
    public:
        Orfanato(Wt::WStackedWidget *parent = 0);
        virtual ~Orfanato();

    private:
        ListaCriancas *minhasCriancas;

        void cadastrarCrianca();
        void excluirCrianca();
        void listarCriancas();


    protected:
        Wt::WTemplate *view_;
        Wt::WLineEdit *nome_;
        Wt::WLineEdit *estado_;
        Wt::WLineEdit *cidade_;
        Wt::WLineEdit *bairro_;
        Wt::WLineEdit *rua_;
        Wt::WLineEdit *numero_;

};

#endif // ORFANATO_H_
