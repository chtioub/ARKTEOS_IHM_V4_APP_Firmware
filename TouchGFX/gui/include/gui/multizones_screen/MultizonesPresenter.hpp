#ifndef MULTIZONESPRESENTER_HPP
#define MULTIZONESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class MultizonesView;

class MultizonesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    MultizonesPresenter(MultizonesView& v);

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

    virtual ~MultizonesPresenter() {}

private:
    MultizonesPresenter();

    MultizonesView& view;
};

#endif // MULTIZONESPRESENTER_HPP
