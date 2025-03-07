#ifndef INSTALLATION_HYSTERESISPRESENTER_HPP
#define INSTALLATION_HYSTERESISPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_hysteresisView;

class Installation_hysteresisPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_hysteresisPresenter(Installation_hysteresisView& v);

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

    virtual ~Installation_hysteresisPresenter() {}

    void c_install_param_zx();
    void c_install_param();
    void c_install_ecs();
    void c_install_piscine();
    void c_install_config_pac();

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);


//    virtual void Red_Butt();
//	virtual void Blue_Butt();

private:
    Installation_hysteresisPresenter();

    Installation_hysteresisView& view;
};

#endif // INSTALLATION_HYSTERESISPRESENTER_HPP
