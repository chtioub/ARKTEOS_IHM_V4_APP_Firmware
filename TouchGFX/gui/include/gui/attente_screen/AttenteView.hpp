#ifndef ATTENTEVIEW_HPP
#define ATTENTEVIEW_HPP

#include <gui_generated/attente_screen/AttenteViewBase.hpp>
#include <gui/attente_screen/AttentePresenter.hpp>

class AttenteView : public AttenteViewBase
{
public:
    AttenteView();
    virtual ~AttenteView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ATTENTEVIEW_HPP
