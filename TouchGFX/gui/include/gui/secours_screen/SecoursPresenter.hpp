#ifndef SECOURSPRESENTER_HPP
#define SECOURSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class SecoursView;

class SecoursPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SecoursPresenter(SecoursView& v);

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

    virtual ~SecoursPresenter() {}

private:
    SecoursPresenter();

    SecoursView& view;
};

#endif // SECOURSPRESENTER_HPP
