#ifndef ERREURSVIEW_HPP
#define ERREURSVIEW_HPP

#include <gui_generated/erreurs_screen/ErreursViewBase.hpp>
#include <gui/erreurs_screen/ErreursPresenter.hpp>

class ErreursView : public ErreursViewBase
{
public:
    ErreursView();
    virtual ~ErreursView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ERREURSVIEW_HPP
