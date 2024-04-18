#ifndef INFOS_SYSTEMEVIEW_HPP
#define INFOS_SYSTEMEVIEW_HPP

#include <gui_generated/infos_systeme_screen/Infos_systemeViewBase.hpp>
#include <gui/infos_systeme_screen/Infos_systemePresenter.hpp>

class Infos_systemeView : public Infos_systemeViewBase
{
public:
    Infos_systemeView();
    virtual ~Infos_systemeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // INFOS_SYSTEMEVIEW_HPP
