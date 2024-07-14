#ifndef POSITION_ECRANVIEW_HPP
#define POSITION_ECRANVIEW_HPP

#include <gui_generated/position_ecran_screen/Position_ecranViewBase.hpp>
#include <gui/position_ecran_screen/Position_ecranPresenter.hpp>

class Position_ecranView : public Position_ecranViewBase
{
public:
    Position_ecranView();
    virtual ~Position_ecranView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // POSITION_ECRANVIEW_HPP
