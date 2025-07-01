#ifndef LINKYVIEW_HPP
#define LINKYVIEW_HPP

#include <gui_generated/linky_screen/LinkyViewBase.hpp>
#include <gui/linky_screen/LinkyPresenter.hpp>

class LinkyView : public LinkyViewBase
{
public:
    LinkyView();
    virtual ~LinkyView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LINKYVIEW_HPP
