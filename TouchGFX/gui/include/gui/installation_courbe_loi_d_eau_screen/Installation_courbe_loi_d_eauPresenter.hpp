#ifndef INSTALLATION_COURBE_LOI_D_EAUPRESENTER_HPP
#define INSTALLATION_COURBE_LOI_D_EAUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_courbe_loi_d_eauView;

class Installation_courbe_loi_d_eauPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_courbe_loi_d_eauPresenter(Installation_courbe_loi_d_eauView& v);

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

    virtual ~Installation_courbe_loi_d_eauPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_reg_ext();

private:
    Installation_courbe_loi_d_eauPresenter();

    Installation_courbe_loi_d_eauView& view;
};

#endif // INSTALLATION_COURBE_LOI_D_EAUPRESENTER_HPP
