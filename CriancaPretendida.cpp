#include "headers/CriancaPretendida.h"

#include <Wt/WButtonGroup>
CriancaPretendida::CriancaPretendida()
{
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
}

void CriancaPretendida::salvarDados(){
    idadeInf = (int) idadeI->valueText();
    idadeSup = (int) idadeS->valueText();
    sexoBtns = group->checkedButton();
}

CriancaPretendida::~CriancaPretendida()
{
    //dtor
}
