#ifndef INSTALLATION_WATTMETREPRESENTER_HPP
#define INSTALLATION_WATTMETREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_wattmetreView;

class Installation_wattmetrePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_wattmetrePresenter(Installation_wattmetreView& v);

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

    virtual ~Installation_wattmetrePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_param();

private:
    Installation_wattmetrePresenter();

    Installation_wattmetreView& view;
};

#endif // INSTALLATION_WATTMETREPRESENTER_HPP
