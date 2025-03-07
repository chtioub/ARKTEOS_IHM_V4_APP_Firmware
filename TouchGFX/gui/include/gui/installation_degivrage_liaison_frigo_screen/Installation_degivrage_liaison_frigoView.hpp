#ifndef INSTALLATION_DEGIVRAGE_LIAISON_FRIGOVIEW_HPP
#define INSTALLATION_DEGIVRAGE_LIAISON_FRIGOVIEW_HPP

#include <gui_generated/installation_degivrage_liaison_frigo_screen/Installation_degivrage_liaison_frigoViewBase.hpp>
#include <gui/installation_degivrage_liaison_frigo_screen/Installation_degivrage_liaison_frigoPresenter.hpp>

class Installation_degivrage_liaison_frigoView : public Installation_degivrage_liaison_frigoViewBase
{
public:
    Installation_degivrage_liaison_frigoView();
    virtual ~Installation_degivrage_liaison_frigoView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

	void bouton_gauche_condition_degivrage();
	void bouton_droit_condition_degivrage();
	void bouton_valider();
	void update_typedegivrage();

	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
	bool bConnexionDistance;
	unsigned char Type_Degivrage  :1;
	uint16_t u16ErreurAffichee;
	S_DATE sDate_old;
	S_STATUT_PAC sStatut_PAC_old;
	touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9];
};

#endif // INSTALLATION_DEGIVRAGE_LIAISON_FRIGOVIEW_HPP
