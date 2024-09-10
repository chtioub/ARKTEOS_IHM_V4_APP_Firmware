#ifndef HISTORIQUE_DEFAUTSPRESENTER_HPP
#define HISTORIQUE_DEFAUTSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Historique_defautsView;

class Historique_defautsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Historique_defautsPresenter(Historique_defautsView& v);

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

    virtual ~Historique_defautsPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Historique_defautsPresenter();

    Historique_defautsView& view;
};

#endif // HISTORIQUE_DEFAUTSPRESENTER_HPP
