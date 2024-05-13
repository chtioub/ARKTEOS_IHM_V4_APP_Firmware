#ifndef INSTALLATION_PISCINE_AVANCESPRESENTER_HPP
#define INSTALLATION_PISCINE_AVANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_piscine_avancesView;

class Installation_piscine_avancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_piscine_avancesPresenter(Installation_piscine_avancesView& v);

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

    virtual ~Installation_piscine_avancesPresenter() {}

private:
    Installation_piscine_avancesPresenter();

    Installation_piscine_avancesView& view;
};

#endif // INSTALLATION_PISCINE_AVANCESPRESENTER_HPP
