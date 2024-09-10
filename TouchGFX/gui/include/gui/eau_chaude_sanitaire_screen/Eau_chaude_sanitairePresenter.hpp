#ifndef EAU_CHAUDE_SANITAIREPRESENTER_HPP
#define EAU_CHAUDE_SANITAIREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Eau_chaude_sanitaireView;

class Eau_chaude_sanitairePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Eau_chaude_sanitairePresenter(Eau_chaude_sanitaireView& v);

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

    virtual ~Eau_chaude_sanitairePresenter() {}
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_user_ecs();
    void c_prog_ecs(bool bEnvoi);
    void c_prog_option(bool bEnvoi);

private:
    Eau_chaude_sanitairePresenter();

    Eau_chaude_sanitaireView& view;
};

#endif // EAU_CHAUDE_SANITAIREPRESENTER_HPP
