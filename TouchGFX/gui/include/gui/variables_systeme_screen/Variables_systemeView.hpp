#ifndef VARIABLES_SYSTEMEVIEW_HPP
#define VARIABLES_SYSTEMEVIEW_HPP

#include <gui_generated/variables_systeme_screen/Variables_systemeViewBase.hpp>
#include <gui/variables_systeme_screen/Variables_systemePresenter.hpp>

class Variables_systemeView : public Variables_systemeViewBase
{
public:
    Variables_systemeView();
    virtual ~Variables_systemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // VARIABLES_SYSTEMEVIEW_HPP
