#ifndef ADOTE_H_INCLUDED
#define ADOTE_H_INCLUDED

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WTemplate>
#include <Wt/WStackedWidget>
#include <Wt/WAnchor>

#include "Orfanato.h"
#include "Juiz.h"

namespace Wt {
  class WStackedWidget;
  class WAnchor;
}

class Adote : public Wt::WContainerWidget
{
    public:
        Adote(Wt::WContainerWidget *parent = 0);
        virtual ~Adote();

    private:
        Wt::WButtonGroup *group_;
        Wt::WRadioButton *profile_;
        int profileId_;


        Wt::WTemplate *view_;
        Wt::WStackedWidget *window_;
        Wt::WAnchor *continueAnchor_;
        Wt::WLineEdit *userName_;

        void setUserProfile();
        void processLogin();
        void loadFormLogin();
        void loadGuestUser();
        void onAuthEvent();
        void loadJuizPage();
        void loadOrfanatoPage();
};

#endif // ADOTE_H_INCLUDED
