#ifndef CRIANCAPRETENDIDA_H
#define CRIANCAPRETENDIDA_H

#include "Crianca.h"

class CriancaPretendida : public Wt::WContainerWidget
{
    public:
        CriancaPretendida(Wt::WContainerWidget *parent = 0);
        virtual ~CriancaPretendida();

    private:
        std::string *sexo;
        int idadeInf;
        int idadeSup;

        Wt::WStackedWidget *view_;
        Wt::WLineEdit *idadeI;
        Wt::WLineEdit *idadeS;
        Wt::WRadioButton *sexoBtns;
        Wt::WButtonGroup *group;
};

#endif // CRIANCAPRETENDIDA_H
