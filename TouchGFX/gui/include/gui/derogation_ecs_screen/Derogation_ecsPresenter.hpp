#ifndef DEROGATION_ECSPRESENTER_HPP
#define DEROGATION_ECSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Derogation_ecsView;

class Derogation_ecsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Derogation_ecsPresenter(Derogation_ecsView& v);

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

    virtual ~Derogation_ecsPresenter() {}

private:
    Derogation_ecsPresenter();

    Derogation_ecsView& view;
};

#endif // DEROGATION_ECSPRESENTER_HPP
