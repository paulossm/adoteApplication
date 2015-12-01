#ifndef CRIANCA_H
#define CRIANCA_H

#include <Wt/WContainerWidget>
#include "Pais.h"

class Crianca : public Wt::WContainerWidget
{
    public:
        Crianca(Wt::WContainerWidget *parent = 0);
        virtual ~Crianca();

    private:
        std::string *nome;
        std::string *sexo;
        int idade;

        Pais *paisPretendentes;

        Wt::WLineEdit *name;
        Wt::WButtonGroup *selectSexo;
        Wt::WRadioButton *sexoCrianca;

        void salvarDadosCrianca();
};



#endif // CRIANCA_H
