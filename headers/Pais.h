#ifndef PAIS_H
#define PAIS_H

#include <Wt/WContainerWidget>


class Pais : public Wt::WContainerWidget
{
    public:
        Pais(Wt::WContainerWidget *parent = 0);
        virtual ~Pais();
    protected:
    private:
        std::string nome;
        std::string sexo;
        int idade;

        Pais *proximo;
        Pais *anterior;

        Wt::WLineEdit *nome_;
        Wt::WRadioButton *sexo_;
        Wt::WButtonGroup *opcoes_;
        Wt::WLineEdit *idade_;

        void atribuirGenero();
        void salvarDadosPai();
        void atualizarDados();
};

#endif // PAIS_H
