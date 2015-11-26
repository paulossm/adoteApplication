#ifndef ADOTE_H
#define ADOTE_H

#include <Wt/WContainerWidget>

#include "Session.h"

namespace Wt {
  class WStackedWidget;
  class WAnchor;
}

class Session;

class Adote : public Wt::WContainerWidget
{
    public:
        Adote(Wt::WContainerWidget *parent = 0);
        virtual ~Adote();

    private:
        Session session_;
        Wt::WButtonGroup *group_;
        WT::WRadioButton *profile_;
        int profileId_;

        Wt::WStackedWidget *mainStack_;
        Wt::WAnchor *continueAnchor_;
        Wt::WLineEdit *userName_;

        Juiz *userJuiz_;
        Orfanato *userOrfanato_;

        void setUserProfile();
        void loadFormLogin(int profileId);
        void loadGuestUser();
        void onAuthEvent();
        void loadJuizPage();
        void loadOrfanatoPage();
};

#endif // ADOTE_H
