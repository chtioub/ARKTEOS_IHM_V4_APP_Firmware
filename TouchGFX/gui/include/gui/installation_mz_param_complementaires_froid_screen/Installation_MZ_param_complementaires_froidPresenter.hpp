#ifndef INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDPRESENTER_HPP
#define INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_MZ_param_complementaires_froidView;

class Installation_MZ_param_complementaires_froidPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_MZ_param_complementaires_froidPresenter(Installation_MZ_param_complementaires_froidView& v);

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

    virtual ~Installation_MZ_param_complementaires_froidPresenter() {}

    void c_install_zx(uint8_t u8NumZone);

  virtual void changeDate(S_DATE *sDate);
  virtual void changeErreur(uint16_t u16Erreur);
  virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
  virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

private:
    Installation_MZ_param_complementaires_froidPresenter();

    Installation_MZ_param_complementaires_froidView& view;
};

#endif // INSTALLATION_MZ_PARAM_COMPLEMENTAIRES_FROIDPRESENTER_HPP
