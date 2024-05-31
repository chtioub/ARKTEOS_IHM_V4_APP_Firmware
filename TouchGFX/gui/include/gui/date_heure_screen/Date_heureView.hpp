#ifndef DATE_HEUREVIEW_HPP
#define DATE_HEUREVIEW_HPP

#include <gui_generated/date_heure_screen/Date_heureViewBase.hpp>
#include <gui/date_heure_screen/Date_heurePresenter.hpp>

class Date_heureView : public Date_heureViewBase
{
public:
    Date_heureView();
    virtual ~Date_heureView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DATE_HEUREVIEW_HPP
