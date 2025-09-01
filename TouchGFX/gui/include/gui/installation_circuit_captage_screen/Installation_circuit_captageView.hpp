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

	void bouton_moins_vitesse_circ();
	void bouton_plus_vitesse_circ();
	void bouton_moins_vitesse_min_pompe_puits();
	void bouton_plus_vitesse_min_pompe_puits();
	void bouton_moins_vitesse_max_pompe_puits();
	void bouton_plus_vitesse_max_pompe_puits();
	void bouton_non_marche_forcee();
	void bouton_oui_marche_forcee();
	void bouton_non_pilotage_vit_pompe_puits();
	void bouton_oui_pilotage_vit_pompe_puits();
	void bouton_droite_type_circulateur();
	void bouton_gauche_type_circulateur();
	void bouton_droite_type_capteur();
	void bouton_gauche_type_capteur();
	void vitesseCirculateur();
	void update_vitesse_min_pompe_puits();
	void update_vitesse_max_pompe_puits();
	void bouton_valider();

	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

protected:
    bool bConnexionDistance, bCartePhoenix, bPilotagePompedePuits;
    uint8_t u8VitesseCirculateur, u8ConsignePompePuitsMin, u8ConsignePompePuitsMax,eTypeDeCaptage;
    uint16_t u16ErreurAffichee;
    S_DATE sDate_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9],
	textAreaBuffer_Vitesse_Min_Pompe_Puits[5], textAreaBuffer_Vitesse_Max_Pompe_Puits[5], textAreaBuffer_ConsigneCirc[11],
	textAreaBuffer_TypeCirc[11];
};

#endif // INSTALLATION_CIRCUIT_CAPTAGEVIEW_HPP
