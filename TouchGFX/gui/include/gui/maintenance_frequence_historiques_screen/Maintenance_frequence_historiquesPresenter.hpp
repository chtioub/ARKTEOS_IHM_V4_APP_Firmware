#ifndef MAINTENANCE_FREQUENCE_HISTORIQUESPRESENTER_HPP
#define MAINTENANCE_FREQUENCE_HISTORIQUESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Maintenance_frequence_historiquesView;

class Maintenance_frequence_historiquesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Maintenance_frequence_historiquesPresenter(Maintenance_frequence_historiquesView& v);

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

    virtual ~Maintenance_frequence_historiquesPresenter() {}

    virtual void changeDate(S_DATE *sDate);
 	virtual void changeErreur(uint16_t u16Erreur);
 	virtual void changeStatutPAC(S_STATUT_PAC *sStatut_PAC);
 	virtual void changeStatutEther(S_CYC_ETHER_III *sCycEther);

 	void c_sav_param();

private:
    Maintenance_frequence_historiquesPresenter();

    Maintenance_frequence_historiquesView& view;
};

#endif // MAINTENANCE_FREQUENCE_HISTORIQUESPRESENTER_HPP
