#ifndef USINE_CONFIG_GEOTWINPRESENTER_HPP
#define USINE_CONFIG_GEOTWINPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_config_geotwinView;

class Usine_config_geotwinPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_config_geotwinPresenter(Usine_config_geotwinView& v);

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

    virtual ~Usine_config_geotwinPresenter() {}

private:
    Usine_config_geotwinPresenter();

    Usine_config_geotwinView& view;
};

#endif // USINE_CONFIG_GEOTWINPRESENTER_HPP
