#ifndef MAINTENANCE_FCT_AVANCESVIEW_HPP
#define MAINTENANCE_FCT_AVANCESVIEW_HPP

#include <gui_generated/maintenance_fct_avances_screen/Maintenance_fct_avancesViewBase.hpp>
#include <gui/maintenance_fct_avances_screen/Maintenance_fct_avancesPresenter.hpp>

class Maintenance_fct_avancesView : public Maintenance_fct_avancesViewBase
{
public:
    Maintenance_fct_avancesView();
    virtual ~Maintenance_fct_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MAINTENANCE_FCT_AVANCESVIEW_HPP
