#ifndef ENERGIES_HISTOPRESENTER_HPP
#define ENERGIES_HISTOPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Energies_histoView;

class Energies_histoPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Energies_histoPresenter(Energies_histoView& v);

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

    virtual ~Energies_histoPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Energies_histoPresenter();

    Energies_histoView& view;
};

#endif // ENERGIES_HISTOPRESENTER_HPP
