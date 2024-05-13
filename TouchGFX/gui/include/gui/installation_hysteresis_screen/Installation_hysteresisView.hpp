#ifndef INSTALLATION_HYSTERESISVIEW_HPP
#define INSTALLATION_HYSTERESISVIEW_HPP

#include <gui_generated/installation_hysteresis_screen/Installation_hysteresisViewBase.hpp>
#include <gui/installation_hysteresis_screen/Installation_hysteresisPresenter.hpp>

class Installation_hysteresisView : public Installation_hysteresisViewBase
{
public:
    Installation_hysteresisView();
    virtual ~Installation_hysteresisView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_HYSTERESISVIEW_HPP
