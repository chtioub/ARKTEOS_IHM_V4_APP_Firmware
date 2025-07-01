#ifndef MAINTENANCE_FREQUENCE_HISTORIQUESVIEW_HPP
#define MAINTENANCE_FREQUENCE_HISTORIQUESVIEW_HPP

#include <gui_generated/maintenance_frequence_historiques_screen/Maintenance_frequence_historiquesViewBase.hpp>
#include <gui/maintenance_frequence_historiques_screen/Maintenance_frequence_historiquesPresenter.hpp>

class Maintenance_frequence_historiquesView : public Maintenance_frequence_historiquesViewBase
{
public:
    Maintenance_frequence_historiquesView();
    virtual ~Maintenance_frequence_historiquesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

	void bouton_gauche();
	void bouton_droit();
	void bouton_valider();
	void update_valeur_frequence();

protected:
	bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	uint32_t u32ValAction_tmp;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[50], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Frequence[4];
};


#endif // MAINTENANCE_FREQUENCE_HISTORIQUESVIEW_HPP
