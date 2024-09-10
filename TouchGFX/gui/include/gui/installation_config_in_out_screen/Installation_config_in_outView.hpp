#ifndef INSTALLATION_CONFIG_IN_OUTVIEW_HPP
#define INSTALLATION_CONFIG_IN_OUTVIEW_HPP

#include <gui_generated/installation_config_in_out_screen/Installation_config_in_outViewBase.hpp>
#include <gui/installation_config_in_out_screen/Installation_config_in_outPresenter.hpp>

class Installation_config_in_outView : public Installation_config_in_outViewBase
{
public:
    Installation_config_in_outView();
    virtual ~Installation_config_in_outView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_CONFIG_IN_OUTVIEW_HPP
