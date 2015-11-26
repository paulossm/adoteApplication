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

#include "Adote.h"

using namespace Wt;

Adote::Adote(WContainerWidget *parent):
  WContainerWidget(parent)
{
    WText *title = new WText("<h1>Bem Vindo ao Adote</h1>");
    addWidget(title);

    group_ = new WButtonGroup(parent);
    Wt::WRadioButton *profiles;

    profiles = new WRadioButton("Jurídico", root());
    profiles->setInline(false);
    group_->addButton(profiles, 1);

    profiles = new Wt::WRadioButton("Orfanato", root());
    profiles->setInline(false);
    group_->addButton(profiles, 2);

    profiles = new Wt::WRadioButton("Pai Adotivo", root());
    profiles->setInline(false);
    group_->addButton(profiles, 3);

    group_->setSelectedButtonIndex(0);
    group->checkedChanged().connect(this, &Adote::setUserProfile);

    addWidget(group_);

    WPushButton *go = new WPushButton("Continuar");
    go->setMargin(10, Left);

    addWidget(go);
    addWidget(btn);

    go->clicked()->connect(this, &Adote::ProcessLogin);
}

void Adote::setUserProfile(){
    profile_ = group_->checkedButton();
    profileId_ = group_->id(profile_);
}

void Adote::processLogin(){
    if(profileId_ != 3){
        loadFormLogin(profileId_);
    }
    else {
        loadGuestUser();
    }
}

void Adote::loadFormLogin(int profileId){
    mainStack_->clear();
    mainStack_ = new WStackedWidget();
    addWidget(mainStack_);

    WText *title = new WText("<h1>Formulário de Login</h1>", mainStack_);
    userName_ = new WLineEdit("usuário: ", mainStack_);

    WAnchor *entrarBtn = new WAnchor("/dashboard" + (std::string) profileId, "dashboard", mainStack_);
    entrarBtn->setLink(WLink(WLink::internalPath, "dashboard" + (std::string) profileId));

    WApplication::instance()->internalPathChanged()
    .connect(this, &HangmanGame::handleInternalPath);
}

void Adote::handleInternalPath(const std::string &internalPath)
{
    if (internalPath == "/dashboard1")
      loadJuizPage();
    else if (internalPath == "/dashboard2")
      loadOrfanatoPage();
    else
      new adote();
}

void Adote::loadJuizPage(){
    mainStack_->clear();
}
void loadOrfanatoPage(){

}
