#ifndef USINE_PARAM_AVANCESPRESENTER_HPP
#define USINE_PARAM_AVANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_param_avancesView;

class Usine_param_avancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_param_avancesPresenter(Usine_param_avancesView& v);

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

    virtual ~Usine_param_avancesPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Usine_param_avancesPresenter();

    Usine_param_avancesView& view;
};

#endif // USINE_PARAM_AVANCESPRESENTER_HPP