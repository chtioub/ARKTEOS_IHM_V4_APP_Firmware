#ifndef HISTO_FONCTIONNEMENTAVIEW_HPP
#define HISTO_FONCTIONNEMENTAVIEW_HPP

#include <gui_generated/histo_fonctionnementa_screen/Histo_fonctionnementaViewBase.hpp>
#include <gui/histo_fonctionnementa_screen/Histo_fonctionnementaPresenter.hpp>

class Histo_fonctionnementaView : public Histo_fonctionnementaViewBase
{
public:
    Histo_fonctionnementaView();
    virtual ~Histo_fonctionnementaView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // HISTO_FONCTIONNEMENTAVIEW_HPP
