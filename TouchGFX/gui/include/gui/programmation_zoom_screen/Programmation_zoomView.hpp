#ifndef PROGRAMMATION_ZOOMVIEW_HPP
#define PROGRAMMATION_ZOOMVIEW_HPP

#include <gui_generated/programmation_zoom_screen/Programmation_zoomViewBase.hpp>
#include <gui/programmation_zoom_screen/Programmation_zoomPresenter.hpp>

class Programmation_zoomView : public Programmation_zoomViewBase
{
public:
    Programmation_zoomView();
    virtual ~Programmation_zoomView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // PROGRAMMATION_ZOOMVIEW_HPP
