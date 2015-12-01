#include "headers/CriancaPretendida.h"

#include <Wt/WButtonGroup>
#include <Wt/WStackedWidget>
#include <Wt/WTemplate>
#include <Wt/WStackedWidget>

using namespace Wt;
CriancaPretendida::CriancaPretendida(Wt::WStackedWidget *parent = 0)
{
    view_ = new WStackedWidget(parent);

    WTemplate *window = new WTemplate("App.searchChild");
    window->bindWidget("action", "Buscar Crianças por Características:");

    idadeI = new WLineEdit("Idade mínima");
    idadeS = new WLineEdit("Idade maixma");
    group = new WButtonGroup();
    WRadioButton *masc = new WRadioButton("masculino");
    WRadioButton *fem = new WRadioButton("feminino");

    group->addButton(masc, 1);
    group->addButton(fem, 2);

    window->bindWidget("age-lower", idadeI);
    window->bindWidget("age-higher", idadeS);
    window->bindWidget("sex", group);

    WPushButton *buscar = new WPushButton("Buscar");
    buscar->clicked().connect(this, &CriancaPretendida::salvarDados);

    window->bindWidget("search-btn", buscar);
    view_->addWidget(window);
}

void CriancaPretendida::salvarDados(){
    this->idadeInf = (int) idadeI->valueText();
    this->idadeSup = (int) idadeS->valueText();
    this->sexoBtns = group->checkedButton();
}

CriancaPretendida::~CriancaPretendida()
{
    //dtor
}
