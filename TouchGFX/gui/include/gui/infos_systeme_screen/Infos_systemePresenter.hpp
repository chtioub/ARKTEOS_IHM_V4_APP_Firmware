#ifndef INFOS_SYSTEMEPRESENTER_HPP
#define INFOS_SYSTEMEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Infos_systemeView;

class Infos_systemePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Infos_systemePresenter(Infos_systemeView& v);

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

    virtual ~Infos_systemePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);

private:
    Infos_systemePresenter();

    Infos_systemeView& view;
};

#endif // INFOS_SYSTEMEPRESENTER_HPP
