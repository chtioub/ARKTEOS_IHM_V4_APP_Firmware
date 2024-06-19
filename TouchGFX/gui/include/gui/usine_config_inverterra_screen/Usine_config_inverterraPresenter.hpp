#ifndef USINE_CONFIG_INVERTERRAPRESENTER_HPP
#define USINE_CONFIG_INVERTERRAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_config_inverterraView;

class Usine_config_inverterraPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_config_inverterraPresenter(Usine_config_inverterraView& v);

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

    virtual ~Usine_config_inverterraPresenter() {}

private:
    Usine_config_inverterraPresenter();

    Usine_config_inverterraView& view;
};

#endif // USINE_CONFIG_INVERTERRAPRESENTER_HPP
