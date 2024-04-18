#ifndef PROGRAMMATION_ZOOMPRESENTER_HPP
#define PROGRAMMATION_ZOOMPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Programmation_zoomView;

class Programmation_zoomPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Programmation_zoomPresenter(Programmation_zoomView& v);

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

    virtual ~Programmation_zoomPresenter() {}

private:
    Programmation_zoomPresenter();

    Programmation_zoomView& view;
};

#endif // PROGRAMMATION_ZOOMPRESENTER_HPP
