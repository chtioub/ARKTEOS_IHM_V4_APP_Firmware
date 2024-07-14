#ifndef INSTALLATION_PISCINEVIEW_HPP
#define INSTALLATION_PISCINEVIEW_HPP

#include <gui_generated/installation_piscine_screen/Installation_piscineViewBase.hpp>
#include <gui/installation_piscine_screen/Installation_piscinePresenter.hpp>

class Installation_piscineView : public Installation_piscineViewBase
{
public:
    Installation_piscineView();
    virtual ~Installation_piscineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_PISCINEVIEW_HPP
