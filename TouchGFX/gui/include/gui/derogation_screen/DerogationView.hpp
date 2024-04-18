#ifndef DEROGATIONVIEW_HPP
#define DEROGATIONVIEW_HPP

#include <gui_generated/derogation_screen/DerogationViewBase.hpp>
#include <gui/derogation_screen/DerogationPresenter.hpp>

class DerogationView : public DerogationViewBase
{
public:
    DerogationView();
    virtual ~DerogationView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DEROGATIONVIEW_HPP
