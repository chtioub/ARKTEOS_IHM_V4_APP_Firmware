#ifndef INSTALLATION_HYDRAULIQUEPRESENTER_HPP
#define INSTALLATION_HYDRAULIQUEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_hydrauliqueView;

class Installation_hydrauliquePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_hydrauliquePresenter(Installation_hydrauliqueView& v);

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

    virtual ~Installation_hydrauliquePresenter() {}

    virtual void changeConfig(S_CONFIG_IHM *sConfig_IHM);
    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_param();
    void c_install_param_zx();

private:
    Installation_hydrauliquePresenter();

    Installation_hydrauliqueView& view;
};

#endif // INSTALLATION_HYDRAULIQUEPRESENTER_HPP
