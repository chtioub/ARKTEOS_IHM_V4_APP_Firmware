#ifndef ENERGIES_HISTOVIEW_HPP
#define ENERGIES_HISTOVIEW_HPP

#include <gui_generated/energies_histo_screen/Energies_histoViewBase.hpp>
#include <gui/energies_histo_screen/Energies_histoPresenter.hpp>

class Energies_histoView : public Energies_histoViewBase
{
public:
    Energies_histoView();
    virtual ~Energies_histoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    void bouton_pac();
    void bouton_chaud();
    void bouton_froid();
    void bouton_ecs();
    void bouton_piscine();
    void bouton_12mois();
    void bouton_24jours();
    void bouton_24heures();
    void couleur_barres(uint32_t u32Couleur);
protected:
};

#endif // ENERGIES_HISTOVIEW_HPP
