#ifndef TEST_PACPRESENTER_HPP
#define TEST_PACPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Test_pacView;

class Test_pacPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Test_pacPresenter(Test_pacView& v);

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

    virtual ~Test_pacPresenter() {}

    void c_sav_test_pac();

	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Test_pacPresenter();

    Test_pacView& view;
};

#endif // TEST_PACPRESENTER_HPP
