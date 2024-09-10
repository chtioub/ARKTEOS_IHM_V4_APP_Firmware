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

    void bouton_moins_vitesse_circ();
    void bouton_plus_vitesse_circ();
    void bouton_non_marche_forcee();
    void bouton_oui_marche_forcee();
    void bouton_droite_type_circulateur();
    void bouton_gauche_type_circulateur();
    void vitesseCirculateur();
    void bouton_valider();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance, bCartePhoenix;
    uint8_t u8VitesseCirculateur;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_ConsigneCirc[11], textAreaBuffer_TypeCirc[11];
};

#endif // INSTALLATION_CIRCUIT_PRIMAIREVIEW_HPP
