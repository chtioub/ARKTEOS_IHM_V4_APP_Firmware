#ifndef USINE_CALIBRAGE_OFFSETVIEW_HPP
#define USINE_CALIBRAGE_OFFSETVIEW_HPP

#include <gui_generated/usine_calibrage_offset_screen/Usine_calibrage_offsetViewBase.hpp>
#include <gui/usine_calibrage_offset_screen/Usine_calibrage_offsetPresenter.hpp>

class Usine_calibrage_offsetView : public Usine_calibrage_offsetViewBase
{
public:
    Usine_calibrage_offsetView();
    virtual ~Usine_calibrage_offsetView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_oui();
	void bouton_non();
	void bouton_valider();
	void bouton_gauche_choix_sonde();
	void bouton_droit_choix_sonde();
	void bouton_gauche_offset_sonde();
	void bouton_droit_offset_sonde();
	void send_new_value();
	void update_type_sonde();
	void update_offset();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
    uint8_t u8NumSonde;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    S_CONFIG_OFFSET sConfig_OffsetTemp;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_sonde[16], textAreaBuffer_valeur_offset[8];
};

#endif // USINE_CALIBRAGE_OFFSETVIEW_HPP
