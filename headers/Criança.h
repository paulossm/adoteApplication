#ifndef CRIANÇA_H
#define CRIANÇA_H

#include <Wt/WContainerWidget>

class Criança : public Wt::WContainerWidget
{
    public:
        Criança(Wt::WContainerWidget *parent = 0);
        virtual ~Criança();

    private:
        std::string *nome;
        std::string *sexo;
        int idade;

        Fila* paisPretendentes;

        Wt::WLineEdit *name;
        Wt::WButtonGroup *selectSexo;
        Wt::WRadioButton *sexoCrianca;

        /* Operações com a Criança */
        void salvarDadosCrianca();
        void atualizarDados();


};



#endif // CRIANÇA_H
