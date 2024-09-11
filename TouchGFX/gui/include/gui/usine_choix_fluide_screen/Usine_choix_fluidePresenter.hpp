#ifndef USINE_CHOIX_FLUIDEPRESENTER_HPP
#define USINE_CHOIX_FLUIDEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_choix_fluideView;

class Usine_choix_fluidePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_choix_fluidePresenter(Usine_choix_fluideView& v);

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

    virtual ~Usine_choix_fluidePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_usine_param();

private:
    Usine_choix_fluidePresenter();

    Usine_choix_fluideView& view;
};

#endif // USINE_CHOIX_FLUIDEPRESENTER_HPP
