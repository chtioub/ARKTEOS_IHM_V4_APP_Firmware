#ifndef BOUTON_ON_OFF_TOGGLE_HPP
#define BOUTON_ON_OFF_TOGGLE_HPP

#include <gui_generated/containers/Bouton_on_off_toggleBase.hpp>

class Bouton_on_off_toggle : public Bouton_on_off_toggleBase
{
public:
    Bouton_on_off_toggle();
    virtual ~Bouton_on_off_toggle() {}

    virtual void initialize();
protected:
};

#endif // BOUTON_ON_OFF_TOGGLE_HPP
