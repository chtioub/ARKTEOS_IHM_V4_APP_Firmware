#ifndef PROGRAMMATIONPRESENTER_HPP
#define PROGRAMMATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class ProgrammationView;

class ProgrammationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    ProgrammationPresenter(ProgrammationView& v);

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

    virtual ~ProgrammationPresenter() {}

    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_prog_ecs(bool bEnvoi);
    void c_prog_option(bool bEnvoi);
    void c_prog_piscine(bool bEnvoi);
    void c_prog_zone_chaud(uint8_t u8Zone, bool bEnvoi);
    void c_prog_zone_froid(uint8_t u8Zone, bool bEnvoi);
    void c_prog_reg_ext_chaud(bool bEnvoi);
    void c_prog_reg_ext_froid(bool bEnvoi);

private:
    ProgrammationPresenter();

    ProgrammationView& view;
};

#endif // PROGRAMMATIONPRESENTER_HPP
