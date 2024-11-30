#ifndef INSTALLATION_HYDRAULIQUE_REPARTITION_PW_ZONEPRESENTER_HPP
#define INSTALLATION_HYDRAULIQUE_REPARTITION_PW_ZONEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_hydraulique_repartition_PW_zoneView;

class Installation_hydraulique_repartition_PW_zonePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_hydraulique_repartition_PW_zonePresenter(Installation_hydraulique_repartition_PW_zoneView& v);

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

    virtual ~Installation_hydraulique_repartition_PW_zonePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_zx(uint8_t u8NumZone);

private:
    Installation_hydraulique_repartition_PW_zonePresenter();

    Installation_hydraulique_repartition_PW_zoneView& view;
};

#endif // INSTALLATION_HYDRAULIQUE_REPARTITION_PW_ZONEPRESENTER_HPP
