#ifndef USINE_CONFIG_GEOTWINVIEW_HPP
#define USINE_CONFIG_GEOTWINVIEW_HPP

#include <gui_generated/usine_config_geotwin_screen/Usine_config_geotwinViewBase.hpp>
#include <gui/usine_config_geotwin_screen/Usine_config_geotwinPresenter.hpp>

class Usine_config_geotwinView : public Usine_config_geotwinViewBase
{
public:
    Usine_config_geotwinView();
    virtual ~Usine_config_geotwinView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CONFIG_GEOTWINVIEW_HPP
