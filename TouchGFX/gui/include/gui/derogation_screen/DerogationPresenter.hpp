#ifndef DEROGATIONPRESENTER_HPP
#define DEROGATIONPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DerogationView;

class DerogationPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DerogationPresenter(DerogationView& v);

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

    virtual ~DerogationPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_user_zx(uint8_t u8Zone);
    void c_user_reg_ext();

private:
    DerogationPresenter();

    DerogationView& view;
};

#endif // DEROGATIONPRESENTER_HPP
