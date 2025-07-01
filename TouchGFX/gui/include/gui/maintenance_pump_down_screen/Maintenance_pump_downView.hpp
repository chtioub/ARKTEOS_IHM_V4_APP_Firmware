#ifndef MAINTENANCE_PUMP_DOWNVIEW_HPP
#define MAINTENANCE_PUMP_DOWNVIEW_HPP

#include <gui_generated/maintenance_pump_down_screen/Maintenance_pump_downViewBase.hpp>
#include <gui/maintenance_pump_down_screen/Maintenance_pump_downPresenter.hpp>

class Maintenance_pump_downView : public Maintenance_pump_downViewBase
{
public:
    Maintenance_pump_downView();
    virtual ~Maintenance_pump_downView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void changeDate(S_DATE *sDate);
   	virtual void changeErreur(uint16_t u16Erreur);
   	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
   	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
   	virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);

   	void bouton_oui();
   	void bouton_non();
   	void bouton_unite_exterieure();
   	void bouton_unite_interieure();
   	void bouton_valider();
   	void Timer_500ms();

protected:
	bool bConnexionDistance;
    uint8_t eEtape_PumpDown;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	typedef enum {ETAPE_0 =0, ETAPE_1, ETAPE_2, ETAPE_3,ETAPE_4} E_ETAPE_PUMP_DOWN;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Pression_HP[6], textAreaBuffer_Pression_BP[6];
};

#endif // MAINTENANCE_PUMP_DOWNVIEW_HPP
