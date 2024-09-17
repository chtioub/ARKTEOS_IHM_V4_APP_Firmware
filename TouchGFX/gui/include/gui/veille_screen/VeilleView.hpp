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
    void BackgroundClickHandler(const Box& b, const ClickEvent& e);
protected:
    Callback<VeilleView, const Box&, const ClickEvent&> BackgroundClickedCallback;
};

#endif // VEILLEVIEW_HPP
