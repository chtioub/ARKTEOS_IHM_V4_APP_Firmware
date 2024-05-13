#ifndef MULTIZONESVIEW_HPP
#define MULTIZONESVIEW_HPP

#include <gui_generated/multizones_screen/MultizonesViewBase.hpp>
#include <gui/multizones_screen/MultizonesPresenter.hpp>

class MultizonesView : public MultizonesViewBase
{
public:
    MultizonesView();
    virtual ~MultizonesView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // MULTIZONESVIEW_HPP
