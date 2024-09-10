#ifndef INSTALLATION_PARAM_AVANCESVIEW_HPP
#define INSTALLATION_PARAM_AVANCESVIEW_HPP

#include <gui_generated/installation_param_avances_screen/Installation_param_avancesViewBase.hpp>
#include <gui/installation_param_avances_screen/Installation_param_avancesPresenter.hpp>

class Installation_param_avancesView : public Installation_param_avancesViewBase
{
public:
    Installation_param_avancesView();
    virtual ~Installation_param_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_PARAM_AVANCESVIEW_HPP
