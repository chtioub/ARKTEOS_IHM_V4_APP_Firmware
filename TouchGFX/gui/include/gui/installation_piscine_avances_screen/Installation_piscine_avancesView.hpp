#ifndef INSTALLATION_PISCINE_AVANCESVIEW_HPP
#define INSTALLATION_PISCINE_AVANCESVIEW_HPP

#include <gui_generated/installation_piscine_avances_screen/Installation_piscine_avancesViewBase.hpp>
#include <gui/installation_piscine_avances_screen/Installation_piscine_avancesPresenter.hpp>

class Installation_piscine_avancesView : public Installation_piscine_avancesViewBase
{
public:
    Installation_piscine_avancesView();
    virtual ~Installation_piscine_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_PISCINE_AVANCESVIEW_HPP
