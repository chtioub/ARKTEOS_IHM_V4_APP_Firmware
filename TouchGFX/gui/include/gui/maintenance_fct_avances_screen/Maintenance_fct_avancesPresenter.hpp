#ifndef MAINTENANCE_FCT_AVANCESPRESENTER_HPP
#define MAINTENANCE_FCT_AVANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Maintenance_fct_avancesView;

class Maintenance_fct_avancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Maintenance_fct_avancesPresenter(Maintenance_fct_avancesView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Maintenance_fct_avancesPresenter() {}

private:
    Maintenance_fct_avancesPresenter();

    Maintenance_fct_avancesView& view;
};

#endif // MAINTENANCE_FCT_AVANCESPRESENTER_HPP
