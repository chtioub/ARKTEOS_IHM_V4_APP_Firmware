#ifndef INSTALLATION_HYDRAULIQUE_MESSAGE_MULTIZONESVIEW_HPP
#define INSTALLATION_HYDRAULIQUE_MESSAGE_MULTIZONESVIEW_HPP

#include <gui_generated/installation_hydraulique_message_multizones_screen/Installation_hydraulique_message_multizonesViewBase.hpp>
#include <gui/installation_hydraulique_message_multizones_screen/Installation_hydraulique_message_multizonesPresenter.hpp>

class Installation_hydraulique_message_multizonesView : public Installation_hydraulique_message_multizonesViewBase
{
public:
    Installation_hydraulique_message_multizonesView();
    virtual ~Installation_hydraulique_message_multizonesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_valider();

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
    bool bConnexionDistance;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_CONFIG_IHM sConfig_IHM_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // INSTALLATION_HYDRAULIQUE_MESSAGE_MULTIZONESVIEW_HPP
