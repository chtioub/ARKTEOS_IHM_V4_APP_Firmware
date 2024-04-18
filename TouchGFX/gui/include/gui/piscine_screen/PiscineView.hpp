#ifndef PISCINEVIEW_HPP
#define PISCINEVIEW_HPP

#include <gui_generated/piscine_screen/PiscineViewBase.hpp>
#include <gui/piscine_screen/PiscinePresenter.hpp>

class PiscineView : public PiscineViewBase
{
public:
    PiscineView();
    virtual ~PiscineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PISCINEVIEW_HPP
