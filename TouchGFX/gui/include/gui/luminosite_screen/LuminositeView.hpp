#ifndef LUMINOSITEVIEW_HPP
#define LUMINOSITEVIEW_HPP

#include <gui_generated/luminosite_screen/LuminositeViewBase.hpp>
#include <gui/luminosite_screen/LuminositePresenter.hpp>

class LuminositeView : public LuminositeViewBase
{
public:
    LuminositeView();
    virtual ~LuminositeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // LUMINOSITEVIEW_HPP
