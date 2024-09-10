#ifndef DEROGATION_ECSPRESENTER_HPP
#define DEROGATION_ECSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Derogation_ecsView;

class Derogation_ecsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Derogation_ecsPresenter(Derogation_ecsView& v);

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

    virtual ~Derogation_ecsPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);

    void c_user_ecs();

private:
    Derogation_ecsPresenter();

    Derogation_ecsView& view;
};

#endif // DEROGATION_ECSPRESENTER_HPP
