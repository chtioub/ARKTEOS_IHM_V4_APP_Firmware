#ifndef INSTALLATION_HYDRAULIQUE_SONDE_RFPRESENTER_HPP
#define INSTALLATION_HYDRAULIQUE_SONDE_RFPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_hydraulique_sonde_rfView;

class Installation_hydraulique_sonde_rfPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_hydraulique_sonde_rfPresenter(Installation_hydraulique_sonde_rfView& v);

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

    virtual ~Installation_hydraulique_sonde_rfPresenter() {}

    void c_install_zx(uint8_t u8NumZone);
    void c_install_th_association(uint8_t u8NumZone);
    void c_install_th_dissociation(uint8_t u8NumZone);

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeStatutRF(S_STATUT_RF *sStatut_RF);

private:
    Installation_hydraulique_sonde_rfPresenter();

    Installation_hydraulique_sonde_rfView& view;
};

#endif // INSTALLATION_HYDRAULIQUE_SONDE_RFPRESENTER_HPP
