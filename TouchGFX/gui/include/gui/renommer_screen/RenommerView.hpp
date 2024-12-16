#ifndef RENOMMERVIEW_HPP
#define RENOMMERVIEW_HPP

#include <gui_generated/renommer_screen/RenommerViewBase.hpp>
#include <gui/renommer_screen/RenommerPresenter.hpp>

class RenommerView : public RenommerViewBase
{
public:
    RenommerView();
    virtual ~RenommerView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void bouton_retour();
    void bouton_1();
    void bouton_2();
    void bouton_3();
    void bouton_4();
    void bouton_5();
    void bouton_6();
    void bouton_7();
    void bouton_8();
    void bouton_9();
    void bouton_0();
    void bouton_a();
    void bouton_b();
    void bouton_c();
    void bouton_d();
    void bouton_e();
    void bouton_f();
    void bouton_g();
    void bouton_h();
    void bouton_i();
    void bouton_j();
    void bouton_k();
    void bouton_l();
    void bouton_m();
    void bouton_n();
    void bouton_o();
    void bouton_p();
    void bouton_q();
    void bouton_r();
    void bouton_s();
    void bouton_t();
    void bouton_u();
    void bouton_v();
    void bouton_w();
    void bouton_x();
    void bouton_y();
    void bouton_z();
    void bouton_point();
    void bouton__();
    void bouton_aro();
    void bouton_tiret();
    void bouton_space();
    void bouton_valider();
    void bouton_maj();
    void bouton_supprimer();
    void affichageTexte();



	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
protected:
     	 bool bConnexionDistance, bMajActif, bMultizone;
     	 uint8_t u8Caractere, u8NomTemp[10], u8IndexCurseur;
         uint16_t u16ErreurAffichee;
         S_DATE sDate_old;
         S_STATUT_PAC sStatut_PAC_old;

         touchgfx::Unicode::UnicodeChar textAreaBuffer_Titre[40], textAreaBuffer_Heure[6], textAreaBuffer_Date[9], textAreaBuffer_a[2], textAreaBuffer_z[2], textAreaBuffer_e[2], textAreaBuffer_r[2], textAreaBuffer_t[2], textAreaBuffer_y[2], textAreaBuffer_u[2], textAreaBuffer_i[2], textAreaBuffer_o[2], textAreaBuffer_p[2], textAreaBuffer_q[2], textAreaBuffer_s[2], textAreaBuffer_d[2], textAreaBuffer_f[2]
										 , textAreaBuffer_g[2], textAreaBuffer_h[2], textAreaBuffer_j[2], textAreaBuffer_k[2], textAreaBuffer_l[2], textAreaBuffer_m[2], textAreaBuffer_w[2], textAreaBuffer_x[2], textAreaBuffer_c[2], textAreaBuffer_v[2], textAreaBuffer_b[2], textAreaBuffer_n[2], textAreaBuffer_Nom[11];

};

#endif // RENOMMERVIEW_HPP
