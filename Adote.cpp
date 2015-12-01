#include <Wt/WText>
#include <Wt/WContainerWidget>
#include <Wt/WStackedWidget>
#include <Wt/WApplication>
#include <Wt/WButtonGroup>
#include <Wt/WRadioButton>
#include <Wt/WPushButton>
#include <Wt/WLineEdit>
#include <Wt/WTemplate>
#include <Wt/WImage>
#include <Wt/WString>
#include <Wt/WLink>
#include <iostream>
#include <string>

#include "headers/Adote.h"
#include "headers/Juiz.h"
#include "headers/Orfanato.h"


using namespace Wt;

Adote::Adote(WContainerWidget *parent):
  WContainerWidget(parent)
{
    view_ = new WTemplate(WString::tr("App.index"));
    group_ = new WButtonGroup();
    Wt::WRadioButton *profiles;

    Wt::WImage *logo = new Wt::WImage(Wt::WLink("img/adote_logo.png"));
    logo->setStyleClass("img-responsive");
    logo->setAlternateText("Adote Logo");
    logo->setMargin(0, Top);
    view_->bindWidget("logo", logo);

    profiles = new WRadioButton("Orgao juridico");
    profiles->setInline(false);
    profiles->checked().connect(boost::bind(&Adote::setUserProfile, this, 1));
    group_->addButton(profiles, 1);
    view_->bindWidget("profile-1", profiles);

    profiles = new Wt::WRadioButton("Abrigo/Orfanato");
    profiles->setInline(false);
    profiles->checked().connect(boost::bind(&Adote::setUserProfile, this, 2));
    group_->addButton(profiles, 2);
    view_->bindWidget("profile-2", profiles);

    profiles = new Wt::WRadioButton("Desejo adotar");
    profiles->setInline(false);
    profiles->checked().connect(boost::bind(&Adote::setUserProfile, this, 3));
    group_->addButton(profiles, 3);
    view_->bindWidget("profile-3", profiles);

    WPushButton *continue_ = new WPushButton("Continuar");
    continue_->setMargin(10, Top);
    continue_->setStyleClass("btn btn-success");
    continue_->clicked().connect(this, &Adote::processLogin);

    view_->bindWidget("action", new WText("Selecione o seu perfil:"));
    view_->bindWidget("continue-button", continue_);

    window_ = new WStackedWidget(parent);
    window_->addWidget(view_);
}

void Adote::setUserProfile(int id){
    this->profileId_ = id;
}

void Adote::processLogin(){
    if(this->profileId_ == 3){
        this->loadGuestUser();
    }
    else {
        this->loadFormLogin(profileId_);
    }

}

void Adote::loadFormLogin(int id){
    window_->clear();
    view_ = new WTemplate(WString::tr("App.loginForm"));
    userName_ = new WLineEdit();
    userName_->setStyleClass("form-control");
    userName_->setInline(false);
    WPushButton *entrar = new WPushButton("Entrar");
    entrar->setStyleClass("btn btn-success");

    if(id == 1){
        entrar->clicked().connect(this, &Adote::loadJuizPage);
    }
    if(id == 2){
        entrar->clicked().connect(this, &Adote::loadOrfanatoPage);
    }
    else {
        new Adote();
    }

    view_->bindWidget("action", new WText("Formulario de Login"));
    view_->bindWidget("login-form-username", userName_);
    view_->bindWidget("login-button", entrar);
    window_->addWidget(view_);
}

void Adote::loadGuestUser(){
    window_->clear();
    view_ = new WTemplate(WString::tr("App.tutorial"));

    WText *title = new WText("Novos Pais Adotivos");
    view_->bindWidget("action", title);

    WImage *picture = new WImage(Wt::WLink("img/children.jpg"));
    picture->setStyleClass("img-responsive");
    picture->setAlternateText("Crianças sorrindo. fonte: // https://tdhproduction.s3.amazonaws.com/asset_images/4101_adoption-internationale_inline.jpg");
    picture->setMargin(0, Top);
    view_->bindWidget("image", picture);
    view_->bindWidget("footer", new WText("fonte: http://redeglobo.globo.com/globocidadania/noticia/2013/06/conheca-etapas-do-processo-de-adocao-de-criancas-no-brasil.html"));

    WPushButton *logout = new WPushButton("Sair");
    logout->setStyleClass("btn btn-danger");
    logout->clicked().connect(this, &Adote::restartApp);
    view_->bindWidget("button", logout);

    window_->addWidget(view_);
}

void Adote::loadJuizPage(){
    this->juiz = new Juiz(this->window_);
}

void Adote::loadOrfanatoPage(){
    this->orfanato = new Orfanato(this->window_);
}

void Adote::restartApp(){
    this = new Adote();
}

Adote::~Adote(){
}
