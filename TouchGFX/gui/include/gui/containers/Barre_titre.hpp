#ifndef BARRE_TITRE_HPP
#define BARRE_TITRE_HPP

#include <gui_generated/containers/Barre_titreBase.hpp>

class Barre_titre : public Barre_titreBase
{
public:
    Barre_titre();
    virtual ~Barre_titre() {}

    virtual void initialize();
    void connexionDistante(bool bConnexionDistante);
    void recupConfig(bool bRecupConfig);
    void date(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
    void heure(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
    void titre(touchgfx::Unicode::UnicodeChar *textArea_Buffer);
    void sansRetour();
    void sansAccueil();
    void erreur(uint16_t u16Erreur);
protected:
    touchgfx::Unicode::UnicodeChar textArea_Erreur[4];
};

#endif // BARRE_TITRE_HPP
