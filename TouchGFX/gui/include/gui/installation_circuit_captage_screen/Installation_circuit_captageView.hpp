#ifndef INSTALLATION_CIRCUIT_CAPTAGEVIEW_HPP
#define INSTALLATION_CIRCUIT_CAPTAGEVIEW_HPP

#include <gui_generated/installation_circuit_captage_screen/Installation_circuit_captageViewBase.hpp>
#include <gui/installation_circuit_captage_screen/Installation_circuit_captagePresenter.hpp>

class Installation_circuit_captageView : public Installation_circuit_captageViewBase
{
public:
    Installation_circuit_captageView();
    virtual ~Installation_circuit_captageView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_CIRCUIT_CAPTAGEVIEW_HPP
