#ifndef MULTIZONESPRESENTER_HPP
#define MULTIZONESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MultizonesView;

class MultizonesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MultizonesPresenter(MultizonesView& v);

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

    virtual ~MultizonesPresenter() {}

    virtual void changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    MultizonesPresenter();

    MultizonesView& view;
};

#endif // MULTIZONESPRESENTER_HPP
