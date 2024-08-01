#ifndef CONFIGURATIONVIEW_HPP
#define CONFIGURATIONVIEW_HPP

#include <gui_generated/configuration_screen/ConfigurationViewBase.hpp>
#include <gui/configuration_screen/ConfigurationPresenter.hpp>

class ConfigurationView : public ConfigurationViewBase
{
public:
    ConfigurationView();
    virtual ~ConfigurationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[30];
};

#endif // CONFIGURATIONVIEW_HPP
