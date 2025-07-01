#ifndef CODE_NUMERIQUEPRESENTER_HPP
#define CODE_NUMERIQUEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Code_numeriqueView;

class Code_numeriquePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Code_numeriquePresenter(Code_numeriqueView& v);

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

    virtual ~Code_numeriquePresenter() {}

    virtual void changeStatutCyclFrigo(S_CYCL_REG_FRI *sCyclRegFrigo);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_usine_password();
    void c_sav_mode_commande();
    void c_install_date_install();

private:
    Code_numeriquePresenter();

    Code_numeriqueView& view;
};

#endif // CODE_NUMERIQUEPRESENTER_HPP
