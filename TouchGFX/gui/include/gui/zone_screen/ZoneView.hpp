#ifndef ZONEVIEW_HPP
#define ZONEVIEW_HPP

#include <gui_generated/zone_screen/ZoneViewBase.hpp>
#include <gui/zone_screen/ZonePresenter.hpp>

class ZoneView : public ZoneViewBase
{
public:
    ZoneView();
    virtual ~ZoneView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // ZONEVIEW_HPP
