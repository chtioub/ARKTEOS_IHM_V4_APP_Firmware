#ifndef SECOURSVIEW_HPP
#define SECOURSVIEW_HPP

#include <gui_generated/secours_screen/SecoursViewBase.hpp>
#include <gui/secours_screen/SecoursPresenter.hpp>

class SecoursView : public SecoursViewBase
{
public:
    SecoursView();
    virtual ~SecoursView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SECOURSVIEW_HPP
