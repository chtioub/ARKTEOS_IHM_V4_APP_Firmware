#ifndef USINE_CALIBRAGE_OFFSETVIEW_HPP
#define USINE_CALIBRAGE_OFFSETVIEW_HPP

#include <gui_generated/usine_calibrage_offset_screen/Usine_calibrage_offsetViewBase.hpp>
#include <gui/usine_calibrage_offset_screen/Usine_calibrage_offsetPresenter.hpp>

class Usine_calibrage_offsetView : public Usine_calibrage_offsetViewBase
{
public:
    Usine_calibrage_offsetView();
    virtual ~Usine_calibrage_offsetView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // USINE_CALIBRAGE_OFFSETVIEW_HPP
