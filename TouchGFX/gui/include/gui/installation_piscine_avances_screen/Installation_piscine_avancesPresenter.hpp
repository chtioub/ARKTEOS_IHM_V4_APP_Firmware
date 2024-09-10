#ifndef INSTALLATION_PISCINE_AVANCESPRESENTER_HPP
#define INSTALLATION_PISCINE_AVANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_piscine_avancesView;

class Installation_piscine_avancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_piscine_avancesPresenter(Installation_piscine_avancesView& v);

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

    virtual ~Installation_piscine_avancesPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_piscine();
    void c_prog_piscine(bool bEnvoi);

private:
    Installation_piscine_avancesPresenter();

    Installation_piscine_avancesView& view;
};

#endif // INSTALLATION_PISCINE_AVANCESPRESENTER_HPP
