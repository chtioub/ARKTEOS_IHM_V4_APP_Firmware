#ifndef HISTORIQUES_FONCTIONNEMENTPRESENTER_HPP
#define HISTORIQUES_FONCTIONNEMENTPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Historiques_fonctionnementView;

class Historiques_fonctionnementPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Historiques_fonctionnementPresenter(Historiques_fonctionnementView& v);

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

    virtual ~Historiques_fonctionnementPresenter() {}

private:
    Historiques_fonctionnementPresenter();

    Historiques_fonctionnementView& view;
};

#endif // HISTORIQUES_FONCTIONNEMENTPRESENTER_HPP
