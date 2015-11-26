#ifndef ADOTEAPPLICATION_H
#define ADOTEAPPLICATION_H

#include <Wt/WContainerWidget>

#include "Session.h"

namespace Wt {
  class WStackedWidget;
  class WAnchor;
}

class adoteApplication : public Wt::WContainerWidget
{
    public:
        adoteApplication(Wt::WContainerWidget *parent = 0);
        virtual ~adoteApplication();
    protected:
    private:
};

#endif // ADOTEAPPLICATION_H
