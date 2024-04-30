#ifndef INSTALLATION_CONFIG_HYDRAU_RAPIDEPRESENTER_HPP
#define INSTALLATION_CONFIG_HYDRAU_RAPIDEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_config_hydrau_rapideView;

class Installation_config_hydrau_rapidePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_config_hydrau_rapidePresenter(Installation_config_hydrau_rapideView& v);

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

    virtual ~Installation_config_hydrau_rapidePresenter() {}

private:
    Installation_config_hydrau_rapidePresenter();

    Installation_config_hydrau_rapideView& view;
};

#endif // INSTALLATION_CONFIG_HYDRAU_RAPIDEPRESENTER_HPP
