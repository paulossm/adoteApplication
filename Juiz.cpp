#include "headers/Juiz.h"

#include <Wt/WApplication>
#include <Wt/WText>
#include <Wt/WPushButton>
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WTemplate>

using namespace Wt;

Juiz::Juiz(Wt::WContainerWidget *parent = 0):
(WContainerWidget (parent))
{
    listaFamilias = NULL;
    WTemplate *window = new WTemplate("App.dashboard");
    window->bindWidget("profile", "Órgão Juridico");

    addFamilia_ = new WPushButton("Adicionar Familia");
    addFamilia_->clicked().connect(this, &Juiz::adicionarFamilia);
    window->bindWidget(addFamilia_);

    delFamilia_ = new WPushButton("Excluir Familia");
    delFamilia_->clicked().connect(this, &Juiz::excluirFamilia);
    window->bindWidget(delFamilia_);

    buscarCrianca_ = new WPushButton("Buscar Criança Por Perfil");
    buscarCrianca_->clicked().connect(this, &Juiz::buscarCrianca);
    window->bindWidget(buscarCrianca_);
}
Juiz::~Juiz()
{
    //dtor
}

void Juiz::adicionarFamilia(){
    if(listaFamilias == NULL){
        listaFamilias = new Familia;
        Adote::mainStack_->addWidget(new WText("Família cadastrada."));
    }

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

void Juiz::imprimirFamilias(){
    WContainerWidget *lista = new WContainerWidget(Adote::mainStack_);
    if(listaFamilias == NULL)
        lista->addWidget(new WText("Não há cadastros de famílias aptas para a adoção."));
    else {
        Familia *auxiliar = listaFamilias;
        Pais *auxiliares = auxiliar->pais;
        lista->addWidget(new WText("<h3>Famílias aptas para a adoção:</h3><ul>"));
        while(auxiliar != NULL){
            lista->addWidget(new WText("<li><p><strong>" + auxiliar->sobrenome + "</strong></p>"));
            while(auxApp.searchChildiliares != NULL){
                lista->addWidget(new WText(auxiliares->nome + " "));
                auxiliares = auxiliares->proximo;
            }
            lista->addWidget(new WText("</li>"))
            auxiliar = auxiliar->proximo;
        }
    }
}

void Juiz::dashboard(Wt::WContainerWidget *parent = 0){
    new Juiz();
}

void Juiz::buscarCrianca(){
    caracteristicas = new CriancaPretendida();
}
