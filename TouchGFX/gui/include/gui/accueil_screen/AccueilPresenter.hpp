#ifndef ACCUEILPRESENTER_HPP
#define ACCUEILPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class AccueilView;

class AccueilPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    AccueilPresenter(AccueilView& v);

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

    virtual ~AccueilPresenter() {}

    void editLuminosite(uint8_t u8Luminosite);

    virtual void changeModePac(bool marche);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeStatutPrimaire(S_STATUT_PRIMAIRE *sStatut_Primaire);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutECS(S_STATUT_ECS *sStatut_ECS);
    virtual void changeStatutPiscine(S_STATUT_PISCINE *sStatut_Piscine);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);
    virtual void changeStatutZx(uint8_t u8Zone, S_STATUT_ZX *sStatut_Zx);
    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutRegulExt(S_STATUT_REG_EXT *sStatut_RegulExt);

    void c_prog_ecs(bool bEnvoi);
private:
    AccueilPresenter();

    AccueilView& view;
};

#endif // ACCUEILPRESENTER_HPP
