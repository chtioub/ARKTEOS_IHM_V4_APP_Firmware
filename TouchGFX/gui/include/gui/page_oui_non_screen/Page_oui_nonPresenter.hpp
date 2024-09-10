#ifndef PAGE_OUI_NONPRESENTER_HPP
#define PAGE_OUI_NONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Page_oui_nonView;

class Page_oui_nonPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Page_oui_nonPresenter(Page_oui_nonView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Page_oui_nonPresenter() {}
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_ener_raz();
    void c_user_date();
    void c_user_param();
    void c_user_ecs();
    void c_user_zx_all();
    void c_install_param();
    void c_install_raz_config();
    void c_install_config_pac();
    void c_install_piscine();
    void c_install_raz_histo_err();
    void c_usine_password();
    void c_usine_raz_energie();
    void c_usine_raz_config();
    void c_sav_param();
    void c_sav_shunt_tempo();
    void c_sav_raz_tps_fonct(uint8_t u8Esclave);
    void c_sav_raz_soft_flash();
    void c_sav_raz_log();
    void c_restart();

private:
    Page_oui_nonPresenter();

    Page_oui_nonView& view;
};

#endif // PAGE_OUI_NONPRESENTER_HPP
