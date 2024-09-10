#ifndef INSTALLATION_PARAM_AVANCESPRESENTER_HPP
#define INSTALLATION_PARAM_AVANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_param_avancesView;

class Installation_param_avancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_param_avancesPresenter(Installation_param_avancesView& v);

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

    virtual ~Installation_param_avancesPresenter() {}

private:
    Installation_param_avancesPresenter();

    Installation_param_avancesView& view;
};

#endif // INSTALLATION_PARAM_AVANCESPRESENTER_HPP
