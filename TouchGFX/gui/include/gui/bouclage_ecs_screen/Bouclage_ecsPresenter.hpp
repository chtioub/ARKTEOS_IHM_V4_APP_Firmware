#ifndef BOUCLAGE_ECSPRESENTER_HPP
#define BOUCLAGE_ECSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Bouclage_ecsView;

class Bouclage_ecsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Bouclage_ecsPresenter(Bouclage_ecsView& v);

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

    virtual ~Bouclage_ecsPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_user_ecs();
    void c_prog_option(bool bEnvoi);

private:
    Bouclage_ecsPresenter();

    Bouclage_ecsView& view;
};

#endif // BOUCLAGE_ECSPRESENTER_HPP
