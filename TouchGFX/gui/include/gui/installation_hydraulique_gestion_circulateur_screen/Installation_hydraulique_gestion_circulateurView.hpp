#ifndef INSTALLATION_HYDRAULIQUE_GESTION_CIRCULATEURVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_GESTION_CIRCULATEURVIEW_HPP

#include <gui_generated/installation_hydraulique_gestion_circulateur_screen/Installation_hydraulique_gestion_circulateurViewBase.hpp>
#include <gui/installation_hydraulique_gestion_circulateur_screen/Installation_hydraulique_gestion_circulateurPresenter.hpp>

class Installation_hydraulique_gestion_circulateurView : public Installation_hydraulique_gestion_circulateurViewBase
{
public:
    Installation_hydraulique_gestion_circulateurView();
    virtual ~Installation_hydraulique_gestion_circulateurView() {}
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
    void bouton_retour();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance, bCartePhoenix, bMultizone;
    uint8_t u8VitesseCirculateur;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[50], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_ConsigneCirc[11], textAreaBuffer_TypeCirc[11];
};

#endif // INSTALLATION_HYDRAULIQUE_GESTION_CIRCULATEURVIEW_HPP
