#ifndef CRIANCAPRETENDIDA_H
#define CRIANCAPRETENDIDA_H

#include "Criança.h"

class CriancaPretendida : public Wt::WContainerWidget
{
    public:
        CriancaPretendida(Wt::WContainerWidget *parent);
        virtual ~CriancaPretendida();

    private:
        std::string *sexo;
        int idadeInf;
        int idadeSup;

        Wt::WLineEdit *idadeI;
        Wt::WLineEdit *idadeS;
        Wt::WRadioButton *sexoBtns;
        Wt::WButtonGroup *group;
};

#endif // CRIANCAPRETENDIDA_H
