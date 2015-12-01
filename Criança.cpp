#include <Wt/WAnchor>
#include <Wt/WText>
#include <Wt/WApplication>
#include <Wt/WRadioButton>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WButtonGroup>

#include "headers/Criança.h"

using namespace Wt;

Criança::Criança(Wt::WContainerWidget *parent = 0):
    WContainerWidget(parent)
{
    Adote::mainStack_->clear();
    WText *title = new WText("<h1>Dados da Nova Criança:</h1>");
    addWidget(title);

    name = new WLineEdit("Nome: ", Adote::mainStack_);
    sexo = new WText("Sexo: ", Adote::mainStack_);
    selectSexo = new WButtonGroup(Adote::mainStack_);
    WRadioButton *optionSexo = new WRadioButton("masculino", Adote::mainStack_);
    selectSexo->addButton(optionSexo, 1);
    optionSexo = new WRadioButton("feminino", Adote::mainStack_);
    selectSexo->addButton(optionSexo, 2);
    selectSexo->setSelectedButtonIndex(0)

    WPushButton *criar = new WPushButton("Cadastrar", Adote::mainStack_);

    Wt::WPushButton *cadastrar = new Wt::WPushButton("Cadastrar");
    cadastrar->clicked().connect(this, &Crianca::salvarDadosCrianca);
    Adote::mainStack_->addWidget(cadastrar);
}

void Criança::salvarDadosCrianca(){
    nome->text() = name->valueText();
    sexo->text() = selectSexo->checkedButton()->text();
    sexoCrianca = selectSexo->checkedButton();
}

void Criança::atualizarDados(){
    Adote::mainStack_->clear();
    WText *title = new WText("<h1>Atualizar Dados da Criança:</h1>");
    addWidget(title);

    name = new WLineEdit("Nome: ", Adote::mainStack_);
    name->setValueText(nome);
    sexo = new WText("Sexo: ", Adote::mainStack_);
    selectSexo = new WButtonGroup(Adote::mainStack_);
    WRadioButton *optionSexo = new WRadioButton("masculino", Adote::mainStack_);
    selectSexo->addButton(optionSexo, 1);
    optionSexo = new WRadioButton("feminino", Adote::mainStack_);
    selectSexo->addButton(optionSexo, 2);
    selectSexo->setSelectedButtonIndex(selectSexo->id(sexoCrianca)-1);

    WPushButton *criar = new WPushButton("Atualizar", Adote::mainStack_);

    Wt::WPushButton *atualizar = new Wt::WPushButton("Atualizar");
    atualizar->clicked().connect(this, &Crianca::salvarDadosCrianca);
    Adote::mainStack_->addWidget(atualizar);
}

Criança::~Criança()
{
    //dtor
}


