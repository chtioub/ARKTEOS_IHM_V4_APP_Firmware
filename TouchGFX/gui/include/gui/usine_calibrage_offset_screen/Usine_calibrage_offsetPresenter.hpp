#ifndef USINE_CALIBRAGE_OFFSETPRESENTER_HPP
#define USINE_CALIBRAGE_OFFSETPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Usine_calibrage_offsetView;

class Usine_calibrage_offsetPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Usine_calibrage_offsetPresenter(Usine_calibrage_offsetView& v);

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

    virtual ~Usine_calibrage_offsetPresenter() {}

private:
    Usine_calibrage_offsetPresenter();

    Usine_calibrage_offsetView& view;
};

#endif // USINE_CALIBRAGE_OFFSETPRESENTER_HPP
