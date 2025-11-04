#ifndef HISTO_FONCTIONNEMENTPRESENTER_HPP
#define HISTO_FONCTIONNEMENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Histo_fonctionnementView;

class Histo_fonctionnementPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Histo_fonctionnementPresenter(Histo_fonctionnementView& v);

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
    virtual void update_graph_histo(DATA_HISTO *data_histo);
    virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);

    virtual ~Histo_fonctionnementPresenter() {}

private:
    Histo_fonctionnementPresenter();

    Histo_fonctionnementView& view;
};

#endif // HISTO_FONCTIONNEMENTPRESENTER_HPP
