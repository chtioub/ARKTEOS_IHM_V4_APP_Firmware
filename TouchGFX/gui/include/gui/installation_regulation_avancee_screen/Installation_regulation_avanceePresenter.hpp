#ifndef INSTALLATION_REGULATION_AVANCEEPRESENTER_HPP
#define INSTALLATION_REGULATION_AVANCEEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_regulation_avanceeView;

class Installation_regulation_avanceePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_regulation_avanceePresenter(Installation_regulation_avanceeView& v);

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

    virtual ~Installation_regulation_avanceePresenter() {}

	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

//	void c_install_config_pac();
//	void c_install_param();
//	void c_user_param();
//
	void c_install_param();
	void c_user_zx_all();
	void c_usine_param();


//	void c_install_piscine();

private:
    Installation_regulation_avanceePresenter();

    Installation_regulation_avanceeView& view;
};

#endif // INSTALLATION_REGULATION_AVANCEEPRESENTER_HPP
