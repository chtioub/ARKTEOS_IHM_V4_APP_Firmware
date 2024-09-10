#ifndef MAINTENANCE_TEST_COMPOSANTSPRESENTER_HPP
#define MAINTENANCE_TEST_COMPOSANTSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Maintenance_test_composantsView;

class Maintenance_test_composantsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Maintenance_test_composantsPresenter(Maintenance_test_composantsView& v);

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

    virtual ~Maintenance_test_composantsPresenter() {}

private:
    Maintenance_test_composantsPresenter();

    Maintenance_test_composantsView& view;
};

#endif // MAINTENANCE_TEST_COMPOSANTSPRESENTER_HPP
