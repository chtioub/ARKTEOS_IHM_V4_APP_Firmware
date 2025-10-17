#ifndef HISTO_FONCTIONNEMENTPRESENTER_HPP
#define HISTO_FONCTIONNEMENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Histo_fonctionnementView;

class Histo_fonctionnementPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Histo_fonctionnementPresenter(Histo_fonctionnementView& v);

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

    virtual ~Histo_fonctionnementPresenter() {}

private:
    Histo_fonctionnementPresenter();

    Histo_fonctionnementView& view;
};

#endif // HISTO_FONCTIONNEMENTPRESENTER_HPP
