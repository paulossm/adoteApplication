#include "Pais.h"

#include <Wt/WAnchor>
#include <Wt/WText>
#include <Wt/WApplication>
#include <Wt/WRadioButton>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WButtonGroup>

using namespace Wt;

Pais::Pais(Wt::WContainerWidget *parent = 0):
(WContainerWidget parent)
{
    nome = "";
    sexo = "";
    idade = -1;
    proximo = NULL;
    anterior = NULL;

    Pais *auxiliar = pais;

    Adote::mainStack_->clear();
    WText *title = new WText("<h1>Cadastrar novo(a) Pai/Mãe adotivo(a):</h1>");
    addWidget(title);

    nome_ = new WLineEdit("Nome: ", Adote::mainStack_);
    opcoes_ = new WButtonGroup(Adote::mainStack_);
    sexo_ = new WRadioButton("masculino", Adote::mainStack_);
    opcoes_->addButton(sexo_);
    sexo_ = new WRadioButton("feminino", Adote::mainStack_);
    opcoes_->addButton(sexo_);

    opcoes_->checkedChanged().connect(this, &Pais::atribuirGenero);

    idade_ = new WLineEdit("idade: ", Adote::mainStack_);

    WPushButton *cadastrar_ = new WPushButton("Cadastrar", Adote::mainStack_);
    cadastrar_->clicked().connect(this, &Pais::salvarDadosPai);
    Adote::mainStack_->addWidget(cadastrar_);
}

void Pais::atribuirGenero(){
    sexo_ = opcoes_->checkedButton();
}

void Pais::salvarDadosPai(){
    nome = nome_->text();
    sexo = sexo_->text();
    idade = (int) idade_->text();
}

void Pais::atualizarDados(){
    Adote::mainStack_->clear();
    WText *title = new WText("<h1>Atualizar Dados do(a) Pai/Mãe adotivo(a):</h1>");
    addWidget(title);

    nome_ = new WLineEdit("Nome: ", Adote::mainStack_);
    opcoes_ = new WButtonGroup(Adote::mainStack_);
    sexo_ = new WRadioButton("masculino", Adote::mainStack_);
    opcoes_->addButton(sexo_);
    sexo_ = new WRadioButton("feminino", Adote::mainStack_);
    opcoes_->addButton(sexo_);

    opcoes_->checkedChanged().connect(this, &Pais::atribuirGenero);

    idade_ = new WLineEdit("idade: ", Adote::mainStack_);

    WPushButton *atualizar_ = new WPushButton("Atualizar", Adote::mainStack_);
    atualizar_->clicked().connect(this, &Pais::salvarDadosPai);
    Adote::mainStack_->addWidget(atualizar_);
}

Pais::~Pais()
{
    //dtor
}
