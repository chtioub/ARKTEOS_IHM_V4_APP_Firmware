#ifndef USINE_CONFIG_ADDITIONNELLEPRESENTER_HPP
#define USINE_CONFIG_ADDITIONNELLEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_config_additionnelleView;

class Usine_config_additionnellePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_config_additionnellePresenter(Usine_config_additionnelleView& v);

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

    virtual ~Usine_config_additionnellePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_param();

private:
    Usine_config_additionnellePresenter();

    Usine_config_additionnelleView& view;
};

#endif // USINE_CONFIG_ADDITIONNELLEPRESENTER_HPP
