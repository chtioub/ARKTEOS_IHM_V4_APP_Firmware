#ifndef USINE_CONFIG_INVERTERRAVIEW_HPP
#define USINE_CONFIG_INVERTERRAVIEW_HPP

#include <gui_generated/usine_config_inverterra_screen/Usine_config_inverterraViewBase.hpp>
#include <gui/usine_config_inverterra_screen/Usine_config_inverterraPresenter.hpp>

class Usine_config_inverterraView : public Usine_config_inverterraViewBase
{
public:
    Usine_config_inverterraView();
    virtual ~Usine_config_inverterraView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CONFIG_INVERTERRAVIEW_HPP
