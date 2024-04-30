#ifndef VACANCESPRESENTER_HPP
#define VACANCESPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class VacancesView;

class VacancesPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    VacancesPresenter(VacancesView& v);

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

    virtual ~VacancesPresenter() {}

private:
    VacancesPresenter();

    VacancesView& view;
};

#endif // VACANCESPRESENTER_HPP
