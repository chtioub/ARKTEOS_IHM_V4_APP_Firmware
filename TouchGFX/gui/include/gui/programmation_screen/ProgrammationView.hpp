#ifndef PROGRAMMATIONVIEW_HPP
#define PROGRAMMATIONVIEW_HPP

#include <gui_generated/programmation_screen/ProgrammationViewBase.hpp>
#include <gui/programmation_screen/ProgrammationPresenter.hpp>

class ProgrammationView : public ProgrammationViewBase
{
public:
    ProgrammationView();
    virtual ~ProgrammationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PROGRAMMATIONVIEW_HPP
