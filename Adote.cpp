#include <Wt/WAnchor>
#include <Wt/WText>

#include <Wt/WStackedWidget>
#include <Wt/WVBoxLayout>
#include <Wt/WHBoxLayout>

#include <Wt/WApplication>
#include <Wt/WButtonGroup>
#include <Wt/WRadioButton>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WTemplate>

#include "headers/Adote.h"

using namespace Wt;

Adote::Adote(WContainerWidget *parent):
  WContainerWidget(parent)
{
    view_ = new WTemplate(WString::tr("App.index"));

    group_ = new WButtonGroup();
    Wt::WRadioButton *profiles;

    profiles = new WRadioButton("Orgão Jurídico");
    profiles->setInline(false);
    group_->addButton(profiles, 1);

    profiles = new Wt::WRadioButton("Orfanato/Abrigo");
    profiles->setInline(false);
    group_->addButton(profiles, 2);

    profiles = new Wt::WRadioButton("Pai Adotivo");
    profiles->setInline(false);
    group_->addButton(profiles, 3);
    group_->setSelectedButtonIndex(0);

//    group_->checkedChanged().connect(this, &Adote::setUserProfile);
    WPushButton *continue_ = new WPushButton("Continuar");
    continue_->setMargin(10, Top);
    continue_->clicked().connect(this, &Adote::processLogin);

    view_->bindWidget("action", new WText("Selecione o seu perfil:"));
    view_->bindWidget("profiles", group_);
    view_->bindWidget("continue-button", continue_);
}

void Adote::setUserProfile(){
    profile_ = group_->checkedButton();
    profileId_ = group_->id(profile_);
    view_->bindWidget(profileId_);
}

void Adote::processLogin(){
    loadFormLogin(profileId_);
}

void Adote::loadFormLogin(int profileId){
    view_ = new WTemplate(WString::tr("App.loginForm"));
    userName_ = new WLineEdit("usuário: ", window_);
    WPushButton *entrar = new WPushButton("Entrar");
    WPushButton->clicked().connect(this, &processLogin);

    view_->bindWidget("action", new WText("Formulário de Login"));
    view_->bindWidget("login-form-username", userName_);
    view_->bindWidget("login-button", entrar);

    WApplication::instance()->internalPathChanged()
    .connect(this, &Adote::handleInternalPath);
}

void Adote::handleInternalPath(const std::string &internalPath)
{
    if (internalPath == "dashboard1")
      loadJuizPage();
    else if (internalPath == "dashboard2")
      loadOrfanatoPage();
}

void Adote::loadJuizPage(){
    view_->clear();
}
void Adote::loadOrfanatoPage(){
    window_->clear();
    new Orfanato(window_);
}
