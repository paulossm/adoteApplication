#include <Wt/WText>
#include <Wt/WApplication>

#include "headers/ListaCriancas.h"

ListaCriancas::ListaCriancas()
{
    ListaCriancas *temp;
    temp->crianca = NULL;
    temp->proximo = NULL;
    return temp;
}

ListaCriancas::~ListaCriancas()
{
    //dtor
}

void ListaCriancas::listarCriancas(ListaCriancas lista){
    if(!lista){

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
    ListaCriancas *cabeca = lista,
    *auxiliar = lista;

    if(lista.crianca == NULL)
        return;
    while( auxiliar->proximo != NULL && !Crianca::compararCaracteristicas(atual->proximo.crianca, crianca) ){

    }
    if(atual->proximo == NULL)
        Adote::mainStack_->addWidget(new WText("Criança não foi encontrada. não foi possível excluir."));
    else {
        atual->proximo = atual->proximo->proximo;
    }
}
void ListaCriancas::adicionarCrianca(ListaCriancas *lista){
    if(lista == NULL){
        lista = new ListaCriancas();
        lista->crianca = new Criança(Adote::window_);
    }
    else {
        ListaCriancas *aux = lista;
        if(aux->crianca != NULL){
            while(aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = new ListaCriancas();
            if(aux->proximo == NULL){
                WText *erro = new WText("Não há espaço na memória para inserir a nova criança.");
                return;
            }
            aux->proximo->crianca = new Criança();
            aux->proximo = NULL;
    }

}