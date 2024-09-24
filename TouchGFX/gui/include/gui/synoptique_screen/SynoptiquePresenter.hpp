#ifndef SYNOPTIQUEPRESENTER_HPP
#define SYNOPTIQUEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SynoptiqueView;

class SynoptiquePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SynoptiquePresenter(SynoptiqueView& v);

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

    virtual ~SynoptiquePresenter() {}

    virtual void changeDate(S_DATE *sDate);
   	virtual void changeErreur(uint16_t u16Erreur);
   	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
   	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);

private:
    SynoptiquePresenter();

    SynoptiqueView& view;
};

#endif // SYNOPTIQUEPRESENTER_HPP
