#ifndef VEILLEVIEW_HPP
#define VEILLEVIEW_HPP

#include <gui_generated/veille_screen/VeilleViewBase.hpp>
#include <gui/veille_screen/VeillePresenter.hpp>

class VeilleView : public VeilleViewBase
{
public:
    VeilleView();
    virtual ~VeilleView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // VEILLEVIEW_HPP
