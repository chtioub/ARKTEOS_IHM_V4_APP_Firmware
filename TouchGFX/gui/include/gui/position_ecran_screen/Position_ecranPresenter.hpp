#ifndef POSITION_ECRANPRESENTER_HPP
#define POSITION_ECRANPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Position_ecranView;

class Position_ecranPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Position_ecranPresenter(Position_ecranView& v);

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

    virtual ~Position_ecranPresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_user_param();

private:
    Position_ecranPresenter();

    Position_ecranView& view;
};

#endif // POSITION_ECRANPRESENTER_HPP
