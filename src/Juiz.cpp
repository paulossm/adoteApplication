#include "Juiz.h"

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WBreak>

using namespace Wt;

Juiz::Juiz(Wt::WContainerWidget *parent = 0):
(WContainerWidget (parent))
{
    listaFamilias = NULL;

    Adote::mainStack_->clear();

    WText *title = new WText("<h1>Bem Vindo ao perfil Jurídico</h1>");
    Adote::mainStack_->addWidget(title);

    Adote::mainStack_->addWidget(new WBreak());

    // Verificar se ele tem dados no banco (Consultar Banco de Dados)

    title = new WText("<p>Selecione uma ação:</p>");
    Adote::mainStack_->addWidget(title);

    addFamilia_ = new WPushButton("Adicionar Familia", Adote::mainStack_);
    addFamilia_->clicked().connect(this, &Juiz::adicionarFamilia);
    Adote::mainStack_->addWidget(addFamilia_);

    delFamilia_ = new WPushButton("Excluir Familia", Adote::mainStack_);
    delFamilia_->clicked().connect(this, &Juiz::excluirFamilia);
    Adote::mainStack_->addWidget(delFamilia_);
}
Juiz::~Juiz()
{
    //dtor
}

void Juiz::adicionarFamilia(){
    if(listaFamilias == NULL)
        listaFamilias = new Familia;
    else {
        // Criar uma familia nova
        Familia* nova = new Familia;
        if(nova == NULL)
            return;

        // Adicionar a lista de familias
        Familia* auxiliar = listaFamilias;
        while(auxiliar != NULL)
            auxiliar = auxiliar->proximo;
        auxiliar->proximo = nova;
        nova->anterior = auxiliar;
    }
}
void Juiz::excluirFamilia(){

}
