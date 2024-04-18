#ifndef MARCHE_ARRETPRESENTER_HPP
#define MARCHE_ARRETPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Marche_ArretView;

class Marche_ArretPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Marche_ArretPresenter(Marche_ArretView& v);

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

    virtual ~Marche_ArretPresenter() {}

private:
    Marche_ArretPresenter();

    Marche_ArretView& view;
};

#endif // MARCHE_ARRETPRESENTER_HPP
