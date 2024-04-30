#ifndef VACANCESVIEW_HPP
#define VACANCESVIEW_HPP

#include <gui_generated/vacances_screen/VacancesViewBase.hpp>
#include <gui/vacances_screen/VacancesPresenter.hpp>

class VacancesView : public VacancesViewBase
{
public:
    VacancesView();
    virtual ~VacancesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // VACANCESVIEW_HPP
