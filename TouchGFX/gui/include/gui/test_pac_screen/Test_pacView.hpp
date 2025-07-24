#ifndef TEST_PACVIEW_HPP
#define TEST_PACVIEW_HPP

#include <gui_generated/test_pac_screen/Test_pacViewBase.hpp>
#include <gui/test_pac_screen/Test_pacPresenter.hpp>

class Test_pacView : public Test_pacViewBase
{
public:
    Test_pacView();
    virtual ~Test_pacView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_oui();
	void bouton_non();
	void bouton_gauche_pw();
	void bouton_droit_pw();
	void bouton_gauche_mode();
	void bouton_droit_mode();
	void bouton_gauche_test_code();
	void bouton_droit_test_code();
	void bouton_retour();
	void bouton_valider();

	void update_pw_pac();
	void update_mode_pac();
	void update_test_code();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
    uint16_t u16ErreurAffichee;
	unsigned char ModeTest, bTestPAC;
	uint8_t  Pw;
	int16_t Teau;
    S_DATE sDate_old;
    S_CONFIG_IHM sConfig_IHM_old;
    S_STATUT_PAC sStatut_PAC_old;
    touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_Pw_Pac[6],textAreaBuffer_Mode_test_Pac[12],textAreaBuffer_Test_Code[4];
};

#endif // TEST_PACVIEW_HPP
