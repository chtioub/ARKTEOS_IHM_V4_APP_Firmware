#ifndef PISCINEPRESENTER_HPP
#define PISCINEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class PiscineView;

class PiscinePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    PiscinePresenter(PiscineView& v);

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

    virtual ~PiscinePresenter() {}

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);

	void c_user_piscine();
	void c_prog_piscine(bool bEnvoi);

private:
    PiscinePresenter();

    PiscineView& view;
};

#endif // PISCINEPRESENTER_HPP
