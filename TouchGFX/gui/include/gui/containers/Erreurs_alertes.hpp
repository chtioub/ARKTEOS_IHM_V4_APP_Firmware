#ifndef ERREURS_ALERTES_HPP
#define ERREURS_ALERTES_HPP

#include <gui_generated/containers/Erreurs_alertesBase.hpp>

class Erreurs_alertes : public Erreurs_alertesBase
{
public:
    Erreurs_alertes();
    virtual ~Erreurs_alertes() {}

    virtual void initialize();
protected:
};

#endif // ERREURS_ALERTES_HPP
