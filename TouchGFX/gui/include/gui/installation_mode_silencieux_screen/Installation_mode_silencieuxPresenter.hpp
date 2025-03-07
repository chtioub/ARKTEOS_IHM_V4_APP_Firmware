#ifndef INSTALLATION_MODE_SILENCIEUXPRESENTER_HPP
#define INSTALLATION_MODE_SILENCIEUXPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_mode_silencieuxView;

class Installation_mode_silencieuxPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_mode_silencieuxPresenter(Installation_mode_silencieuxView& v);

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

    virtual ~Installation_mode_silencieuxPresenter() {}

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

	void c_user_param();
	void c_install_param();

private:
    Installation_mode_silencieuxPresenter();

    Installation_mode_silencieuxView& view;
};

#endif // INSTALLATION_MODE_SILENCIEUXPRESENTER_HPP
