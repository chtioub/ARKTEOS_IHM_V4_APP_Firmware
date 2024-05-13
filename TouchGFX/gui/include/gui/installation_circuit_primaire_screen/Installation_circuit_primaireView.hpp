#ifndef INSTALLATION_CIRCUIT_PRIMAIREVIEW_HPP
#define INSTALLATION_CIRCUIT_PRIMAIREVIEW_HPP

#include <gui_generated/installation_circuit_primaire_screen/Installation_circuit_primaireViewBase.hpp>
#include <gui/installation_circuit_primaire_screen/Installation_circuit_primairePresenter.hpp>

class Installation_circuit_primaireView : public Installation_circuit_primaireViewBase
{
public:
    Installation_circuit_primaireView();
    virtual ~Installation_circuit_primaireView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INSTALLATION_CIRCUIT_PRIMAIREVIEW_HPP
