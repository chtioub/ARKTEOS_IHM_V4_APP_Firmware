#ifndef MAINTENANCE_FCT_AVANCESVIEW_HPP
#define MAINTENANCE_FCT_AVANCESVIEW_HPP

#include <gui_generated/maintenance_fct_avances_screen/Maintenance_fct_avancesViewBase.hpp>
#include <gui/maintenance_fct_avances_screen/Maintenance_fct_avancesPresenter.hpp>

class Maintenance_fct_avancesView : public Maintenance_fct_avancesViewBase
{
public:
    Maintenance_fct_avancesView();
    virtual ~Maintenance_fct_avancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void button_mode_commande();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	 bool bConnexionDistance, bCartePhoenix;
//	    uint8_t u8VitesseCirculateur;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];//, textAreaBuffer_ConsigneCirc[11], textAreaBuffer_TypeCirc[11];
};

#endif // MAINTENANCE_FCT_AVANCESVIEW_HPP
