#ifndef USINEVIEW_HPP
#define USINEVIEW_HPP

#include <gui_generated/usine_screen/UsineViewBase.hpp>
#include <gui/usine_screen/UsinePresenter.hpp>

class UsineView : public UsineViewBase
{
public:
    UsineView();
    virtual ~UsineView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINEVIEW_HPP
