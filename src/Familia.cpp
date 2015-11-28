#include "Familia.h"


#include <Wt/WText>
#include <Wt/WPushButton>

using namespace Wt;

Familia::Familia()
{
    Adote::mainStack_->clear();
    WText *title_ = new WText("Cadastrando nova família pretendente à adoção.", Adote::mainStack_);
    pais = new Pais;

    WText *title_ = new WText("Cadastrando preferências de criança.", Adote::mainStack_);
    pretendida = new Criança;

    proximo = NULL;
}

void Familia::cadastrarMembro(){
    if(pais == NULL)
        pais = new Pais;
    else {
        // Criar um novo membro da familia
        Pais *novo = new Pais;
        if(novo == NULL)
            return;

        // Inseri-lo na lista de membros
        Pais *auxiliar = pais;
        while(auxiliar->proximo != NULL)
            auxiliar = auxiliar->proximo;
        auxiliar->proximo = novo;
        novo->anterior = auxiliar;
    }
}

void Familia::excluirPais(Pais pai){
    // pega o nome do pai e busca pra excluir
    if(pai == NULL)
        return;
    Pais *auxiliar = pais;
    while(auxiliar != NULL){
        if(Pais::compararPais(auxiliar, pai)){
            auxiliar->anterior->proximo = auxiliar->proximo;
            auxiliar->proximo->anterior = auxiliar->anterior;
            delete auxiliar;
        }
    }
}
void Familia::atualizarFamilia(){

}
void atualizarCriancaPretendida(){

}

Familia::~Familia()
{
    //dtor
}
