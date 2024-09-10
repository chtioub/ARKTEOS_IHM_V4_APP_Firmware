#ifndef ZONEPRESENTER_HPP
#define ZONEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ZoneView;

class ZonePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ZonePresenter(ZoneView& v);

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

    virtual ~ZonePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);

    void c_user_param();
    void c_user_zx(uint8_t u8Zone);
    void c_user_reg_ext();
    void c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi);
    void c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi);
    void c_prog_reg_ext_chaud(bool bEnvoi);
    void c_prog_reg_ext_froid(bool bEnvoi);

private:
    ZonePresenter();

    ZoneView& view;
};

#endif // ZONEPRESENTER_HPP
