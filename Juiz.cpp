#include "headers/Juiz.h"
#include "headers/Familia.h"
#include "headers/CriancaPretendida.h"

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WBreak>
#include <Wt/WStackedWidget>
#include <Wt/WTemplate>

using namespace Wt;

Juiz::Juiz(Wt::WStackedWidget *parent):
WStackedWidget(parent)
{
    listaFamilias = NULL;
    view_ = new WTemplate(WString::tr("App.dashboard"));
    view_->bindWidget("profile", new WText("Orgao Juridico"));


    addFamilia_ = new WPushButton("Adicionar Familia");
    addFamilia_->setStyleClass("btn-block btn btn-primary");
    addFamilia_->clicked().connect(this, &Juiz::adicionarFamilia);
    view_->bindWidget("action1", addFamilia_);

    delFamilia_ = new WPushButton("Excluir Familia");
    delFamilia_->setStyleClass("btn btn-danger btn-block");
    delFamilia_->clicked().connect(this, &Juiz::excluirFamilia);
    view_->bindWidget("action2", delFamilia_);

    buscarCrianca_ = new WPushButton("Buscar Crianca Por Perfil");
    buscarCrianca_->setStyleClass("btn btn-block");
    buscarCrianca_->clicked().connect(this, &Juiz::buscarCrianca);
    view_->bindWidget("action3", buscarCrianca_);

    parent->clear();
    parent->addWidget(view_);

}
Juiz::~Juiz()
{
    //dtor
}

void Juiz::adicionarFamilia(){
//    if(listaFamilias == NULL){
//        listaFamilias = new Familia;
//        Adote::mainStack_->addWidget(new WText("Família cadastrada."));
//    }
//
//    else {
//        // Criar uma familia nova
//        Familia* nova = new Familia;
//        if(nova == NULL)
//            return;
//
//        // Adicionar a lista de familias
//        Familia* auxiliar = listaFamilias;
//        while(auxiliar != NULL)
//            auxiliar = auxiliar->proximo;
//        auxiliar->proximo = nova;
//        nova->anterior = auxiliar;
//    }
}
void Juiz::excluirFamilia(){

}

void Juiz::buscarCrianca(){
//    this->caracteristicas = new CriancaPretendida();
//    procurarCrianca( caracteristicas->idadeInf, caracteristicas->idadeSup, caracteristicas->sexo);
}


