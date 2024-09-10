#ifndef ENERGIESPRESENTER_HPP
#define ENERGIESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class EnergiesView;

class EnergiesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    EnergiesPresenter(EnergiesView& v);

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

    virtual ~EnergiesPresenter() {}

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_ener_cumul_prod();
    void c_ener_cumul_conso();
    void c_ener_histo_12m_conso();
    void c_ener_histo_24j_conso();
    void c_ener_histo_24h_conso();
    void c_ener_histo_12m_prod();
    void c_ener_histo_24j_prod();
    void c_ener_histo_24h_prod();

private:
    EnergiesPresenter();

    EnergiesView& view;
};

#endif // ENERGIESPRESENTER_HPP
