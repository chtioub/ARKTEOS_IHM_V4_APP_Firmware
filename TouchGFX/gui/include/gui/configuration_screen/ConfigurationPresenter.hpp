#ifndef CONFIGURATIONPRESENTER_HPP
#define CONFIGURATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ConfigurationView;

class ConfigurationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
	ConfigurationPresenter(ConfigurationView& v);

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

	    virtual ~ConfigurationPresenter() {}

	    void editLuminosite(uint8_t u8Luminosite);

	    virtual void changeDate(S_DATE *sDate);
	    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	    virtual void changeErreur(uint16_t u16Erreur);

	private:
	    ConfigurationPresenter();

	    ConfigurationView& view;
	};

	#endif // ACCUEILPRESENTER_HPP
