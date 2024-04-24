#ifndef BARRE_TITRE_HPP
#define BARRE_TITRE_HPP

#include <gui_generated/containers/Barre_titreBase.hpp>

class Barre_titre : public Barre_titreBase
{
public:
    Barre_titre();
    virtual ~Barre_titre() {}

    virtual void initialize();
protected:
};

#endif // BARRE_TITRE_HPP
