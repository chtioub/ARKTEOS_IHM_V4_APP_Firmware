#ifndef LANGUEVIEW_HPP
#define LANGUEVIEW_HPP

#include <gui_generated/langue_screen/LangueViewBase.hpp>
#include <gui/langue_screen/LanguePresenter.hpp>

class LangueView : public LangueViewBase
{
public:
    LangueView();
    virtual ~LangueView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LANGUEVIEW_HPP
