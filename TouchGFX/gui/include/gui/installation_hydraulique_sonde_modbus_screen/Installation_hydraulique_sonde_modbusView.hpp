#ifndef INSTALLATION_HYDRAULIQUE_SONDE_MODBUSVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_SONDE_MODBUSVIEW_HPP

#include <gui_generated/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusViewBase.hpp>
#include <gui/installation_hydraulique_sonde_modbus_screen/Installation_hydraulique_sonde_modbusPresenter.hpp>

class Installation_hydraulique_sonde_modbusView : public Installation_hydraulique_sonde_modbusViewBase
{
public:
    Installation_hydraulique_sonde_modbusView();
    virtual ~Installation_hydraulique_sonde_modbusView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_HYDRAULIQUE_SONDE_MODBUSVIEW_HPP
