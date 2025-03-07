#ifndef INSTALLATION_ECS_SOLAIREPRESENTER_HPP
#define INSTALLATION_ECS_SOLAIREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_ecs_solaireView;

class Installation_ecs_solairePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_ecs_solairePresenter(Installation_ecs_solaireView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

	void c_install_ecs();
/**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Installation_ecs_solairePresenter() {}

private:
    Installation_ecs_solairePresenter();

    Installation_ecs_solaireView& view;
};

#endif // INSTALLATION_ECS_SOLAIREPRESENTER_HPP
