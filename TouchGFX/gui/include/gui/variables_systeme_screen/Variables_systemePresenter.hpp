#ifndef VARIABLES_SYSTEMEPRESENTER_HPP
#define VARIABLES_SYSTEMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Variables_systemeView;

class Variables_systemePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Variables_systemePresenter(Variables_systemeView& v);

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

    virtual ~Variables_systemePresenter() {}

    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Variables_systemePresenter();

    Variables_systemeView& view;
};

#endif // VARIABLES_SYSTEMEPRESENTER_HPP
