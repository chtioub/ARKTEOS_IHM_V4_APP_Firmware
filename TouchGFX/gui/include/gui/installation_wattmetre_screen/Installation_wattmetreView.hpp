#ifndef INSTALLATION_WATTMETREVIEW_HPP
#define INSTALLATION_WATTMETREVIEW_HPP

#include <gui_generated/installation_wattmetre_screen/Installation_wattmetreViewBase.hpp>
#include <gui/installation_wattmetre_screen/Installation_wattmetrePresenter.hpp>

class Installation_wattmetreView : public Installation_wattmetreViewBase
{
public:
    Installation_wattmetreView();
    virtual ~Installation_wattmetreView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_WATTMETREVIEW_HPP
