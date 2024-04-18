#ifndef BOUCLAGE_ECSVIEW_HPP
#define BOUCLAGE_ECSVIEW_HPP

#include <gui_generated/bouclage_ecs_screen/Bouclage_ecsViewBase.hpp>
#include <gui/bouclage_ecs_screen/Bouclage_ecsPresenter.hpp>

class Bouclage_ecsView : public Bouclage_ecsViewBase
{
public:
    Bouclage_ecsView();
    virtual ~Bouclage_ecsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // BOUCLAGE_ECSVIEW_HPP
