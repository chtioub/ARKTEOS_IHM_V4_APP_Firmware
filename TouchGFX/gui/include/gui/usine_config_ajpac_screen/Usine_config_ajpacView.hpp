#ifndef USINE_CONFIG_AJPACVIEW_HPP
#define USINE_CONFIG_AJPACVIEW_HPP

#include <gui_generated/usine_config_ajpac_screen/Usine_config_ajpacViewBase.hpp>
#include <gui/usine_config_ajpac_screen/Usine_config_ajpacPresenter.hpp>

class Usine_config_ajpacView : public Usine_config_ajpacViewBase
{
public:
    Usine_config_ajpacView();
    virtual ~Usine_config_ajpacView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CONFIG_AJPACVIEW_HPP
