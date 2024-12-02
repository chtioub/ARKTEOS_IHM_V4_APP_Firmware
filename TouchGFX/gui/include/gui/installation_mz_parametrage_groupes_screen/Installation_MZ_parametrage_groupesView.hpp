#ifndef INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP
#define INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP

#include <gui_generated/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesViewBase.hpp>
#include <gui/installation_mz_parametrage_groupes_screen/Installation_MZ_parametrage_groupesPresenter.hpp>

class Installation_MZ_parametrage_groupesView : public Installation_MZ_parametrage_groupesViewBase
{
public:
    Installation_MZ_parametrage_groupesView();
    virtual ~Installation_MZ_parametrage_groupesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void MAJ_Type_GroupeA();
	void MAJ_Type_GroupeB();
	void MAJ_Carte_GroupeA();
	void MAJ_Carte_GroupeB();
	void bouton_choix_carte_MZ_groupe_A();
	void bouton_choix_carte_MZ_groupe_B();
	void bouton_sortie_groupe_A();
	void bouton_sortie_groupe_B();
	void bouton_groupe_A();
	void bouton_groupe_B();
	void affichage_attention();
	void attention_valid_button_clicked();
	void bouton_valider();



    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance, bAttentionClicked;
	unsigned char bGroupeAOnOff : 1, bGroupeBOnOff : 1;
	unsigned short u3CarteGroupeA : 3, u3CarteGroupeB : 3, u3NumVoieGroupeA : 3, u3NumVoieGroupeB : 3;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9],textAreaBuffer_GroupeA[11],  textAreaBuffer_GroupeB[11],
	textAreaBuffer_Voie_GroupeA[2], textAreaBuffer_Voie_GroupeB[2],textAreaBuffer_MessTitre[40], textAreaBuffer_MessMess[500];
};

#endif // INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP
