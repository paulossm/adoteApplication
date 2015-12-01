#include <Wt/WText>
#include <Wt/WApplication>

#include "headers/ListaCriancas.h"
#include "headers/Crianca.h"

using namespace Wt;

ListaCriancas::ListaCriancas()
{
    this->crianca = NULL;
    this->proximo = NULL;
}

ListaCriancas::~ListaCriancas()
{
    //dtor
}

void ListaCriancas::listarCriancas(ListaCriancas *lista){
    if(!lista){
        lista = new ListaCriancas;
    }
    ListaCriancas *atual = lista;
    if(atual.crianca == NULL)
        return;
    WText *imprimir;
    while(atual.crianca != NULL){
        imprimir = new WText("<ul>");
        imprimir += "<li>Nome: " + atual.crianca.nome  + "</li>";
        imprimir += "<li>Sexo: " + atual.crianca.sexo + "</li>";
        imprimir += "<li>Idade: " + atual.crianca.idade + "</li>";
        imprimir += "</ul>";
        Adote::mainStack_->addWidget(imprimir);
        atual = atual->proximo;
    }
}

void ListaCriancas::removerCrianca(ListaCriancas *lista ){
//    ListaCriancas *cabeca = lista,
//    *auxiliar = lista;
//
//    if(lista.crianca == NULL)
//        return;
//    while( auxiliar->proximo != NULL && !Crianca::compararCaracteristicas(atual->proximo.crianca, crianca) ){
//
//    }
//    if(atual->proximo == NULL)
//        Adote::mainStack_->addWidget(new WText("Criança não foi encontrada. não foi possível excluir."));
//    else {
//        atual->proximo = atual->proximo->proximo;
//    }
}
void ListaCriancas::adicionarCrianca(){
    Crianca* temp = new Crianca::Crianca();
    ListaCriancas *aux = this;
    while(aux->proximo != NULL){
        aux = aux->proximo;
    }
    aux->proximo->crianca = temp;
    aux->proximo->proximo = NULL;
}

ListaCriancas* ListaCriancas::procurarCrianca(int idadeInf = 0, int idadeSup = 0, std::string sexo = ""){
    fstream database ("criancas/lista.txt", ios::in, 0);
    if(!database){
        new WText(WString::fromUTF8("Não foi possível salvar os dados no banco."), window_);
    }
    ListaCriancas *resultados = new ListaCriancas;
    while(!database.eof()){

    }
    while(aux != NULL){
        database << aux->crianca->nome << " " << aux->crianca->sexo << " " << aux->crianca->idade << endl;
        aux = aux->proximo;
    }
}
