#ifndef USINE_CONFIG_ADDITIONNELLEVIEW_HPP
#define USINE_CONFIG_ADDITIONNELLEVIEW_HPP

#include <gui_generated/usine_config_additionnelle_screen/Usine_config_additionnelleViewBase.hpp>
#include <gui/usine_config_additionnelle_screen/Usine_config_additionnellePresenter.hpp>

class Usine_config_additionnelleView : public Usine_config_additionnelleViewBase
{
public:
    Usine_config_additionnelleView();
    virtual ~Usine_config_additionnelleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CONFIG_ADDITIONNELLEVIEW_HPP
