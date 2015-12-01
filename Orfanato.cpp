#include "headers/Orfanato.h"

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
#include <Wt/WTemplate>
#include <fstream>

using namespace Wt;

Orfanato::Orfanato(Wt::WStackedWidget *parent):
WStackedWidget(parent)
{
    this->minhasCriancas = NULL;
    view_ = new WTemplate(WString::tr("App.dashboard"));
    view_->bindWidget("profile", new WText("Orfanato/Abrigo"));

    WPushButton *addCrianca = new WPushButton("Adicionar Crianca");
    addCrianca->setStyleClass("btn-block btn btn-primary");
    addCrianca->clicked().connect(this, &Orfanato::cadastrarCrianca);
    view_->bindWidget("action1", addCrianca);

    WPushButton *delCrianca_ = new WPushButton("Excluir Crianca");
    delCrianca_->setStyleClass("btn btn-danger btn-block");
    delCrianca_->clicked().connect(this, &Orfanato::excluirCrianca);
    view_->bindWidget("action2", delCrianca_);

    WPushButton *listar_ = new WPushButton("Criancas Cadastradas");
    listar_->setStyleClass("btn btn-block");
    listar_->clicked().connect(this, &Orfanato::listarCriancas);
    view_->bindWidget("action3", listar_);

    parent->clear();
    parent->addWidget(view_);
}

//void Orfanato::salvarDados(){
////    nome->text() = nome_->valueText();
////    Endereco.estado->text() = estado_->valueText();
////    Endereco.cidade->text() = cidade_->valueText();
////    Endereco.bairro->text() = bairro_->valueText();
////    Endereco.rua->text() = rua_->valueText();
////    Endereco.numero = (int) numero_->valueText(); // Ver isso aqui (string >> int)
////    dashboard();
//}
//
//void Orfanato::atualizarDados(){
////    Adote::mainStack_->clear();
////    WText *title_ = new WText("<h1>Atualizar Orfanato ou Casa de Abrigo</h1>", Adote::mainStack_);
////    Adote::mainStack_->addWidget(nome);
////    Adote::mainStack_->addWidget(new WBreak());
////    Adote::mainStack_->addWidget(new WText("Endereço: "), new WBreak());
////    Adote::mainStack_->addWidget(estado_);
////    Adote::mainStack_->addWidget(new WBreak());
////    Adote::mainStack_->addWidget(cidade_);
////    Adote::mainStack_->addWidget(new WBreak());
////    Adote::mainStack_->addWidget(bairro_);
////    Adote::mainStack_->addWidget(new WBreak());
////    Adote::mainStack_->addWidget(rua_);
////    Adote::mainStack_->addWidget(new WBreak());
////    Adote::mainStack_->addWidget(numero_);
////    Adote::mainStack_->addWidget(new WBreak());
////
////    Wt::WPushButton *atualizar_ = new Wt::WPushButton("Atualizar");
////    atualizar_->clicked().connect(this, &Orfanato::salvarDados);
////    Adote::mainStack_->addWidget(atualizar_);
//}
//void Orfanato::dashboard(Wt::WContainerWidget *parent = 0){
////    WTemplate *window = new WTemplate(WString::tr("App.dashboard"));
////    window->bindWidget("profile", new WText("Orfanato"));
////
////    WPushButton *addCrianca = new WPushButton("Cadastrar Crianca");
////    addCrianca->clicked().connect(boost::BOOST_BIND(&ListaCriancas::adicionarCrianca, minhasCriancas);
////
////    WPushButton *deleteCrianca = new WPushButton("Excluir Crianca");
////    deleteCrianca->clicked().connect(this, &ListaCriancas::removerCrianca);
////
////    window->bindWidget("actions", addCrianca);
////    window->bindWidget("actions", deleteCrianca);
////
////    parent->clear();
////    parent->addWidget(window);
//}
//
//void Orfanato::preservarDados(){
////    fstream database ("criancas/lista.txt", ios::ate, 0);
////    if(!database){
////        new WTemplate(WString::fromUTF8("Não foi possível salvar os dados no banco."));
////    }
////    ListaCriancas *aux = minhasCriancas;
////    while(aux != NULL){
////        database << aux->crianca->nome << " " << aux->crianca->sexo << " " << aux->crianca->idade << endl;
////        aux = aux->proximo;
////    }
//}

Orfanato::~Orfanato()
{
    //dtor
}
void Orfanato::listarCriancas(){
}
void Orfanato::cadastrarCrianca(){
    if(this->minhasCriancas == NULL){
        this->minhasCriancas = new ListaCriancas;
    }
    else {
        this->minhasCriancas->adicionarCrianca();
    }
}
void Orfanato::excluirCrianca(){

}


