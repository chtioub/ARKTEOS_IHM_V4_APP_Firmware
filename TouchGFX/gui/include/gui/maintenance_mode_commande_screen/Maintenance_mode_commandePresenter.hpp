#ifndef MAINTENANCE_MODE_COMMANDEPRESENTER_HPP
#define MAINTENANCE_MODE_COMMANDEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Maintenance_mode_commandeView;

class Maintenance_mode_commandePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Maintenance_mode_commandePresenter(Maintenance_mode_commandeView& v);

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

    virtual ~Maintenance_mode_commandePresenter() {}

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);

	void c_sav_par21();

private:
    Maintenance_mode_commandePresenter();

    Maintenance_mode_commandeView& view;
};

#endif // MAINTENANCE_MODE_COMMANDEPRESENTER_HPP
