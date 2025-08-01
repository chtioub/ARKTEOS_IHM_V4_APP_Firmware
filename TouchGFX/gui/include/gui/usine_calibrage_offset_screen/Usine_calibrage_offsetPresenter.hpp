#ifndef USINE_CALIBRAGE_OFFSETPRESENTER_HPP
#define USINE_CALIBRAGE_OFFSETPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_calibrage_offsetView;

class Usine_calibrage_offsetPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_calibrage_offsetPresenter(Usine_calibrage_offsetView& v);

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

    virtual ~Usine_calibrage_offsetPresenter() {}

    void c_usine_offset();

//    virtual void changeOffset(S_CONFIG_OFFSET *sConfig_Offset);
	virtual void changeDate(S_DATE *sDate);
	virtual void changeErreur(uint16_t u16Erreur);
	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
	virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Usine_calibrage_offsetPresenter();

    Usine_calibrage_offsetView& view;
};

#endif // USINE_CALIBRAGE_OFFSETPRESENTER_HPP
