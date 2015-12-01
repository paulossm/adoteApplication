#ifndef ADOTE_H_
#define ADOTE_H_

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

class Juiz;
class Orfanato;

class Adote : public Wt::WContainerWidget
{
    public:
        Adote(Wt::WContainerWidget *parent = 0);
        virtual ~Adote();

    private:
        Wt::WButtonGroup *group_;
        Wt::WRadioButton *profile_;
        int profileId_;

        Juiz *juiz;
        Orfanato *orfanato;

        Wt::WTemplate *view_;
        Wt::WStackedWidget *window_;
        Wt::WAnchor *continueAnchor_;
        Wt::WLineEdit *userName_;

        void setUserProfile(int id);
        void processLogin();
        void loadFormLogin(int id);
        void loadGuestUser();
        void loadJuizPage();
        void loadOrfanatoPage();
        void restartApp();
};

#endif // ADOTE_H_
