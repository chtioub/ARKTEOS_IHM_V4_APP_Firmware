#ifndef HISTO_FONCTIONNEMENTAPRESENTER_HPP
#define HISTO_FONCTIONNEMENTAPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Histo_fonctionnementaView;

class Histo_fonctionnementaPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Histo_fonctionnementaPresenter(Histo_fonctionnementaView& v);

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

    virtual ~Histo_fonctionnementaPresenter() {}

private:
    Histo_fonctionnementaPresenter();

    Histo_fonctionnementaView& view;
};

#endif // HISTO_FONCTIONNEMENTAPRESENTER_HPP
