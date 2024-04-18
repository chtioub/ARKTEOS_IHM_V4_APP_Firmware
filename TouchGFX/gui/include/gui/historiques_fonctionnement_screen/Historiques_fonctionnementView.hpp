#ifndef HISTORIQUES_FONCTIONNEMENTVIEW_HPP
#define HISTORIQUES_FONCTIONNEMENTVIEW_HPP

#include <gui_generated/historiques_fonctionnement_screen/Historiques_fonctionnementViewBase.hpp>
#include <gui/historiques_fonctionnement_screen/Historiques_fonctionnementPresenter.hpp>

class Historiques_fonctionnementView : public Historiques_fonctionnementViewBase
{
public:
    Historiques_fonctionnementView();
    virtual ~Historiques_fonctionnementView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HISTORIQUES_FONCTIONNEMENTVIEW_HPP
