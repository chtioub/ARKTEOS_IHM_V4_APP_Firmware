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

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee, u16GroupeA, u16GroupeB, u16GroupeAOnOff, u16GroupeBOnOff, u16NumVoieGroupeA, u16NumVoieGroupeB;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_GroupeA[19],  textAreaBuffer_GroupeB[19];
};

#endif // INSTALLATION_MZ_PARAMETRAGE_GROUPESVIEW_HPP
