#ifndef COURBE_LOI_D_EAUPRESENTER_HPP
#define COURBE_LOI_D_EAUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Courbe_loi_d_eauView;

class Courbe_loi_d_eauPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Courbe_loi_d_eauPresenter(Courbe_loi_d_eauView& v);

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

    virtual ~Courbe_loi_d_eauPresenter() {}

private:
    Courbe_loi_d_eauPresenter();

    Courbe_loi_d_eauView& view;
};

#endif // COURBE_LOI_D_EAUPRESENTER_HPP
