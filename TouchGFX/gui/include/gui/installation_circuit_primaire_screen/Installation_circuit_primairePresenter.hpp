#ifndef INSTALLATION_CIRCUIT_PRIMAIREPRESENTER_HPP
#define INSTALLATION_CIRCUIT_PRIMAIREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Installation_circuit_primaireView;

class Installation_circuit_primairePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Installation_circuit_primairePresenter(Installation_circuit_primaireView& v);

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

    virtual ~Installation_circuit_primairePresenter() {}

    virtual void changeDate(S_DATE *sDate);
    virtual void changeErreur(uint16_t u16Erreur);
    virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
    virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

    void c_install_param();
    void c_usine_phoenix(int u8Esclave);

private:
    Installation_circuit_primairePresenter();

    Installation_circuit_primaireView& view;
};

#endif // INSTALLATION_CIRCUIT_PRIMAIREPRESENTER_HPP
