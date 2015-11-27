#include "Orfanato.h"

#include <Wt/WAnchor>
#include <Wt/WText>
#include <Wt/WStackedWidget>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>
#include <Wt/WApplication>
#include <Wt/Auth/AuthWidget>
#include <Wt/WButtonGroup>
#include <Wt/WRadioButton>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WString>

using namespace Wt;

Orfanato::Orfanato(Wt::WContainerWidget *parent = 0):
WContainerWidget(parent)
{
    Adote::mainStack_->clear();
    WText *title_ = new WText("<h1>Cadastrar Orfanato ou Casa de Abrigo</h1>", Adote::mainStack_);
    nome_ = new WLineEdit("Nome do Orfanato ou Casa de Abrigo: ");
    Adote::mainStack_->addWidget(nome_);

    WText *endereco_ = new WText("Endereço:");
    Adote::mainStack_->addWidget(endereco_);

    Adote::mainStack_->addWidget(new WBreak());

    estado_ = new WLineEdit("UF: ", Adote::mainStack_);
    cidade_ = new WLineEdit("Cidade: ", Adote::mainStack_);
    bairro_ = new WLineEdit("Bairro: ", Adote::mainStack_);
    rua_ = new WLineEdit("Rua: ", Adote::mainStack_);
    numero_ = new WLineEdit("Nº: ", Adote::mainStack_);

    minhasCriancas = new ListaCriancas;

    Wt::WPushButton *cadastrar_ = new Wt::WPushButton("Cadastrar");
    cadastrar_->clicked().connect(this, &Orfanato::salvarDados);
    Adote::mainStack_->addWidget(cadastrar_);
}

void Orfanato::salvarDados(){
    nome->text() = nome_->valueText();
    Endereco.estado->text() = estado_->valueText();
    Endereco.cidade->text() = cidade_->valueText();
    Endereco.bairro->text() = bairro_->valueText();
    Endereco.rua->text() = rua_->valueText();
    Endereco.numero = (int) numero_->valueText(); // Ver isso aqui (string >> int)
}

void Orfanato::atualizarDados(){
    Adote::mainStack_->clear();
    WText *title_ = new WText("<h1>Atualizar Orfanato ou Casa de Abrigo</h1>", Adote::mainStack_);
    Adote::mainStack_->addWidget(nome);
    Adote::mainStack_->addWidget(new WBreak());
    Adote::mainStack_->addWidget(new WText("Endereço: "), new WBreak());
    Adote::mainStack_->addWidget(estado_);
    Adote::mainStack_->addWidget(new WBreak());
    Adote::mainStack_->addWidget(cidade_);
    Adote::mainStack_->addWidget(new WBreak());
    Adote::mainStack_->addWidget(bairro_);
    Adote::mainStack_->addWidget(new WBreak());
    Adote::mainStack_->addWidget(rua_);
    Adote::mainStack_->addWidget(new WBreak());
    Adote::mainStack_->addWidget(numero_);
    Adote::mainStack_->addWidget(new WBreak());

    Wt::WPushButton *atualizar_ = new Wt::WPushButton("Atualizar");
    atualizar_->clicked().connect(this, &Orfanato::salvarDados);
    Adote::mainStack_->addWidget(atualizar_);
}

Orfanato::~Orfanato()
{
    //dtor
}



