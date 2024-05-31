#ifndef DATE_HEUREPRESENTER_HPP
#define DATE_HEUREPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Date_heureView;

class Date_heurePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Date_heurePresenter(Date_heureView& v);

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

    virtual ~Date_heurePresenter() {}

private:
    Date_heurePresenter();

    Date_heureView& view;
};

#endif // DATE_HEUREPRESENTER_HPP
