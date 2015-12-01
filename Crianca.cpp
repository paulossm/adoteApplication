#include <Wt/WAnchor>
#include <Wt/WText>
#include <Wt/WApplication>
#include <Wt/WRadioButton>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WButtonGroup>

#include "headers/Crianca.h"
#include "headers/Pais.h"

using namespace Wt;

Crianca::Crianca(Wt::WContainerWidget *parent):
    WContainerWidget(parent)
{
    WTemplate *view = new WTemplate(WString::tr("App.nova-crianca"));
    WText *title = new WText("Cadastrar nova crianca:");
    view->bindWidget("action", title);

    name = new WLineEdit("Nome: ");
    view->bindWidget("name", name);

    WText *text = new WText("Sexo: ");
    view->bindWidget("sex", text);

    selectSexo = new WButtonGroup();
    WRadioButton *optionSexo = new WRadioButton("masculino");
    selectSexo->addButton(optionSexo, 1);

    optionSexo = new WRadioButton("feminino");
    selectSexo->addButton(optionSexo, 2);

    view->bindWidget("group", selectSexo);

    Wt::WPushButton *cadastrar = new Wt::WPushButton("Cadastrar");
    cadastrar->clicked().connect(this, &Crianca::salvarDadosCrianca);
    view->bindWidget("button", cadastrar);

    WContainerWidget *container = new WContainerWidget();
    WStackedWidget *stacked = new WStackedWidget(container);
    stacked->addWidget(view);
}

void Crianca::salvarDadosCrianca(){
    this->nome->text() = name->valueText();
    this->sexo->text() = selectSexo->checkedButton()->text();
    this->sexoCrianca = selectSexo->checkedButton();
}

Crianca::~Crianca()
{
    //dtor
}


