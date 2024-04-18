#ifndef BOUCLAGE_ECSPRESENTER_HPP
#define BOUCLAGE_ECSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Bouclage_ecsView;

class Bouclage_ecsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Bouclage_ecsPresenter(Bouclage_ecsView& v);

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

    virtual ~Bouclage_ecsPresenter() {}

private:
    Bouclage_ecsPresenter();

    Bouclage_ecsView& view;
};

#endif // BOUCLAGE_ECSPRESENTER_HPP
