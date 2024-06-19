#ifndef USINE_CONFIG_AJPACPRESENTER_HPP
#define USINE_CONFIG_AJPACPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_config_ajpacView;

class Usine_config_ajpacPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_config_ajpacPresenter(Usine_config_ajpacView& v);

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

    virtual ~Usine_config_ajpacPresenter() {}

private:
    Usine_config_ajpacPresenter();

    Usine_config_ajpacView& view;
};

#endif // USINE_CONFIG_AJPACPRESENTER_HPP
